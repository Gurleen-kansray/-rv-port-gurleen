# SLEPc 3.21.1 Cross-Compile Attempt — May 18, 2026

## ❌ Status: VERSION INCOMPATIBILITY

### Summary
SLEPc 3.20 and 3.21 are incompatible with PETSc 3.25 due to breaking API changes in `PetscViewerAndFormat` struct.

### Problem
- PETSc 3.25 removed/changed `lg` member from `PetscViewerAndFormat`
- SLEPc 3.20/3.21 source still references old API
- Latest SLEPc at time of port doesn't support PETSc 3.25

### Solution for Future
- Rebuild PETSc 3.20 (instead of 3.25), then use SLEPc 3.20
- Or wait for SLEPc 3.22+ with PETSc 3.25 support

### Impact
- Defers: 20+ eigenvalue solver codes
- Priority shift: Focus on FEM codes (CalculiX, FEniCS, deal.II) first
