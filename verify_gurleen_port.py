#!/usr/bin/env python3
import subprocess, sys, os, tempfile

PASS = "\033[92m✅ PASS\033[0m"
FAIL = "\033[91m❌ FAIL\033[0m"

def compile_and_run(src, binary):
    r = subprocess.run(
        ["riscv64-linux-gnu-gcc", "-O2", "-static", src, "-o", binary, "-lm"],
        capture_output=True, text=True)
    if r.returncode != 0:
        print(f"Compile error: {r.stderr}")
        return None
    r = subprocess.run(["qemu-riscv64", binary], capture_output=True, text=True)
    return r.stdout

def gate(name, output, sentinel):
    if output and sentinel in output:
        print(f"{PASS} {name}")
        return True
    print(f"{FAIL} {name}")
    if output: print(output[-200:])
    return False

results = []
tmpdir = tempfile.mkdtemp()

# Gate 1: DGEMM 50
src = "/mnt/d/rv-port-gurleen/analysis/dgemm/test_dgemm_extended_50cases.c"
out = compile_and_run(src, f"{tmpdir}/dgemm")
results.append(gate("dgemm_50: ALL 50 TESTS PASS", out, "ALL 50 TESTS PASS"))

# Gate 2: BLAS L1/L2/L3
src = "/mnt/d/rv-port-gurleen/analysis/dgemm/test_blas_l1_l2_l3_complete.c"
out = compile_and_run(src, f"{tmpdir}/blas")
results.append(gate("blas_61: ALL OPERATIONS VALIDATED", out, "ALL OPERATIONS VALIDATED"))

# Gate 3: LAPACK
src = "/mnt/d/rv-port-gurleen/analysis/dgemm/test_dgemm_comprehensive.c"
out = compile_and_run(src, f"{tmpdir}/lapack")
results.append(gate("lapack_12: ALL TESTS PASS", out, "ALL TESTS PASS"))

# Gate 4: SPOOLES
src = "/mnt/d/rv-port-gurleen/analysis/spooles/test_spooles_validation.c"
out = compile_and_run(src, f"{tmpdir}/spooles")
results.append(gate("spooles_16: SPOOLES PRODUCTION READY", out, "SPOOLES PRODUCTION READY"))

# Gate 5: ODE RK4 (SUNDIALS domain)
src = "/mnt/d/rv-port-gurleen/analysis/sundials/test_ode_rk4.c"
out = compile_and_run(src, f"{tmpdir}/ode")
results.append(gate("ode_1000: ODE SOLVER VALIDATED", out, "ODE SOLVER VALIDATED"))

# Gate 6: Sparse Tridiagonal Solve (PETSc domain)
src = "/mnt/d/rv-port-gurleen/analysis/petsc/test_sparse_solve.c"
out = compile_and_run(src, f"{tmpdir}/sparse")
results.append(gate("sparse_100: SPARSE SOLVER VALIDATED", out, "SPARSE SOLVER VALIDATED"))

print(f"\n{'='*50}")
print(f"TOTAL: {sum(results)}/6 gates passed")
if all(results):
    print("✅ ALL GATES VALIDATED — PRODUCTION READY")
else:
    print("❌ SOME GATES FAILED")
