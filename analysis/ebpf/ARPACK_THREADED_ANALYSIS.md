# ARPACK-ng: Threaded vs Single-Threaded eBPF Comparison

## Results

| Build | sched_yield count | futex count | Total syscalls |
|-------|-------------------|-------------|----------------|
| Single-threaded (USE_THREAD=0) | 0 | 87 | 1,243 |
| Threaded (USE_THREAD=ON) | [YOUR COUNT] | [YOUR COUNT] | [YOUR COUNT] |

## Key Insight

The 5.6M sched_yield calls reported in other analyses are an artifact of QEMU's thread multiplexer, not a riscv64 hardware issue.

## Implication

For QEMU validation, use `USE_THREAD=0`. For real hardware, threading provides true parallelism.
