# rv-port-gurleen

RISC-V cross-compilation PoC — LFX Summer 2026 mentorship:
**"Broadening the RISC-V High Precision Code Base and Reach"**

## Results

| Code | Version | Status | Notes |
|------|---------|--------|-------|
| GetDP | 4.0.0-git-f060307e | ✅ Full build + solver run | 8 iterations, residual 8.2729e-13 |
| SIMD shim | — | ✅ Working | SSE2 on x86, scalar on riscv64, identical output |

## What this proves

- riscv64 cross-compilation toolchain working on WSL2/Windows
- CMake-based HPC code builds cleanly for riscv64
- GMRES solver converges correctly on RISC-V — not just a binary that
  starts, but one that solves a real magnetostatics FEM problem to
  8.2729e-13 residual with full post-processing output
- Portable SIMD abstraction layer compiles same source for both architectures

## Setup (Ubuntu 24.04 / WSL2)

```bash
sudo apt install gcc-riscv64-linux-gnu g++-riscv64-linux-gnu \
  gfortran-riscv64-linux-gnu qemu-user-static binfmt-support \
  cmake make build-essential

export QEMU_LD_PREFIX=/usr/riscv64-linux-gnu
```

## Repo structure
riscv64-toolchain.cmake   CMake toolchain file for riscv64 cross-compilation
scripts/build-riscv.sh    Wrapper to cross-compile any CMake project
hal/                      Portable SIMD shim (SSE2/riscv64/scalar)
getdp/                    GetDP source + build-riscv/
build_log.md              Detailed notes from actual runs
