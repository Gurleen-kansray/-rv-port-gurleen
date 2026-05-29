# Complete RISC-V HPC Porting Guide

## Quick Start Checklist
- [ ] Download source
- [ ] Check build system
- [ ] Apply toolchain
- [ ] Configure & build
- [ ] Verify binary
- [ ] Test with QEMU
- [ ] Validate output
- [ ] Package as .deb

## Build Systems

**CMake:** `cmake -DCMAKE_TOOLCHAIN_FILE=riscv64-linux-gnu.cmake ..`

**Autotools:** `./configure --host=riscv64-linux-gnu CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran`

**Makefile:** Add `-march=rv64g -mabi=lp64d` to CFLAGS

## Common Blockers

| Issue | Fix |
|-------|-----|
| Missing BLAS | `-DBLAS_LIBRARIES=/path/to/libopenblas.a` |
| Fortran loop vars | `-Wno-do-subscript` |
| x86 intrinsics | Use `hal/simd.h` wrapper |
| CMake try_run | `CMAKE_CROSSCOMPILING_EMULATOR=qemu-riscv64-static` |

## Validation
```bash
qemu-riscv64-static -L /usr/riscv64-linux-gnu ./binary
```

Compare numerical output with x86 baseline (tolerance: 1e-13)
