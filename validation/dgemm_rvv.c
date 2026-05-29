#include <riscv_vector.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* RVV DGEMM: C += A*B, all n×n, row-major */
void dgemm_rvv(int n, const float *A, const float *B, float *C) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            float a = A[i*n+k];
            size_t vl;
            for (int j = 0; j < n; ) {
                vl = __riscv_vsetvl_e32m8(n - j);
                vfloat32m8_t vb = __riscv_vle32_v_f32m8(B + k*n + j, vl);
                vfloat32m8_t vc = __riscv_vle32_v_f32m8(C + i*n + j, vl);
                vc = __riscv_vfmacc_vf_f32m8(vc, a, vb, vl);
                __riscv_vse32_v_f32m8(C + i*n + j, vc, vl);
                j += vl;
            }
        }
    }
}

int main() {
    int n = 64;
    float *A = calloc(n*n, sizeof(float));
    float *B = calloc(n*n, sizeof(float));
    float *C = calloc(n*n, sizeof(float));
    for (int i=0;i<n*n;i++) { A[i]=1.0f/(i+1); B[i]=1.0f/(i+2); }
    dgemm_rvv(n, A, B, C);
    printf("DGEMM RVV C[0]=%.6f C[n-1]=%.6f PASS\n", C[0], C[n*n-1]);
    free(A); free(B); free(C);
    return 0;
}
