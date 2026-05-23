FINAL DISCOVERY: Sync Overhead in Production HPC Codes

Raw Data from 3 Production Codes

GetDP (FEM Electromagnetics)
- sched_yield: 0
- futex: 10 calls, 2.6 ms

OOFEM (Structural Mechanics)
- sched_yield: 0
- futex: 22 calls, 2.0 ms

ARPACK-ng (Linear Algebra, Threaded)
- sched_yield: 0
- futex: 552 calls, 163 ms

Key Finding:
Zero sched_yield calls across all tested production HPC codes.
Only futex appears, which is expected for thread synchronization.
