# CalculiX 2.21 — riscv64 Port Notes

**Category:** Full FEM solver — industry standard | **Status:** built and validated
**Build order:** OpenBLAS → SPOOLES → ARPACK-ng → CalculiX

## Build

```bash
wget http://www.dhondt.de/ccx_2.21.src.tar.bz2
tar xf ccx_2.21.src.tar.bz2
cd CalculiX/ccx_2.21/src/
# Edit Makefile: set CC, FC, and replace LIBS as below
make -j$(nproc)
```

Makefile changes:

```makefile
CC = riscv64-linux-gnu-gcc
FC = riscv64-linux-gnu-gfortran
LIBS = -L/usr/riscv64-linux-gnu/lib \
       -L$(HOME)/rv-port-gurleen/spooles/build-riscv \
       -L$(HOME)/rv-port-gurleen/arpack-ng/build-riscv \
       -lspooles -larpack -lopenblas -lgfortran -lm -lpthread
```

## Key Pitfalls
1. Explicit `-L` paths required. See Blocker 6 in toolchain-pitfalls.md.
2. SPOOLES needs `-fcommon`. See Blocker 1.

## Verification

```bash
file ccx_2.21
qemu-riscv64-static ./ccx_2.21 achtel2
```
