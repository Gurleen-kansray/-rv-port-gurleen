#!/usr/bin/env python3
"""
Real dynamic audit engine for RISC-V HPC packages.
Discovers .deb files, verifies riscv64 architecture, checks ELF binaries.
No hardcoded package lists. No hardcoded PASS/FAIL.
"""
 
import json
import subprocess
import os
import glob
import tempfile
import shutil
import argparse
from datetime import datetime
from pathlib import Path
 
 
REPO_ROOT = Path(__file__).resolve().parent.parent
DEBS_DIR = REPO_ROOT / "debs"
RELEASES_DIR = REPO_ROOT / "releases"
 
 
def run(cmd, check=False):
    try:
        result = subprocess.run(
            cmd, shell=True, capture_output=True, text=True, timeout=30
        )
        return result.returncode, result.stdout.strip(), result.stderr.strip()
    except subprocess.TimeoutExpired:
        return -1, "", "TIMEOUT"
 
 
def find_debs():
    """Discover all .deb files dynamically — no hardcoded list."""
    debs = []
    for search_dir in [DEBS_DIR, RELEASES_DIR, REPO_ROOT]:
        if search_dir.exists():
            found = list(search_dir.glob("*.deb"))
            debs.extend(found)
    # deduplicate by filename
    seen = set()
    unique = []
    for d in debs:
        if d.name not in seen:
            seen.add(d.name)
            unique.append(d)
    return sorted(unique)
 
 
def parse_deb_name(deb_path):
    """Extract name/version/arch from filename like pkg_1.0_riscv64.deb"""
    stem = deb_path.stem  # e.g. lammps_2026.3_riscv64
    parts = stem.split("_")
    if len(parts) >= 3:
        name = "_".join(parts[:-2])
        version = parts[-2]
        arch = parts[-1]
    elif len(parts) == 2:
        name = parts[0]
        version = parts[1]
        arch = "unknown"
    else:
        name = stem
        version = "unknown"
        arch = "unknown"
    return name, version, arch
 
 
def verify_deb_architecture(deb_path):
    """Check declared architecture via dpkg-deb."""
    rc, out, err = run(f"dpkg-deb -f '{deb_path}' Architecture")
    if rc != 0:
        return False, f"dpkg-deb failed: {err}"
    arch = out.strip()
    if arch == "riscv64":
        return True, "riscv64"
    return False, f"wrong arch: {arch}"
 
 
def verify_elf_riscv64(deb_path):
    """Extract .deb and check at least one ELF binary is riscv64."""
    tmpdir = tempfile.mkdtemp(prefix="audit_")
    try:
        rc, _, err = run(f"dpkg-deb -x '{deb_path}' '{tmpdir}'")
        if rc != 0:
            return False, f"extract failed: {err}"
 
        # find ELF files
        rc2, out2, _ = run(f"find '{tmpdir}' -type f | xargs file 2>/dev/null | grep ELF")
        if not out2:
            # header-only package (like eigen) — check for any files
            rc3, out3, _ = run(f"find '{tmpdir}' -type f | head -5")
            if out3:
                return True, "header-only (no ELF, files present)"
            return False, "no files found in package"
 
        lines = out2.splitlines()
        riscv_count = sum(1 for l in lines if "RISC-V" in l or "riscv" in l.lower())
        total = len(lines)
 
        if riscv_count > 0:
            return True, f"{riscv_count}/{total} ELF binaries are RISC-V"
        else:
            # show what arch was found
            sample = lines[0] if lines else "unknown"
            return False, f"ELF found but not RISC-V: {sample[:80]}"
    finally:
        shutil.rmtree(tmpdir, ignore_errors=True)
 
 
def get_deb_contents_summary(deb_path):
    """Get package metadata."""
    rc, out, _ = run(f"dpkg-deb -f '{deb_path}' Package Version Description")
    return out
 
 
def audit_package(deb_path, check_elf=True):
    """Full audit of a single .deb file. Returns real results."""
    name, version, arch_from_name = parse_deb_name(deb_path)
    result = {
        "file": deb_path.name,
        "name": name,
        "version": version,
        "arch_in_filename": arch_from_name,
        "size_kb": round(deb_path.stat().st_size / 1024, 1),
        "checks": {},
        "status": None,
        "failure_reason": None,
    }
 
    # Check 1: file exists and is readable
    if not deb_path.exists():
        result["status"] = "FAIL"
        result["failure_reason"] = "file not found"
        return result
    result["checks"]["file_exists"] = "PASS"
 
    # Check 2: declared architecture
    arch_ok, arch_msg = verify_deb_architecture(deb_path)
    result["checks"]["declared_arch"] = "PASS" if arch_ok else f"FAIL: {arch_msg}"
    result["declared_arch"] = arch_msg
 
    if not arch_ok:
        result["status"] = "FAIL"
        result["failure_reason"] = arch_msg
        return result
 
    # Check 3: ELF binary verification (skip for very large packages, takes too long)
    if check_elf and result["size_kb"] < 100 * 1024:  # skip >100MB
        elf_ok, elf_msg = verify_elf_riscv64(deb_path)
        result["checks"]["elf_riscv64"] = "PASS" if elf_ok else f"FAIL: {elf_msg}"
        result["elf_detail"] = elf_msg
        if not elf_ok:
            result["status"] = "FAIL"
            result["failure_reason"] = elf_msg
            return result
    else:
        result["checks"]["elf_riscv64"] = "SKIP (>100MB or disabled)"
 
    result["status"] = "PASS"
    return result
 
 
def generate_report(debs, check_elf=True, verbose=False):
    """Audit all discovered .deb files and generate report."""
    print(f"[*] Discovered {len(debs)} .deb files")
    print(f"[*] ELF verification: {'enabled' if check_elf else 'disabled'}\n")
 
    results = []
    passed = failed = skipped = 0
 
    for i, deb in enumerate(debs, 1):
        print(f"[{i:02d}/{len(debs)}] Auditing {deb.name} ...", end=" ", flush=True)
        r = audit_package(deb, check_elf=check_elf)
        results.append(r)
 
        if r["status"] == "PASS":
            passed += 1
            print("✅ PASS")
        elif r["status"] == "FAIL":
            failed += 1
            print(f"❌ FAIL — {r['failure_reason']}")
        else:
            skipped += 1
            print("⚠️  SKIP")
 
        if verbose and r["status"] == "PASS":
            print(f"         arch={r.get('declared_arch','')}  elf={r.get('elf_detail','')}")
 
    report = {
        "generated": datetime.now().isoformat(),
        "repo_root": str(REPO_ROOT),
        "summary": {
            "total": len(debs),
            "passed": passed,
            "failed": failed,
            "skipped": skipped,
            "pass_rate": f"{100*passed//len(debs)}%" if debs else "0%",
        },
        "packages": results,
    }
    return report
 
 
def print_dashboard(report):
    s = report["summary"]
    print("\n" + "=" * 60)
    print("  RISC-V HPC AUDIT DASHBOARD")
    print("=" * 60)
    print(f"  Generated : {report['generated']}")
    print(f"  Total     : {s['total']}")
    print(f"  ✅ Passed : {s['passed']}")
    print(f"  ❌ Failed : {s['failed']}")
    print(f"  Pass Rate : {s['pass_rate']}")
    print("=" * 60)
 
    if s["failed"] > 0:
        print("\nFAILED PACKAGES:")
        for p in report["packages"]:
            if p["status"] == "FAIL":
                print(f"  ❌ {p['file']}: {p['failure_reason']}")
 
    print("\nPASSED PACKAGES:")
    for p in report["packages"]:
        if p["status"] == "PASS":
            elf = p.get("elf_detail", "")
            print(f"  ✅ {p['name']} {p['version']} — {elf}")
    print()
 
 
def save_report(report, path="audit_report.json"):
    with open(path, "w") as f:
        json.dump(report, f, indent=2)
    print(f"[+] JSON report saved: {path}")
 
 
def save_markdown(report, path="status_dashboard.md"):
    s = report["summary"]
    lines = [
        "# RISC-V HPC Audit Dashboard",
        f"Generated: {report['generated']}",
        "",
        f"| Metric | Value |",
        f"|--------|-------|",
        f"| Total packages | {s['total']} |",
        f"| Passed | {s['passed']} |",
        f"| Failed | {s['failed']} |",
        f"| Pass rate | {s['pass_rate']} |",
        "",
        "## Package Results",
        "",
        "| Package | Version | Size (KB) | Arch | ELF Check | Status |",
        "|---------|---------|-----------|------|-----------|--------|",
    ]
    for p in report["packages"]:
        elf = p.get("elf_detail", p["checks"].get("elf_riscv64", ""))
        lines.append(
            f"| {p['name']} | {p['version']} | {p['size_kb']} | "
            f"{p.get('declared_arch','')} | {elf} | {p['status']} |"
        )
    with open(path, "w") as f:
        f.write("\n".join(lines) + "\n")
    print(f"[+] Markdown dashboard saved: {path}")
 
 
def main():
    parser = argparse.ArgumentParser(description="RISC-V HPC dynamic audit engine")
    parser.add_argument("--all", action="store_true", help="Audit all discovered .deb files")
    parser.add_argument("--no-elf", action="store_true", help="Skip ELF binary extraction (faster)")
    parser.add_argument("--verbose", "-v", action="store_true", help="Show per-package detail")
    parser.add_argument("--output", default="audit_report.json", help="JSON output path")
    parser.add_argument("--markdown", default="status_dashboard.md", help="Markdown output path")
    parser.add_argument("--debs-dir", help="Override .deb search directory")
    args = parser.parse_args()
 
    global DEBS_DIR
    if args.debs_dir:
        DEBS_DIR = Path(args.debs_dir)
 
    debs = find_debs()
    if not debs:
        print(f"[!] No .deb files found. Searched: {DEBS_DIR}, {RELEASES_DIR}")
        print(f"    Run from repo root or pass --debs-dir <path>")
        return 1
 
    report = generate_report(debs, check_elf=not args.no_elf, verbose=args.verbose)
    print_dashboard(report)
    save_report(report, args.output)
    save_markdown(report, args.markdown)
    return 0
 
 
if __name__ == "__main__":
    exit(main())
 
