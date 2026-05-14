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
