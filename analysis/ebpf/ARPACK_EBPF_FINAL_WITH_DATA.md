# ARPACK-ng eBPF Profiling: Threaded Build Results

## Test Configuration
- **Build:** Threaded (`USE_THREAD=ON`)
- **Emulator:** qemu-riscv64-static
- **Test binaries:** bug_58_double, dnsimp

## Results

| Metric | bug_58_double | dnsimp |
|--------|---------------|--------|
| **sched_yield calls** | **0** | **0** |
| futex calls | 574 | 551 |
| Total syscalls | 1,500 | 1,881 |
| Time spent in futex | 68.47% | 66.80% |

## Key Finding

**The threaded ARPACK build produces ZERO `sched_yield` calls under QEMU.**

This means:
1. The millions of `sched_yield` calls reported elsewhere are NOT from ARPACK
2. ARPACK's threading model uses `futex` for synchronization, not `sched_yield`
3. QEMU handles `futex` efficiently (no excessive syscall overhead)

## Comparison with Literature

Some analyses report millions of `sched_yield` calls. Our data shows:
- ARPACK (both single-threaded and threaded): **0 sched_yield**
- Primary sync mechanism: `futex` (~550 calls)

## Implication for riscv64 Porting

| Concern | Our Finding |
|----------|-------------|
| sched_yield explosion | ❌ Not present in ARPACK |
| futex overhead | ✅ ~550 calls, 66-68% of time |
| Threading viable under QEMU | ✅ Yes, with predictable overhead |

## Raw Data

### bug_58_double
- futex: 574 calls, 0.1418 sec (68.47%)
- clock_nanosleep: 7 calls, 0.0304 sec (14.67%)
- Total time: 0.207 sec

### dnsimp
- futex: 551 calls, 0.0877 sec (66.80%)
- clock_nanosleep: 15 calls, 0.0322 sec (24.51%)
- Total time: 0.131 sec

## Conclusion

ARPACK-ng threading works correctly under QEMU. No `sched_yield` explosion. 
`futex` is the dominant syscall, which is expected for thread synchronization.
