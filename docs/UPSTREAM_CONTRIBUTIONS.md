# Upstream Contributions

This document tracks patches contributed back to upstream HPC projects
to improve RISC-V support ecosystem-wide.

## Submitted PRs

### 1. SPOOLES: GCC 10+ `-fcommon` support
- **Status**: Ready to submit
- **Impact**: Fixes build on modern GCC (10+) with tentative definitions
- **Blocker solved**: `SPOOLES` linker errors on systems with GCC 10+
- **PR target**: https://github.com/dsimba/SparseLib

### 2. OpenBLAS: riscv64 cross-compile target detection
- **Status**: Ready to submit
- **Impact**: Enables TARGET=RISCV64_GENERIC auto-detection
- **Blocker solved**: Manual target specification requirement
- **PR target**: https://github.com/OpenMathLib/OpenBLAS

### 3. ARPACK-ng: CMake toolchain compatibility
- **Status**: Ready to submit
- **Impact**: Fixes CMake cross-compilation with riscv64 target
- **Blocker solved**: CMAKE_SYSROOT multiarch conflicts
- **PR target**: https://github.com/opencollab/arpack-ng

## Contribution Philosophy

Each patch:
1. Solves a real blocker from RISC-V HPC porting
2. Benefits ALL cross-compilation users (not just riscv64)
3. Minimal, focused change
4. Tested on multiple architectures

This elevates RISC-V HPC support from "special case" to "first-class."

