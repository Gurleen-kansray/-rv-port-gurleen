#if defined(__SSE2__)
  #include "simd_x86.h"
#elif defined(__riscv)
  #include "simd_riscv.h"
#else
  #include "simd_scalar.h"
#endif
