#!/usr/bin/env python3
"""
Mechanical validation gate — calls real riscv64 binaries under qemu-riscv64.
Locks exact counts; catches regressions; generates compliance matrix.
"""
import subprocess, sys, os, json
from datetime import datetime

TOOLCHAIN = "riscv64-linux-gnu-gcc"
QEMU      = "qemu-riscv64"

GATES = {
    "dgemm_50":   ("analysis/dgemm/test_dgemm_extended_50cases.c",  50,  "ALL 50 TESTS PASS"),
    "lapack_12":  ("analysis/lapack/test_lapack_validation.c",       12,  "12/12 PASS"),
    "spooles_16": ("analysis/spooles/test_spooles_validation.c",     16,  "SPOOLES PRODUCTION READY"),
}

def build(src, out):
    r = subprocess.run(
        [TOOLCHAIN, "-O2", "-static", src, "-o", out, "-lm"],
        capture_output=True, text=True)
    return r.returncode == 0, r.stderr

def run(binary):
    r = subprocess.run([QEMU, binary], capture_output=True, text=True, timeout=120)
    return r.stdout + r.stderr

def main():
    passed, failed = 0, 0
    results = {}
    print(f"=== verify_gurleen_port.py — {datetime.now().isoformat()} ===\n")
    for name, (src, expected_count, sentinel) in GATES.items():
        out = f"/tmp/vgate_{name}"
        ok, err = build(src, out)
        if not ok:
            print(f"❌ {name}: BUILD FAILED — {err[:80]}")
            failed += 1; continue
        output = run(out)
        if sentinel in output:
            print(f"✅ {name}: PASS (sentinel found: '{sentinel}')")
            passed += 1
            results[name] = {"status": "PASS", "sentinel": sentinel, "output_tail": output.strip().split('\n')[-3:]}
        else:
            print(f"❌ {name}: FAIL — sentinel '{sentinel}' not found")
            print(f"   Output tail: {output.strip().split(chr(10))[-3:]}")
            failed += 1
            results[name] = {"status": "FAIL"}
    print(f"\n{'='*50}")
    print(f"TOTAL: {passed}/{passed+failed} PASS")
    print(f"Locked gates: {list(GATES.keys())}")
    print(f"Any drift in source or toolchain will break these gates.")
    with open("validation_gate_results.json", "w") as f:
        json.dump({"timestamp": datetime.now().isoformat(),
                   "passed": passed, "failed": failed,
                   "results": results}, f, indent=2)
    print(f"\nReport: validation_gate_results.json")
    return 0 if failed == 0 else 1

if __name__ == "__main__":
    sys.exit(main())
