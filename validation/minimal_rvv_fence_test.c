// minimal_rvv_fence_test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdatomic.h>

#ifdef USE_RVV
#include <riscv_vector.h>
#endif

#define EPSILON 1e-6

void init_vector(float *v, int n, int seed) {
    srand(seed);
    for (int i = 0; i < n; i++) {
        v[i] = (float)(rand() % 100) / 10.0f;
    }
}

float dot_scalar(const float *x, const float *y, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += x[i] * y[i];
    }
    return sum;
}

#ifdef USE_RVV
float dot_rvv(const float *x, const float *y, int n) {
    float sum = 0.0f;
    size_t vl;
    vfloat32m1_t vec_x, vec_y;
    vfloat32m1_t vec_sum = __riscv_vfmv_v_f_f32m1(0.0f, 1);
    
    for (size_t i = 0; i < n; i += vl) {
        vl = __riscv_vsetvl_e32m1(n - i);
        vec_x = __riscv_vle32_v_f32m1(x + i, vl);
        vec_y = __riscv_vle32_v_f32m1(y + i, vl);
        vec_sum = __riscv_vfmacc_vv_f32m1(vec_sum, vec_x, vec_y, vl);
    }
    
    #if USE_FENCE == 1
    atomic_thread_fence(memory_order_seq_cst);
    #endif
    
    sum = __riscv_vfmv_f_s_f32m1_f32(__riscv_vfredusum_vs_f32m1_f32m1(vec_sum, vec_sum, __riscv_vsetvl_e32m1(1)));
    return sum;
}
#endif

int main(int argc, char *argv[]) {
    const int sizes[] = {1000, 10000, 100000, 1000000, 10000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("=== Minimal RVV Fence Test ===\n");
    #ifdef USE_RVV
    printf("Build: RVV with %s fence\n", 
           #if USE_FENCE == 1
           ""
           #else
           "out "
           #endif
    );
    #else
    printf("Build: Scalar (no vectorization)\n");
    #endif
    printf("================================\n\n");
    
    int passed = 0;
    int failed = 0;
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        
        float *x = (float*)malloc(n * sizeof(float));
        float *y = (float*)malloc(n * sizeof(float));
        float *z = (float*)malloc(n * sizeof(float));
        
        if (!x || !y || !z) {
            printf("Size %d: SKIP (malloc failed)\n", n);
            free(x); free(y); free(z);
            continue;
        }
        
        init_vector(x, n, 42);
        init_vector(y, n, 43);
        memcpy(z, y, n * sizeof(float));
        
        float scalar_result = dot_scalar(x, y, n);
        
        #ifdef USE_RVV
        float rvv_result = dot_rvv(x, z, n);
        #else
        float rvv_result = dot_scalar(x, z, n);
        #endif
        
        float error = 0.0f;
        if (scalar_result != 0.0f) {
            error = fabs((rvv_result - scalar_result) / scalar_result);
        } else {
            error = fabs(rvv_result - scalar_result);
        }
        
        if (error > EPSILON) {
            failed++;
            printf("Size %9d: FAIL | Error: %.2e\n", n, error);
        } else {
            passed++;
            printf("Size %9d: PASS | Error: %.2e\n", n, error);
        }
        
        free(x); free(y); free(z);
    }
    
    printf("\n================================\n");
    printf("Results: %d PASS, %d FAIL\n", passed, failed);
    
    return failed > 0 ? 1 : 0;
}
