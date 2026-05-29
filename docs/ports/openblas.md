# OpenBLAS 0.3.33 — riscv64 Port Notes

**Category:** Optimized BLAS/LAPACK | **Status:** built and validated
**Downstream:** ARPACK-ng, CalculiX, ~80 eigenvalue codes

## Build

```bash
git clone --depth 1 --branch v0.3.33 https://github.com/OpenMathLib/OpenBLAS.git
cd OpenBLAS
make CROSS=1 TARGET=RISCV64_GENERIC NO_SHARED=1 \
     CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran -j$(nproc)
make PREFIX=$(pwd)/build-riscv install \
     CROSS=1 TARGET=RISCV64_GENERIC NO_SHARED=1 \
     CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran
```

## Key Pitfall
Always pass `TARGET=RISCV64_GENERIC` — never rely on auto-detection.
See Blocker 5 in toolchain-pitfalls.md.

## Verification

```bash
file build-riscv/lib/libopenblas.a
# Expected: ELF 64-bit LSB relocatable, UCB RISC-V
```
