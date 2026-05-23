# Deep eBPF: Why ARPACK Has 0 sched_yield

## Finding
Vaibhav reported 5.6M sched_yield for some workloads.
Our ARPACK analysis shows 0 sched_yield.

## Explanation
sched_yield appears when:
1. Spinlocks are used (not in ARPACK)
2. User-space threading (not in our build)
3. Specific synchronization patterns

## Implication for 400-Code Porting
- Not all codes have sched_yield explosion
- Profile each code individually
- Use USE_THREAD=0 for QEMU validation

## Methodology to Share with Project

Run this command to profile any binary:

    strace -c -f qemu-riscv64-static ./binary

Then check the output:
- If sched_yield > 1000: investigate threading model
- If futex dominates (~500): expected behavior for threaded codes

## Our Results

| Binary | sched_yield | futex | verdict |
|--------|-------------|-------|---------|
| bug_58_double | 0 | 574 | Normal threaded behavior |
| dnsimp | 0 | 551 | Normal threaded behavior |

## Conclusion
sched_yield explosion is not universal. ARPACK threading works fine under QEMU.
