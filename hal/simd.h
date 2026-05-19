#if defined(__SSE2__)
  #include "simd_x86.h"
#elif defined(__riscv)
  #include "simd_riscv.h"
#else
  #include "simd_scalar.h"
#endif

// ============================================
// RISC-V Vector Extension (RVV) – ACTUAL IMPLEMENTATION
// ============================================
#ifdef __riscv_v
#include <riscv_vector.h>

static inline double hal_dot4_rvv(const double a[4], const double b[4]) {
    vfloat64m1_t va = vle64_v_f64m1(a, 4);
    vfloat64m1_t vb = vle64_v_f64m1(b, 4);
    vfloat64m1_t vc = vfmul_vv_f64m1(va, vb, 4);
    return vfmv_f_s_f64m1_f64(vfredusum_vs_f64m1_f64m1(vc, vfmv_s_f_f64m1(0.0, 4), 4));
}

static inline void hal_fmadd_rvv(double* result, const double a[4], const double b[4], const double c[4]) {
    vfloat64m1_t va = vle64_v_f64m1(a, 4);
    vfloat64m1_t vb = vle64_v_f64m1(b, 4);
    vfloat64m1_t vc = vle64_v_f64m1(c, 4);
    vfloat64m1_t vd = vfmacc_vv_f64m1(vc, va, vb, 4);
    vse64_v_f64m1(result, vd, 4);
}

#endif

// ============================================
// RISC-V Vector Extension (RVV) Implementation
// ============================================
#ifdef __riscv_v
#include <riscv_vector.h>

// Vector dot product (4 elements)
static inline double hal_dot4_rvv(const double a[4], const double b[4]) {
    vfloat64m1_t va = vle64_v_f64m1(a, 4);
    vfloat64m1_t vb = vle64_v_f64m1(b, 4);
    vfloat64m1_t vc = vfmul_vv_f64m1(va, vb, 4);
    return vfmv_f_s_f64m1_f64(vfredusum_vs_f64m1_f64m1(vc, vfmv_s_f_f64m1(0.0, 4), 4));
}

// Fused multiply-add: result = a*b + c
static inline void hal_fmadd_rvv(double* result, const double a[4], const double b[4], const double c[4]) {
    vfloat64m1_t va = vle64_v_f64m1(a, 4);
    vfloat64m1_t vb = vle64_v_f64m1(b, 4);
    vfloat64m1_t vc = vle64_v_f64m1(c, 4);
    vfloat64m1_t vd = vfmacc_vv_f64m1(vc, va, vb, 4);
    vse64_v_f64m1(result, vd, 4);
}

#endif

// ============================================
// RISC-V Vector Extension (RVV) Implementation
// ============================================
#ifdef __riscv_v
#include <riscv_vector.h>

// Vector dot product (4 elements)
static inline double hal_dot4_rvv(const double a[4], const double b[4]) {
    vfloat64m1_t va = vle64_v_f64m1(a, 4);
    vfloat64m1_t vb = vle64_v_f64m1(b, 4);
    vfloat64m1_t vc = vfmul_vv_f64m1(va, vb, 4);
    return vfmv_f_s_f64m1_f64(vfredusum_vs_f64m1_f64m1(vc, vfmv_s_f_f64m1(0.0, 4), 4));
}

// Fused multiply-add: result = a*b + c
static inline void hal_fmadd_rvv(double* result, const double a[4], const double b[4], const double c[4]) {
    vfloat64m1_t va = vle64_v_f64m1(a, 4);
    vfloat64m1_t vb = vle64_v_f64m1(b, 4);
    vfloat64m1_t vc = vle64_v_f64m1(c, 4);
    vfloat64m1_t vd = vfmacc_vv_f64m1(vc, va, vb, 4);
    vse64_v_f64m1(result, vd, 4);
}

#endif
