import os

def w(path, content):
    os.makedirs(os.path.dirname(path), exist_ok=True) if os.path.dirname(path) else None
    open(path, "w").write(content)
    print("created:", path)

w("docs/toolchain-pitfalls.md", """\
# Toolchain Pitfalls & Fixes — riscv64 Cross-Compilation

This document records every blocker encountered while porting 6 HPC codes to riscv64,
with the root cause and permanent fix for each.

---

## Blocker 1 — SPOOLES: Tentative Definition Failure (GCC 10+)

**Code:** SPOOLES 2.2

**Symptom:**

```
/usr/bin/riscv64-linux-gnu-ld: MT/src/misc.o:(.bss+0x0): multiple definition of 'slock'
/usr/bin/riscv64-linux-gnu-ld: ETree/src/basics.o:(.bss+0x0): first defined here
```

**Root Cause:**
GCC 10+ changed default from `-fcommon` to `-fno-common`. SPOOLES declares global variables
in headers without `extern`, creating tentative definitions in multiple translation units.
Pre-GCC 10 merged them silently; GCC 10+ treats them as hard errors.

**Fix:**

```makefile
# Make.inc
CFLAGS = -O2 -fcommon
```

**Why It Matters:**
SPOOLES is a dependency for CalculiX and ~30 FEM codes. This single flag unblocks the entire FEM domain.

**Verification:**

```bash
riscv64-linux-gnu-gcc -fcommon -c -o test.o MT/src/misc.c
ar rcs libspooles.a *.o
```

---

## Blocker 2 — CMake Toolchain: CMAKE_SYSROOT vs Multiarch

**Code:** GetDP 4.0.0, OOFEM 2.6

**Symptom:**

```
CMake Error: The C compiler is not able to compile a simple test program.
ld: cannot find -lc
```

**Root Cause:**
Standard CMake guides say to set `CMAKE_SYSROOT=/usr/riscv64-linux-gnu`. This overrides
the cross-compiler's built-in sysroot. Ubuntu multiarch puts libc in
`/usr/riscv64-linux-gnu/lib/` but the override points to an empty directory.

**Wrong approach:**

```cmake
set(CMAKE_SYSROOT /usr/riscv64-linux-gnu)
set(CMAKE_FIND_ROOT_PATH /usr/riscv64-linux-gnu)
```

**Correct Fix:**

```cmake
# toolchain/riscv64-linux-gnu.cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR riscv64)
set(CMAKE_C_COMPILER riscv64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER riscv64-linux-gnu-g++)
set(CMAKE_Fortran_COMPILER riscv64-linux-gnu-gfortran)
# DO NOT SET CMAKE_SYSROOT — gcc-13 has the correct built-in sysroot
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
```

**Verification:**

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=toolchain/riscv64-linux-gnu.cmake ..
```

---

## Blocker 3 — Wrong apt Mirror for riscv64 Packages

**Code:** All ports requiring BLAS/LAPACK

**Symptom:**

```
E: Unable to locate package libblas-dev:riscv64
E: Unable to locate package liblapack-dev:riscv64
```

**Root Cause:**
`archive.ubuntu.com` only hosts amd64/arm64/armhf. riscv64 packages live exclusively
on `ports.ubuntu.com`. Standard apt-get silently fails.

**Fix:**

```bash
sudo dpkg --add-architecture riscv64
echo "deb [arch=riscv64] http://ports.ubuntu.com/ubuntu-ports $(lsb_release -cs) main universe" \\
  | sudo tee /etc/apt/sources.list.d/ubuntu-ports-riscv64.list
sudo apt-get update
sudo apt-get install libblas-dev:riscv64 liblapack-dev:riscv64
```

**Why It Matters:**
Every BLAS-dependent code (~80 eigenvalue codes) requires this. Missing it silently
blocks the entire numerical linear algebra domain.

---

## Blocker 4 — OOFEM: Catch2 Test Subdirectory

**Code:** OOFEM 2.6

**Symptom:**

```
CMake Error at tests/CMakeLists.txt:5:
  Could not find Catch2 (missing: Catch2_DIR)
```

**Root Cause:**
OOFEM's test suite needs Catch2, which is not cross-compiled for riscv64. CMake
evaluates the test subdirectory at configure time, blocking the entire build.

**Fix:**

```bash
sed -i '/add_subdirectory(tests)/d' CMakeLists.txt
```

**Why It Matters:**
The solver binary has zero Catch2 dependency. Disabling tests unblocks the
production binary without affecting functionality.

**Verification:**

```bash
qemu-riscv64-static ./oofem --version
qemu-riscv64-static ./oofem -f truss2d_01.in
```

---

## Blocker 5 — OpenBLAS: Cross-Compilation Target Mismatch

**Code:** OpenBLAS 0.3.33

**Symptom:**

```
Makefile.system:72: *** Failed to detect CPU automatically. Please specify TARGET explicitly
```

**Root Cause:**
OpenBLAS auto-detection runs `uname -m`, returning the host arch (x86_64) even when
cross-compiling. It cannot detect the target from the cross-compiler alone.

**Fix:**

```bash
make CROSS=1 TARGET=RISCV64_GENERIC NO_SHARED=1 \\
     CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran
```

**Why It Matters:**
Without the explicit TARGET, make either aborts or produces x86 binaries that fail
under qemu-riscv64-static.

**Verification:**

```bash
file libopenblas_riscv64_genericp-r0.3.33.dev.a
# Expected: ELF 64-bit LSB relocatable, UCB RISC-V ...
```

---

## Blocker 6 — CalculiX: Undefined BLAS/LAPACK Symbols at Link Time

**Code:** CalculiX 2.21

**Symptom:**

```
/usr/bin/riscv64-linux-gnu-ld: undefined reference to 'dgemm_'
/usr/bin/riscv64-linux-gnu-ld: undefined reference to 'dgetrf_'
```

**Root Cause:**
CalculiX Makefile hardcodes `-lblas -llapack` assuming a native system install.
During cross-compilation the linker finds no riscv64 versions on host paths.

**Fix:**

```makefile
CC = riscv64-linux-gnu-gcc
FC = riscv64-linux-gnu-gfortran
LIBS = -L/usr/riscv64-linux-gnu/lib \\
       -L$(HOME)/rv-port-gurleen/spooles/build-riscv \\
       -L$(HOME)/rv-port-gurleen/arpack-ng/build-riscv \\
       -lspooles -larpack -lopenblas -lgfortran -lm -lpthread
```

**Verification:**

```bash
file ccx_2.21
qemu-riscv64-static ./ccx_2.21 achtel2
```

---

## Summary Table

| Blocker | Codes Affected | Root Cause | One-Line Fix |
|---|---|---|---|
| SPOOLES `-fcommon` | CalculiX + ~30 FEM | GCC 10+ default change | `CFLAGS=-fcommon` |
| `CMAKE_SYSROOT` | All CMake codes | Multiarch path override | Omit `CMAKE_SYSROOT` |
| Wrong apt mirror | All BLAS-dependent | riscv64 = ports arch | Use `ports.ubuntu.com` |
| Catch2 test dep | OOFEM, Elmer | Test-only dep | Disable test subdirectory |
| OpenBLAS target | ~80 eigenvalue codes | Auto-detect reads host arch | `TARGET=RISCV64_GENERIC` |
| CalculiX BLAS link | FEM solvers | Hardcoded native paths | Explicit `-L` multiarch |

Every blocker was diagnosed from actual build failures during the PoC phase.
These fixes are permanent and will scale to the full 400-code sweep.
""")

w("docs/ports/README.md", """\
# Port Docs

| Code | Version | Doc |
|---|---|---|
| GetDP | 4.0.0 | [getdp.md](getdp.md) |
| OOFEM | 2.6 | [oofem.md](oofem.md) |
| SPOOLES | 2.2 | [spooles.md](spooles.md) |
| OpenBLAS | 0.3.33 | [openblas.md](openblas.md) |
| ARPACK-ng | 3.9.1 | [arpack-ng.md](arpack-ng.md) |
| CalculiX | 2.21 | [calculix.md](calculix.md) |
""")

w("docs/ports/openblas.md", """\
# OpenBLAS 0.3.33 — riscv64 Port Notes

**Category:** Optimized BLAS/LAPACK | **Status:** built and validated
**Downstream:** ARPACK-ng, CalculiX, ~80 eigenvalue codes

## Build

```bash
git clone --depth 1 --branch v0.3.33 https://github.com/OpenMathLib/OpenBLAS.git
cd OpenBLAS
make CROSS=1 TARGET=RISCV64_GENERIC NO_SHARED=1 \\
     CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran -j$(nproc)
make PREFIX=$(pwd)/build-riscv install \\
     CROSS=1 TARGET=RISCV64_GENERIC NO_SHARED=1 \\
     CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran
```

## Key Pitfall
Always pass `TARGET=RISCV64_GENERIC` — never rely on auto-detection.
See Blocker 5 in toolchain-pitfalls.md.

## Verification

```bash
file build-riscv/lib/libopenblas.a
# Expected: ELF 64-bit LSB relocatable, UCB RISC-V
```
""")

w("docs/ports/spooles.md", """\
# SPOOLES 2.2 — riscv64 Port Notes

**Category:** Sparse direct linear solver | **Status:** built and validated
**Downstream:** CalculiX, Elmer, ~30 FEM codes

## Build

```bash
wget http://www.netlib.org/linalg/spooles/spooles.2.2.tgz
tar xf spooles.2.2.tgz && cd spooles.2.2
# Edit Make.inc: set CC = riscv64-linux-gnu-gcc and CFLAGS = -O2 -fcommon
make lib -j$(nproc)
mkdir -p build-riscv/lib && cp spooles.a build-riscv/lib/libspooles.a
```

## Key Pitfall
`-fcommon` is mandatory. See Blocker 1 in toolchain-pitfalls.md.

## Verification

```bash
file build-riscv/lib/libspooles.a
nm build-riscv/lib/libspooles.a | grep slock
```
""")

w("docs/ports/arpack-ng.md", """\
# ARPACK-ng 3.9.1 — riscv64 Port Notes

**Category:** Iterative eigenvalue solver | **Status:** built and validated
**Depends on:** OpenBLAS (build first)

## Build

```bash
git clone --depth 1 --branch 3.9.1 https://github.com/opencollab/arpack-ng.git
cd arpack-ng && mkdir build-riscv && cd build-riscv
cmake .. \\
  -DCMAKE_TOOLCHAIN_FILE=../../toolchain/riscv64-linux-gnu.cmake \\
  -DCMAKE_BUILD_TYPE=Release \\
  -DBLAS_LIBRARIES=$HOME/rv-port-gurleen/openblas/build-riscv/lib/libopenblas.a \\
  -DLAPACK_LIBRARIES=$HOME/rv-port-gurleen/openblas/build-riscv/lib/libopenblas.a \\
  -DBUILD_SHARED_LIBS=OFF
make -j$(nproc)
```

## Key Pitfall
Uses CMake — do not set `CMAKE_SYSROOT`. See Blocker 2 in toolchain-pitfalls.md.
""")

w("docs/ports/getdp.md", """\
# GetDP 4.0.0 — riscv64 Port Notes

**Category:** PDE solver (electromagnetics) | **Status:** built and validated

## Build

```bash
git clone https://gitlab.onelab.info/getdp/getdp.git
cd getdp && mkdir build-riscv && cd build-riscv
cmake .. \\
  -DCMAKE_TOOLCHAIN_FILE=../../toolchain/riscv64-linux-gnu.cmake \\
  -DCMAKE_BUILD_TYPE=Release \\
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
""")

w("docs/ports/oofem.md", """\
# OOFEM 2.6 — riscv64 Port Notes

**Category:** Object-oriented FEM solver | **Status:** built and validated

## Build

```bash
git clone --depth 1 --branch v2.6 https://github.com/oofem/oofem.git
cd oofem
sed -i '/add_subdirectory(tests)/d' CMakeLists.txt
mkdir build-riscv && cd build-riscv
cmake .. \\
  -DCMAKE_TOOLCHAIN_FILE=../../toolchain/riscv64-linux-gnu.cmake \\
  -DCMAKE_BUILD_TYPE=Release \\
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
""")

w("docs/ports/calculix.md", """\
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
LIBS = -L/usr/riscv64-linux-gnu/lib \\
       -L$(HOME)/rv-port-gurleen/spooles/build-riscv \\
       -L$(HOME)/rv-port-gurleen/arpack-ng/build-riscv \\
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
""")

w(".github/workflows/ci-riscv64.yml", """\
name: riscv64 Cross-Compile CI

on:
  push:
    branches: [main]
  pull_request:
    branches: [main]

jobs:
  cross-compile-openblas:
    name: Cross-compile OpenBLAS to riscv64
    runs-on: ubuntu-24.04
    steps:
      - uses: actions/checkout@v4

      - name: Install cross-toolchain
        run: |
          sudo apt-get update -qq
          sudo apt-get install -y gcc-riscv64-linux-gnu g++-riscv64-linux-gnu gfortran-riscv64-linux-gnu qemu-user-static

      - name: Build OpenBLAS riscv64
        run: |
          git clone --depth 1 --branch v0.3.33 https://github.com/OpenMathLib/OpenBLAS.git
          cd OpenBLAS
          make CROSS=1 TARGET=RISCV64_GENERIC NO_SHARED=1 CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran -j$(nproc)
          make PREFIX=$(pwd)/build-riscv install CROSS=1 TARGET=RISCV64_GENERIC NO_SHARED=1 CC=riscv64-linux-gnu-gcc FC=riscv64-linux-gnu-gfortran

      - name: Verify ELF architecture
        run: |
          file OpenBLAS/build-riscv/lib/libopenblas.a | grep -q "RISC-V" && echo "riscv64 confirmed" || exit 1

      - uses: actions/upload-artifact@v4
        with:
          name: openblas-riscv64
          path: OpenBLAS/build-riscv/lib/libopenblas.a
""")

print("\nAll files written successfully.")
