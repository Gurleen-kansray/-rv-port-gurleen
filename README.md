# RISC-V HPC Portability — PoC

Cross-compilation pipeline for riscv64 HPC codes.  
LFX Mentorship 2026 — Broadening the RISC-V High Precision Code Base and Reach  
**Gurleen Kaur Kansray** | gurleen72542@gmail.com

---

## Validated Ports

| Package | Version | Test Problem | Result |
|---|---|---|---|
| GetDP | 4.0.0 | Magnetostatics, 1554 DOFs, GMRES+ILUTP | residual 8.2729e-13 ✅ |
| OOFEM | 2.6 | Structural mechanics, Newton-Raphson | converged 1.312e-16 ✅ |
| SPOOLES | 2.2 | Sparse direct solver, 291 object files | PASSED ✅ |
| ARPACK-ng | 3.9.1 | All 17 drivers (dsbdr/dndrv/dsdrv) | worst residual 1.40e-13 ✅ |
| CalculiX | 2.21 | FEM solver, achtel2 test problem | Job finished 0.405768s ✅ |
| OpenBLAS | 0.3.33 | TARGET=RISCV64_GENERIC | built, ~80 codes unblocked ✅ |

All binaries validated under `qemu-riscv64-static`.  
All packaged as installable `.deb` files with `Architecture: riscv64`.

---

## Dependency Chain

- OpenBLAS 0.3.33 ✅
  - ARPACK-ng 3.9.1 ✅
- SPOOLES 2.2 ✅
  - CalculiX 2.21 ✅ — both blockers resolved

---

## Repository Layout

- toolchain/riscv64-linux-gnu.cmake — cross-compilation toolchain file
- hal/simd.h — portable SIMD shim (SSE2 + scalar fallback + RVV planned)
- spooles/spooles.a — SPOOLES 2.2 riscv64 static library
- debs/
  - getdp_4.0.0_riscv64.deb
  - oofem_2.6_riscv64.deb
  - spooles_2.2_riscv64.deb
  - arpack-ng_3.9.1_riscv64.deb
  - calculix-ccx_2.21_riscv64.deb
  - libopenblas_0.3.33_riscv64.deb

---

## Toolchain

- CC: riscv64-linux-gnu-gcc 13.3.0
- FC: riscv64-linux-gnu-gfortran 13.3.0
- Emulator: qemu-riscv64-static

```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=toolchain/riscv64-linux-gnu.cmake
qemu-riscv64-static -L /usr/riscv64-linux-gnu ./binary
```

---

## Known Issues and Fixes

| Code | Issue | Fix |
|---|---|---|
| SPOOLES 2.2 | GCC 10+ tentative definition handling | -fcommon flag |
| CalculiX 2.21 | SPOOLES header path | -I pointing to full SPOOLES source |
| ARPACK-ng | riscv64 not on archive.ubuntu.com | cross-compile from source |
| OpenBLAS | -march=native breaks cross-compile | TARGET=RISCV64_GENERIC |

---

## HAL SIMD Shim

hal/simd.h provides architecture-transparent SIMD — zero #ifdefs in application code.

| Architecture | Backend |
|---|---|
| x86_64 | SSE2 intrinsics |
| riscv64 | Scalar fallback (RVV backend planned Weeks 6-8) |
