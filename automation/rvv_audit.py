#!/usr/bin/env python3
"""RVV opcode audit — scans ALL binaries inside each deb"""
import subprocess, tempfile, shutil, json
from pathlib import Path

DEBS_DIR = Path("/mnt/d/rv-port-gurleen/debs")
OUT = Path("/mnt/d/rv-port-gurleen/rvv_audit_results.json")

ARITH_OPS = ["vle8","vle16","vle32","vle64","vse8","vse16","vse32","vse64",
             "vfmacc","vfmadd","vfmsub","vfmul","vfadd","vfsub","vfmv",
             "vmul","vadd","vsub","vand","vor","vxor","vslide"]

def is_elf(f):
    try:
        with open(f,"rb") as fh:
            return fh.read(4) == b'\x7fELF'
    except: return False

def count_rvv(binary):
    try:
        r = subprocess.run(["riscv64-linux-gnu-objdump","-d",str(binary)],
                          capture_output=True, text=True, timeout=180)
        lines = r.stdout.splitlines()
        setup = sum(1 for l in lines if "vsetvli" in l or "vsetivli" in l)
        arith = sum(1 for l in lines if any(op in l for op in ARITH_OPS))
        return setup, arith
    except: return 0, 0

results = {}
for deb in sorted(DEBS_DIR.glob("*.deb")):
    tmp = tempfile.mkdtemp()
    try:
        subprocess.run(["dpkg-deb","-x",str(deb),tmp], capture_output=True)
        elfs = [f for f in Path(tmp).rglob("*") if f.is_file() and is_elf(f)]
        if not elfs:
            name = deb.stem.rsplit("_",2)[0]
            results[name] = {"setup":0,"arith":0,"ratio_pct":0,"rvv":False,"note":"no-elf"}
            print(f"⚪ {name:35s} header-only")
            continue
        # sum across ALL elf files in the deb
        total_setup = total_arith = 0
        for elf in elfs:
            s, a = count_rvv(elf)
            total_setup += s; total_arith += a
        ratio = round(total_arith/total_setup*100) if total_setup > 0 else 0
        name = deb.stem.rsplit("_",2)[0]
        results[name] = {"setup":total_setup,"arith":total_arith,
                        "ratio_pct":ratio,"rvv":total_setup>0,"elf_count":len(elfs)}
        status = "✅" if total_setup > 0 else "⚠️ scalar"
        print(f"{status} {name:35s} vsetvli={total_setup:6d} arith={total_arith:6d} ratio={ratio}% [{len(elfs)} ELF]")
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

with open(OUT,"w") as f:
    json.dump(results, f, indent=2)
print(f"\n✅ Saved: {OUT}")
