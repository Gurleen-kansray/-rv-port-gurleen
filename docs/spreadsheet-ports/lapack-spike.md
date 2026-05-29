# LAPACK – RISC-V Port

**Status:** ✅ COMPLETE (May 19, 2026)

**Build Method:** CMake with riscv64-linux-gnu toolchain

**Build Commands:**
```bash
git clone https://github.com/Reference-LAPACK/lapack.git
cd lapack
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/mnt/d/rv-workspace/-rv-port-gurleen/toolchain/riscv64-linux-gnu.cmake -DBUILD_TESTING=OFF -DLAPACKE=OFF
make -j4
