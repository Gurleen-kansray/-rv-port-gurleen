# ARPACK-ng 3.9.1 — riscv64 Port Notes

**Category:** Iterative eigenvalue solver | **Status:** built and validated
**Depends on:** OpenBLAS (build first)

## Build

```bash
git clone --depth 1 --branch 3.9.1 https://github.com/opencollab/arpack-ng.git
cd arpack-ng && mkdir build-riscv && cd build-riscv
cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=../../toolchain/riscv64-linux-gnu.cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DBLAS_LIBRARIES=$HOME/rv-port-gurleen/openblas/build-riscv/lib/libopenblas.a \
  -DLAPACK_LIBRARIES=$HOME/rv-port-gurleen/openblas/build-riscv/lib/libopenblas.a \
  -DBUILD_SHARED_LIBS=OFF
make -j$(nproc)
```

## Key Pitfall
Uses CMake — do not set `CMAKE_SYSROOT`. See Blocker 2 in toolchain-pitfalls.md.
