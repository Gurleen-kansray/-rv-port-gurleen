# GetDP 4.0.0 — riscv64 Port Notes

**Category:** PDE solver (electromagnetics) | **Status:** built and validated

## Build

```bash
git clone https://gitlab.onelab.info/getdp/getdp.git
cd getdp && mkdir build-riscv && cd build-riscv
cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=../../toolchain/riscv64-linux-gnu.cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DENABLE_BUILD_SHARED=OFF
make -j$(nproc)
```

## Key Pitfall
Do not set `CMAKE_SYSROOT`. See Blocker 2 in toolchain-pitfalls.md.

## Verification

```bash
file getdp
qemu-riscv64-static ./getdp --version
```
