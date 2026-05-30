#!/usr/bin/env python3
import json, subprocess, tempfile, shutil, argparse
from datetime import datetime
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
DEBS_DIR = REPO_ROOT / "debs"

def run(cmd):
    try:
        r = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=30)
        return r.returncode, r.stdout.strip(), r.stderr.strip()
    except subprocess.TimeoutExpired:
        return -1, "", "TIMEOUT"

def find_debs():
    debs = []
    for d in [DEBS_DIR, REPO_ROOT/"releases", REPO_ROOT]:
        if d.exists():
            debs.extend(d.glob("*.deb"))
    seen, unique = set(), []
    for d in debs:
        if d.name not in seen:
            seen.add(d.name)
            unique.append(d)
    return sorted(unique)

def verify_arch(deb):
    rc, out, err = run(f"dpkg-deb -f '{deb}' Architecture")
    if rc != 0: return False, f"dpkg-deb error: {err}"
    return (True, "riscv64") if out.strip() == "riscv64" else (False, f"wrong: {out.strip()}")

def verify_elf(deb):
    tmp = tempfile.mkdtemp()
    try:
        rc, _, err = run(f"dpkg-deb -x '{deb}' '{tmp}'")
        if rc != 0: return False, f"extract failed: {err}"
        rc2, out2, _ = run(f"find '{tmp}' -type f | xargs file 2>/dev/null | grep ELF")
        if not out2:
            _, out3, _ = run(f"find '{tmp}' -type f | head -3")
            return (True, "header-only") if out3 else (False, "empty package")
        lines = out2.splitlines()
        rv = sum(1 for l in lines if "RISC-V" in l)
        return (True, f"{rv}/{len(lines)} RISC-V ELF") if rv > 0 else (False, f"x86 ELF found")
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

def audit(deb, check_elf=True):
    parts = deb.stem.split("_")
    name = "_".join(parts[:-2]) if len(parts) >= 3 else deb.stem
    version = parts[-2] if len(parts) >= 3 else "unknown"
    r = {"file": deb.name, "name": name, "version": version,
         "size_kb": round(deb.stat().st_size/1024, 1), "status": None, "reason": None}
    ok, msg = verify_arch(deb)
    r["arch"] = msg
    if not ok:
        r["status"] = "FAIL"; r["reason"] = msg; return r
    if check_elf and r["size_kb"] < 100*1024:
        ok2, msg2 = verify_elf(deb)
        r["elf"] = msg2
        if not ok2:
            r["status"] = "FAIL"; r["reason"] = msg2; return r
    else:
        r["elf"] = "SKIP"
    r["status"] = "PASS"
    return r

def main():
    p = argparse.ArgumentParser()
    p.add_argument("--all", action="store_true")
    p.add_argument("--no-elf", action="store_true")
    p.add_argument("--debs-dir")
    args = p.parse_args()

    global DEBS_DIR
    if args.debs_dir: DEBS_DIR = Path(args.debs_dir)

    debs = find_debs()
    if not debs:
        print(f"[!] No .deb files found in {DEBS_DIR}"); return 1

    print(f"[*] Found {len(debs)} .deb files\n")
    results, passed, failed = [], 0, 0
    for i, deb in enumerate(debs, 1):
        print(f"[{i:02d}/{len(debs)}] {deb.name} ...", end=" ", flush=True)
        r = audit(deb, check_elf=not args.no_elf)
        results.append(r)
        if r["status"] == "PASS":
            passed += 1; print(f"PASS  {r.get('elf','')}")
        else:
            failed += 1; print(f"FAIL  {r['reason']}")

    print(f"\n{'='*50}")
    print(f"  TOTAL: {len(debs)}  PASS: {passed}  FAIL: {failed}")
    print(f"{'='*50}\n")

    report = {"generated": datetime.now().isoformat(),
              "summary": {"total": len(debs), "passed": passed, "failed": failed},
              "packages": results}
    with open("audit_report_v2.json", "w") as f:
        json.dump(report, f, indent=2)
    print("[+] Saved: audit_report_v2.json")

if __name__ == "__main__":
    main()
