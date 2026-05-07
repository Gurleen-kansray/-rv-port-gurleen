# Build Log

## GetDP 4.0.0-git-f060307e — riscv64

**Date:** 2026-05-07
**Host:** Ubuntu 24.04 / WSL2 on Windows
**Toolchain:** riscv64-linux-gnu-gcc 13.3.0, qemu-riscv64-static 8.2.2

**CMake flags:**
- DEFAULT=0, ENABLE_FORTRAN=1, ENABLE_SPARSKIT=1
- ENABLE_PETSC=0, ENABLE_BLAS_LAPACK=0

**Result:** Full build, 100% of translation units compiled, zero errors.
Only harmless upstream warnings (sign-compare, Fortran 2018 style in SparsKit).

**Binary confirmed running on qemu-riscv64-static:**
**Magnetostatics example (magnet.pro, Magnetostatics_phi resolution):**
- Problem size: 1554 DOFs
- Solver: GMRES with ILUTP preconditioner (fill-in=20), RCMK reordering
- Result: **8 iterations, residual 8.2729e-13**
- Post-processing: hc.pos, phi.pos, h.pos, b.pos written successfully

## SIMD shim — hal/

**Result:** Same source compiles for x86 (SSE2) and riscv64 (scalar fallback).
Both produce dot(a,b) = 70.0. Zero warnings after fix.
RVV intrinsic backend planned for summer.

## SPOOLES 2.2 — riscv64 ✅

**Date:** 2025-05-07  
**Source:** http://www.netlib.org/linalg/spooles/spooles.2.2.tgz  
**Build command:**
make CC=riscv64-linux-gnu-gcc AR=riscv64-linux-gnu-ar 
RANLIB=riscv64-linux-gnu-ranlib CFLAGS="-O2 -fcommon" lib
**Result:** spooles.a — 5.1MB, 291 object files  
**Fix required:** `-fcommon` flag for tentative definition conflicts (standard for old C codebases on GCC 10+)  
**Warnings:** format string `%d` vs `size_t` in MM.h — harmless, build succeeds  
**Validation:**
qemu-riscv64-static -L /usr/riscv64-linux-gnu ./test_spooles_riscv
SPOOLES riscv64 link test PASSED
