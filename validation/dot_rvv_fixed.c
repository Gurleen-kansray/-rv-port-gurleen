#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <riscv_vector.h>

void init_vector(float *v, int n, int seed) {
    srand(seed);
    for (int i = 0; i < n; i++) v[i] = (float)(rand() % 100) / 10.0f;
}

float dot_scalar(const float *x, const float *y, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += (double)x[i] * y[i];
    return (float)sum;
}

float dot_rvv(const float *x, const float *y, int n) {
    size_t vl;
    vfloat32m8_t vacc = __riscv_vfmv_v_f_f32m8(0.0f, __riscv_vsetvlmax_e32m8());
    for (size_t i = 0; i < (size_t)n; i += vl) {
        vl = __riscv_vsetvl_e32m8(n - i);
        vfloat32m8_t vx = __riscv_vle32_v_f32m8(x + i, vl);
        vfloat32m8_t vy = __riscv_vle32_v_f32m8(y + i, vl);
        vacc = __riscv_vfmacc_vv_f32m8(vacc, vx, vy, vl);
    }
    vfloat32m1_t zero = __riscv_vfmv_v_f_f32m1(0.0f, __riscv_vsetvlmax_e32m1());
    vfloat32m1_t red = __riscv_vfredusum_vs_f32m8_f32m1(vacc, zero, __riscv_vsetvlmax_e32m8());
    return __riscv_vfmv_f_s_f32m1_f32(red);
}

int main() {
    const int sizes[] = {1000, 10000, 100000, 1000000, 10000000};
    /* epsilon scales with sqrt(n) for float accumulation */
    const float epsilons[] = {1e-4, 1e-4, 1e-3, 1e-2, 5e-2};
    int passed = 0, failed = 0;
    printf("=== RVV dot_rvv Corrected Reduction ===\n\n");
    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        float *x = malloc(n * sizeof(float));
        float *y = malloc(n * sizeof(float));
        init_vector(x, n, 42); init_vector(y, n, 43);
        float ref = dot_scalar(x, y, n);
        float rvv = dot_rvv(x, y, n);
        float err = fabsf((rvv - ref) / ref);
        if (err <= epsilons[i]) { passed++; printf("Size %9d: PASS | Error: %.2e (eps %.0e)\n", n, err, epsilons[i]); }
        else                    { failed++; printf("Size %9d: FAIL | Error: %.2e (eps %.0e)\n", n, err, epsilons[i]); }
        free(x); free(y);
    }
    printf("\n=======================================\n");
    printf("Results: %d PASS, %d FAIL\n", passed, failed);
    return failed > 0 ? 1 : 0;
}
