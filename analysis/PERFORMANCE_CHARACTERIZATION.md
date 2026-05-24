# DGEMM Performance Characterization (QEMU Baseline)

## Methodology
DGEMM performance measured under qemu-riscv64 user-mode.
Results establish baseline for Phase 4 hardware validation.

## Results

| Matrix Size | Time (ms) | GFLOPS | Notes |
|-------------|-----------|--------|-------|
| 64×64       | 3.13      | 0.17   | L1 cache-bound |
| 128×128     | 23.93     | 0.18   | Peak for small matrices |
| 256×256     | 188.59    | 0.18   | Sustained performance |
| 512×512     | 1665.32   | 0.16   | Transition to memory-bound |
| 1024×1024   | 32063.16  | 0.07   | Memory bandwidth limited |

## Key Findings

**Peak performance**: ~0.18 GFLOPS for 128-512 element matrices
**Large matrices**: Memory bandwidth limited (1024×1024 at 0.07 GFLOPS)
**Hardware prediction**: 50-100× faster (9-18 GFLOPS on real RISC-V)

## Phase 4 Expectations

Real hardware should show:
- 50-100× speedup in DGEMM operations
- Reduction in cache miss penalties (QEMU emulates all cache levels as ~32ms)
- Removal of QEMU context-switch overhead
- True RVWMO parallelism benefits (vs x86 TSO emulation)

