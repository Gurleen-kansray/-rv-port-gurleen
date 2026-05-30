#!/bin/bash
WORKSPACE=/mnt/d/rv-workspace
DEBS=/mnt/d/rv-port-gurleen/debs
TMP=/tmp/rvv-verify
mkdir -p $TMP

ARITH='/vle8|vle16|vle32|vle64|vse8|vse16|vse32|vse64|vfmacc|vfmul|vfadd|vfnmacc|vfsub|vfmadd|vfmv|vfslide|vfmsub|vfmsac/'

check_rvv() {
  local name=$1
  local lib=$2
  result=$(riscv64-linux-gnu-objdump -d "$lib" 2>/dev/null | \
    awk '/vsetvli|vsetivli/{s++} /vle8|vle16|vle32|vle64|vse8|vse16|vse32|vse64|vfmacc|vfmul|vfadd|vfnmacc|vfsub|vfmadd|vfmv|vfslide|vfmsub|vfmsac/{a++} END{print s+0, a+0, int(a*100/(s+1))"%"}')
  setup=$(echo $result | awk '{print $1}')
  arith=$(echo $result | awk '{print $2}')
  ratio=$(echo $result | awk '{print $3}')
  if [ "$setup" -gt 0 ] 2>/dev/null; then
    printf "%-12s | %7s | %7s | %6s | ✅ RVV\n" "$name" "$setup" "$arith" "$ratio"
  else
    printf "%-12s | %7s | %7s | %6s | ⚠️  no RVV\n" "$name" "0" "0" "N/A"
  fi
}

check_rvv_dir() {
  local name=$1
  local dir=$2
  result=$(find "$dir" -name "*.so" -o -name "*.so.*" -o -name "*.a" 2>/dev/null | \
    xargs riscv64-linux-gnu-objdump -d 2>/dev/null | \
    awk '/vsetvli|vsetivli/{s++} /vle8|vle16|vle32|vle64|vse8|vse16|vse32|vse64|vfmacc|vfmul|vfadd|vfnmacc|vfsub|vfmadd|vfmv|vfslide|vfmsub|vfmsac/{a++} END{print s+0, a+0, int(a*100/(s+1))"%"}')
  setup=$(echo $result | awk '{print $1}')
  arith=$(echo $result | awk '{print $2}')
  ratio=$(echo $result | awk '{print $3}')
  if [ "$setup" -gt 0 ] 2>/dev/null; then
    printf "%-12s | %7s | %7s | %6s | ✅ RVV\n" "$name" "$setup" "$arith" "$ratio"
  else
    printf "%-12s | %7s | %7s | %6s | ⚠️  no RVV\n" "$name" "0" "0" "N/A"
  fi
}

mkdir -p $TMP/arpack $TMP/lammps
dpkg-deb -x $DEBS/arpack-ng-rvv_3.9.1_riscv64.deb $TMP/arpack 2>/dev/null
dpkg-deb -x $DEBS/lammps-rvv_2026.3_riscv64.deb $TMP/lammps 2>/dev/null

echo "Package      | vsetvli | Arith   | Ratio  | Status"
echo "-------------|---------|---------|--------|-------"
check_rvv     "LAMMPS"    "$TMP/lammps/usr/local/bin/lmp"
check_rvv     "OpenBLAS"  "$WORKSPACE/OpenBLAS-RVV/libopenblas.so"
check_rvv     "ARPACK-ng" "$TMP/arpack/usr/lib/riscv64-linux-gnu/libarpack.a"
check_rvv     "FFTW"      "$WORKSPACE/fftw-rvv-install/lib/libfftw3.so.3"
check_rvv     "GSL"       "$WORKSPACE/gsl-rvv-install/lib/libgsl.so"
check_rvv     "GROMACS"   "$WORKSPACE/gromacs-rvv-install/lib/libgromacs.so"
check_rvv     "HDF5"      "$WORKSPACE/hdf5-rvv-install/lib/libhdf5.so"
check_rvv     "SuperLU"   "$WORKSPACE/superlu-rvv-install/lib/libsuperlu.a"
check_rvv     "PETSc"     "$WORKSPACE/petsc-rvv-install/lib/libpetsc.so"
check_rvv_dir "SUNDIALS"  "$WORKSPACE/sundials-rvv-install/lib"
