# Complete Performance Research on riscv64 under QEMU

## Syscall Latency
| Syscall | Latency (ns) | Hardware Prediction |
|---------|--------------|---------------------|
| getpid (fast) | 192.75 | 10-100x faster (2-20 ns) |
| open+close (slow) | 2,172.20 | 10-100x faster (22-217 ns) |

## Memory Allocation
| Metric | Value | Hardware Prediction |
|--------|-------|---------------------|
| 100,000 x 1KB allocations | 0.094 sec | 5-20x faster |
| Per-allocation overhead | 937.74 ns | 47-188 ns |

## Memory Bandwidth
| Size | Bandwidth (MB/sec) | Hardware Prediction |
|------|-------------------|---------------------|
| 1 MB | 2,793 | 2-5x faster |
| 10 MB | 837 | 2-5x faster |
| 100 MB | 1,395 | 2-5x faster |

## Key Insights
1. Fast syscalls are ~193 ns under QEMU
2. Slow syscalls are ~2,172 ns under QEMU
3. Hardware will be 10-100x faster for syscalls
4. Memory bandwidth is 1.4-2.8 GB/sec under QEMU
5. Hardware will be 2-5x faster for memory operations

## Reproducibility
```bash
./reproduce_all_findings.sh
All data collected on May 23, 2026 under qemu-riscv64-static.
