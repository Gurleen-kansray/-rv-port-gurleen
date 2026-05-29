/* simd_riscv.h — RISC-V Vector (RVV) backend
 *
 * Uses RVV intrinsics (rvv-0.10 / ratified 1.0 spec) when __riscv_vector
 * is defined by the compiler (riscv64-linux-gnu-gcc -march=rv64gcv).
 * Falls back to portable scalar code when RVV is not available so the
 * file compiles cleanly on any riscv64 target.
 *
 * Ported as part of LFX RISC-V HPC porting PoC.
 */

#ifndef SIMD_RISCV_H
#define SIMD_RISCV_H

#ifdef __riscv_vector
  #include <riscv_vector.h>
  #define BACKEND "riscv-rvv"
#else
  #define BACKEND "riscv-scalar"
#endif

#include <stddef.h>

/* --------------------------------------------------------------------------
 * Scalar type: vec4f
 * A 4-wide float vector used throughout the HAL interface.
 * -------------------------------------------------------------------------- */
typedef struct { float x, y, z, w; } vec4f;


/* --------------------------------------------------------------------------
 * vec4f_add — element-wise addition
 * RVV: load 4 floats into vfloat32m1, vadd, store back.
 * -------------------------------------------------------------------------- */
static inline vec4f vec4f_add(vec4f a, vec4f b) {
#ifdef __riscv_vector
    /* vl=4, use m1 (single register group) */
    size_t vl = __riscv_vsetvl_e32m1(4);
    float buf_a[4] = {a.x, a.y, a.z, a.w};
    float buf_b[4] = {b.x, b.y, b.z, b.w};
    vfloat32m1_t va = __riscv_vle32_v_f32m1(buf_a, vl);
    vfloat32m1_t vb = __riscv_vle32_v_f32m1(buf_b, vl);
    vfloat32m1_t vc = __riscv_vfadd_vv_f32m1(va, vb, vl);
    float out[4];
    __riscv_vse32_v_f32m1(out, vc, vl);
    return (vec4f){out[0], out[1], out[2], out[3]};
#else
    return (vec4f){a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w};
#endif
}


/* --------------------------------------------------------------------------
 * vec4f_sub — element-wise subtraction
 * -------------------------------------------------------------------------- */
static inline vec4f vec4f_sub(vec4f a, vec4f b) {
#ifdef __riscv_vector
    size_t vl = __riscv_vsetvl_e32m1(4);
    float buf_a[4] = {a.x, a.y, a.z, a.w};
    float buf_b[4] = {b.x, b.y, b.z, b.w};
    vfloat32m1_t va = __riscv_vle32_v_f32m1(buf_a, vl);
    vfloat32m1_t vb = __riscv_vle32_v_f32m1(buf_b, vl);
    vfloat32m1_t vc = __riscv_vfsub_vv_f32m1(va, vb, vl);
    float out[4];
    __riscv_vse32_v_f32m1(out, vc, vl);
    return (vec4f){out[0], out[1], out[2], out[3]};
#else
    return (vec4f){a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w};
#endif
}


/* --------------------------------------------------------------------------
 * vec4f_mul — element-wise multiply
 * -------------------------------------------------------------------------- */
static inline vec4f vec4f_mul(vec4f a, vec4f b) {
#ifdef __riscv_vector
    size_t vl = __riscv_vsetvl_e32m1(4);
    float buf_a[4] = {a.x, a.y, a.z, a.w};
    float buf_b[4] = {b.x, b.y, b.z, b.w};
    vfloat32m1_t va = __riscv_vle32_v_f32m1(buf_a, vl);
    vfloat32m1_t vb = __riscv_vle32_v_f32m1(buf_b, vl);
    vfloat32m1_t vc = __riscv_vfmul_vv_f32m1(va, vb, vl);
    float out[4];
    __riscv_vse32_v_f32m1(out, vc, vl);
    return (vec4f){out[0], out[1], out[2], out[3]};
#else
    return (vec4f){a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w};
#endif
}


/* --------------------------------------------------------------------------
 * vec4f_dot — dot product (returns scalar float)
 * RVV: multiply then vfredusum (ordered float reduction) into scalar.
 * -------------------------------------------------------------------------- */
static inline float vec4f_dot(vec4f a, vec4f b) {
#ifdef __riscv_vector
    size_t vl = __riscv_vsetvl_e32m1(4);
    float buf_a[4] = {a.x, a.y, a.z, a.w};
    float buf_b[4] = {b.x, b.y, b.z, b.w};
    vfloat32m1_t va  = __riscv_vle32_v_f32m1(buf_a, vl);
    vfloat32m1_t vb  = __riscv_vle32_v_f32m1(buf_b, vl);
    vfloat32m1_t vp  = __riscv_vfmul_vv_f32m1(va, vb, vl);
    /* reduction: sum all lanes into a single scalar */
    vfloat32m1_t zero = __riscv_vfmv_v_f_f32m1(0.0f, vl);
    vfloat32m1_t red  = __riscv_vfredusum_vs_f32m1_f32m1(vp, zero, vl);
    return __riscv_vfmv_f_s_f32m1_f32(red);
#else
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
#endif
}


/* --------------------------------------------------------------------------
 * vec4f_scale — multiply all elements by a scalar
 * -------------------------------------------------------------------------- */
static inline vec4f vec4f_scale(vec4f a, float s) {
#ifdef __riscv_vector
    size_t vl = __riscv_vsetvl_e32m1(4);
    float buf[4] = {a.x, a.y, a.z, a.w};
    vfloat32m1_t va = __riscv_vle32_v_f32m1(buf, vl);
    vfloat32m1_t vc = __riscv_vfmul_vf_f32m1(va, s, vl);
    float out[4];
    __riscv_vse32_v_f32m1(out, vc, vl);
    return (vec4f){out[0], out[1], out[2], out[3]};
#else
    return (vec4f){a.x*s, a.y*s, a.z*s, a.w*s};
#endif
}


/* --------------------------------------------------------------------------
 * vec4f_madd — fused multiply-add:  a * b + c
 * RVV: vfmadd — single instruction, no rounding between mul and add.
 * This is the key instruction for HPC BLAS-level inner loops (DGEMM, etc).
 * -------------------------------------------------------------------------- */
static inline vec4f vec4f_madd(vec4f a, vec4f b, vec4f c) {
#ifdef __riscv_vector
    size_t vl = __riscv_vsetvl_e32m1(4);
    float buf_a[4] = {a.x, a.y, a.z, a.w};
    float buf_b[4] = {b.x, b.y, b.z, b.w};
    float buf_c[4] = {c.x, c.y, c.z, c.w};
    vfloat32m1_t va = __riscv_vle32_v_f32m1(buf_a, vl);
    vfloat32m1_t vb = __riscv_vle32_v_f32m1(buf_b, vl);
    vfloat32m1_t vc = __riscv_vle32_v_f32m1(buf_c, vl);
    /* vfmadd: va = va*vb + vc */
    vfloat32m1_t vr = __riscv_vfmadd_vv_f32m1(va, vb, vc, vl);
    float out[4];
    __riscv_vse32_v_f32m1(out, vr, vl);
    return (vec4f){out[0], out[1], out[2], out[3]};
#else
    return (vec4f){a.x*b.x+c.x, a.y*b.y+c.y, a.z*b.z+c.z, a.w*b.w+c.w};
#endif
}


/* --------------------------------------------------------------------------
 * axpy_rvv — full vector AXPY:  y[i] = a*x[i] + y[i]  for n elements
 *
 * This is the core BLAS Level-1 operation. The RVV implementation uses
 * a strip-mining loop with vsetvl so it handles any n, not just multiples
 * of the vector register width. This is the RVV idiom that makes RISC-V
 * vectors portable across different hardware VLEN values (128, 256, 512...).
 * -------------------------------------------------------------------------- */
static inline void axpy_rvv(float a, const float *x, float *y, size_t n) {
#ifdef __riscv_vector
    for (size_t i = 0; i < n; ) {
        size_t vl = __riscv_vsetvl_e32m8(n - i);   /* m8: use 8 regs for max throughput */
        vfloat32m8_t vx = __riscv_vle32_v_f32m8(x + i, vl);
        vfloat32m8_t vy = __riscv_vle32_v_f32m8(y + i, vl);
        vy = __riscv_vfmacc_vf_f32m8(vy, a, vx, vl);  /* vy = a*vx + vy */
        __riscv_vse32_v_f32m8(y + i, vy, vl);
        i += vl;
    }
#else
    for (size_t i = 0; i < n; i++)
        y[i] = a * x[i] + y[i];
#endif
}


/* --------------------------------------------------------------------------
 * dot_rvv — full vector dot product:  sum(x[i]*y[i])  for n elements
 * -------------------------------------------------------------------------- */
static inline float dot_rvv(const float *x, const float *y, size_t n) {
#ifdef __riscv_vector
    vfloat32m8_t  vacc  = __riscv_vfmv_v_f_f32m8(0.0f, __riscv_vsetvlmax_e32m8());
    for (size_t i = 0; i < n; ) {
        size_t vl = __riscv_vsetvl_e32m8(n - i);
        vfloat32m8_t vx = __riscv_vle32_v_f32m8(x + i, vl);
        vfloat32m8_t vy = __riscv_vle32_v_f32m8(y + i, vl);
        vacc = __riscv_vfmacc_vv_f32m8(vacc, vx, vy, vl);
        i += vl;
    }
    /* reduce m8 accumulator to scalar */
    size_t vl1 = __riscv_vsetvlmax_e32m1();
    vfloat32m1_t zero = __riscv_vfmv_v_f_f32m1(0.0f, vl1);
    vfloat32m1_t red  = __riscv_vfredusum_vs_f32m8_f32m1(vacc, zero, __riscv_vsetvlmax_e32m8());
    return __riscv_vfmv_f_s_f32m1_f32(red);
#else
    float acc = 0.0f;
    for (size_t i = 0; i < n; i++) acc += x[i] * y[i];
    return acc;
#endif
}

#endif /* SIMD_RISCV_H */
