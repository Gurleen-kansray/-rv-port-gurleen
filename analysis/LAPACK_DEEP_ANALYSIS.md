# LAPACK Performance Deep Dive

## Routines Analyzed

| Routine | Operation | Complexity | Our Time (1000x1000) |
|---------|-----------|------------|----------------------|
| dgesv | Linear solve | O(n³) | 4,023.64 ms |
| dpotrf | Cholesky | O(n³) | 1,810.93 ms |
| dgetrf | LU factor | O(n³) | (measured) |
| dgeqrf | QR factor | O(n³) | (measured) |
| dsyev | Eigenvalue | O(n³) | (measured) |

## Scaling Analysis

### dgesv Scaling
| n | Time (ms) | n³/Time | GFLOPS |
|---|-----------|---------|--------|
| 100 | 4.29 | 233,100 | 0.23 |
| 200 | 34.62 | 231,000 | 0.23 |
| 500 | 507.18 | 246,500 | 0.25 |
| 1000 | 4,023.64 | 248,500 | 0.25 |

**Observation:** GFLOPS stable at ~0.24, indicating compute-bound under QEMU.

## Hardware Prediction

| Routine | QEMU Time | Hardware Prediction | Speedup |
|---------|-----------|---------------------|---------|
| dgesv (1000) | 4.0 sec | 0.2-0.8 sec | 5-20x |
| dpotrf (1000) | 1.8 sec | 0.09-0.36 sec | 5-20x |

## Comparison with OpenBLAS Depth

| Aspect | Vaibhav (OpenBLAS) | Me (LAPACK) |
|--------|--------------------|--------------|
| Focus | BLAS kernels | LAPACK routines |
| Metrics | Opcode counts | Performance (ms, GFLOPS) |
| Impact | Low-level optimization | Application-level solvers |

**Both are needed. I bring application-level depth.**
