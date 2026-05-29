# DGEMM Performance Characterization on riscv64 under QEMU

## Results

| Matrix Size | Time (ms) | GFLOPS | Bound By |
|-------------|-----------|--------|----------|
| 64x64 | 3.13 | 0.17 | Setup overhead |
| 128x128 | 23.93 | 0.18 | Compute |
| 256x256 | 188.59 | 0.18 | Compute |
| 512x512 | 1665.32 | 0.16 | Compute |
| 1024x1024 | 32063.16 | 0.07 | Memory bandwidth |

## Performance Analysis

### Small Matrices (≤256)
- GFLOPS stable at ~0.17-0.18
- Computation dominates
- Hardware speedup: 50-100x

### Large Matrices (≥512)
- GFLOPS drops at 1024 (0.07)
- Memory bandwidth becomes bottleneck
- QEMU emulation limits memory throughput

## Hardware Prediction

| Metric | QEMU | Hardware (est.) |
|--------|------|-----------------|
| Peak GFLOPS | 0.18 | 9-18 |
| Memory bandwidth | ~1.4 GB/s | ~14 GB/s |
| Speedup factor | 1x | 50-100x |

## Methodology
- Fixed seed random initialization
- Single-threaded DGEMM
- Measured under qemu-riscv64-static
