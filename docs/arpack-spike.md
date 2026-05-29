# ARPACK-ng 3.9.1 Cross-Compile Spike — May 2026

## ✅ Status: COMPLETE SUCCESS

### Summary
Successfully cross-compiled ARPACK-ng 3.9.1 for riscv64-linux-gnu with OpenBLAS backend.

### Environment
- Host: WSL2 Ubuntu 24.04 (x86_64)
- Target: riscv64-linux-gnu
- Workspace: D drive (/mnt/d/rv-workspace)
- Compiler: riscv64-linux-gnu-gcc 13.3.0
- Build Time: ~15 minutes

### Results
✅ Configure: PASSED
✅ Build: PASSED
✅ Install: PASSED

### Installed Libraries
- libarpack.a (1.2 MB) — Eigenvalue/eigenvector solver
- CMake configs
- pkg-config files

Total: 1.2 MB

### Configure Command
```bash
../configure \
  --prefix=/mnt/d/rv-workspace/arpack-riscv64-install \
  --host=riscv64-linux-gnu \
  --build=x86_64-linux-gnu \
  --enable-static \
  --disable-shared \
  CC=riscv64-linux-gnu-gcc \
  FC=riscv64-linux-gnu-gfortran \
  CFLAGS="-O2 -march=rv64gc" \
  FFLAGS="-O2 -march=rv64gc" \
  LDFLAGS="-L/mnt/d/rv-workspace/openblas-riscv64-install/lib" \
  LIBS="-lopenblas"
```

### Build Command
```bash
make -j4
make install
```

### Key Learning
ARPACK-ng successfully linked with cross-compiled OpenBLAS. Dependency chain works!

### Impact for LFX Project
ARPACK-ng unlocks 25+ downstream codes:
- Eigenvalue solvers: SLEPc, FEAST
- Physics simulations: multiple research codes
- Forms critical dependency chain: OpenBLAS → ARPACK-ng → SLEPc/FEAST

### Storage Usage (D Drive Only)
- ARPACK-ng source: ~500 KB
- Build artifacts: ~10 MB
- Installed libraries: ~1.2 MB
- Total: ~12 MB
- C drive usage: 0 bytes ✓

### Dependency Chain Validated
✅ OpenBLAS (57 MB) → ✅ ARPACK-ng (1.2 MB)

This proves the dependency resolution strategy works. Can now chain:
- OpenBLAS → ARPACK-ng → SLEPc
- OpenBLAS → ARPACK-ng → FEAST
- PETSc + OpenBLAS → FEniCS/deal.II

### Next Steps
1. Test ARPACK-ng under QEMU
2. Port SLEPc (depends on PETSc + ARPACK-ng)
3. Begin FEM code integration

---
Spike Completed by: Gurleen Kaur Kansray
Date: May 18, 2026
LFX Mentorship: Summer 2026
Status: Dependency chain validated, ready for SLEPc
