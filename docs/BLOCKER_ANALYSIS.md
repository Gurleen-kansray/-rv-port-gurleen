# Known Blockers & Solutions

## Blocker 1: GCC -fcommon Issue
**Codes affected:** SPOOLES, CalculiX, ~15 others
**Error:** Multiple definition of 'symbol'
**Solution:** `CFLAGS="-fcommon" ./configure`
**Status:** ✅ Solved

## Blocker 2: CMAKE_SYSROOT Issue
**Codes affected:** All CMake-based (~60 codes)
**Error:** Cannot find headers in sysroot
**Solution:** Use CMAKE_FIND_ROOT_PATH, omit CMAKE_SYSROOT
**Status:** ✅ Solved in toolchain

## Blocker 3: BLAS Symbol Linking
**Codes affected:** ARPACK, ScaLAPACK, PETSc (~80 codes)
**Error:** undefined reference to 'sgemm_'
**Solution:** `cmake -DBLAS_LIBRARIES=/path/to/libopenblas.a`
**Status:** ✅ Solved

## Blocker 4: Catch2 Framework
**Codes affected:** OOFEM, Elmer (~5 codes)
**Error:** Can't cross-compile tests
**Solution:** `-DCMAKE_DISABLE_TESTING=ON`
**Status:** ✅ Solved

## Blocker 5: x86 Intrinsics
**Codes affected:** ~20 performance codes
**Error:** '_mm_add_epi32' undefined
**Solution:** Use hal/simd.h wrapper
**Status:** ✅ HAL ready (SSE2 + scalar + RVV)

## Future Blockers (Identified)

**deal.II:** BLAS symbol check - Medium impact
**PETSc:** --with-batch complexity - High impact (~50 codes)
**Trilinos:** Deep CMake - Very high impact (~40 codes)
