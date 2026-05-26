# OpenMM 8.5.0 - Molecular Dynamics with AI/ML

**Status:** ✅ BUILT & PACKAGED
**Category:** AI/ML / Molecular Dynamics

## Build Commands
```bash
git clone --depth 1 https://github.com/openmm/openmm.git
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=riscv64-toolchain.cmake \
    -DOPENMM_BUILD_CUDA_LIB=OFF \
    -DOPENMM_BUILD_OPENCL_LIB=OFF \
    -DOPENMM_BUILD_PYTHON_WRAPPERS=OFF
make -j4 && make install
Libraries Built
libOpenMM.so

libOpenMMAmoeba.so

libOpenMMCPU.so

libOpenMMDrude.so

libOpenMMPME.so

libOpenMMRPMD.so

Impact
RVV auto-vectorized molecular dynamics for drug discovery, materials science.
