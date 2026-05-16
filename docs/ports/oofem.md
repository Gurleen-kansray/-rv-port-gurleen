# OOFEM 2.6 — riscv64 Port Notes

**Category:** Object-oriented FEM solver | **Status:** built and validated

## Build

```bash
git clone --depth 1 --branch v2.6 https://github.com/oofem/oofem.git
cd oofem
sed -i '/add_subdirectory(tests)/d' CMakeLists.txt
mkdir build-riscv && cd build-riscv
cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=../../toolchain/riscv64-linux-gnu.cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DUSE_SHARED_LIB=OFF
make -j$(nproc)
```

## Key Pitfalls
1. Remove Catch2 test subdir before cmake. See Blocker 4 in toolchain-pitfalls.md.
2. Do not set `CMAKE_SYSROOT`. See Blocker 2.

## Verification

```bash
qemu-riscv64-static ./oofem --version
```
