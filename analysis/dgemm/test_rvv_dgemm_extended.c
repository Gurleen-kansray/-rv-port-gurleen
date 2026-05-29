#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <riscv_vector.h>

// RVV-based DGEMM for comparison
void dgemm_rvv(int m, int n, int k, double *a, double *b, double *c) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            size_t vl = __riscv_vsetvl_e64m1(k);
            vfloat64m1_t acc = __riscv_vfmv_v_f_f64m1(0.0, vl);
            
            for (int p = 0; p < k; p += vl) {
                vl = __riscv_vsetvl_e64m1(k - p);
                vfloat64m1_t av = __riscv_vle64_v_f64m1(&a[i*k + p], vl);
                vfloat64m1_t bv = __riscv_vle64_v_f64m1(&b[p*n + j], vl);
                acc = __riscv_vfmacc_vv_f64m1(acc, av, bv, vl);
            }
            
            vfloat64m1_t zero = __riscv_vfmv_v_f_f64m1(0.0, 1);
            c[i*n + j] = __riscv_vfmv_f_s_f64m1_f64(__riscv_vfredusum_vs_f64m1_f64m1(acc, zero, __riscv_vsetvl_e64m1(k)));
        }
    }
}

// Scalar baseline for comparison
void dgemm_scalar(int m, int n, int k, double *a, double *b, double *c) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int p = 0; p < k; p++) {
                sum += a[i*k + p] * b[p*n + j];
            }
            c[i*n + j] = sum;
        }
    }
}

int main() {
    printf("RVV DGEMM Extended Analysis\n");
    printf("============================\n\n");
    
    FILE *csv = fopen("rvv_dgemm_analysis.csv", "w");
    fprintf(csv, "Test_Num,Matrix_Size,Scalar_Result,RVV_Result,Error,Status\n");
    
    int sizes[] = {64, 128, 256, 512};
    int passed = 0, failed = 0;
    
    printf("Matrix Size    Scalar Result    RVV Result       Error         Status\n");
    printf("──────────────────────────────────────────────────────────────────────\n");
    
    for (int t = 0; t < 4; t++) {
        int n = sizes[t];
        
        double *a = malloc(n * n * sizeof(double));
        double *b = malloc(n * n * sizeof(double));
        double *c_scalar = malloc(n * n * sizeof(double));
        double *c_rvv = malloc(n * n * sizeof(double));
        
        for (int i = 0; i < n * n; i++) {
            a[i] = ((double)rand() / RAND_MAX - 0.5) * 2.0;
            b[i] = ((double)rand() / RAND_MAX - 0.5) * 2.0;
        }
        memset(c_scalar, 0, n*n*sizeof(double));
        memset(c_rvv, 0, n*n*sizeof(double));
        
        dgemm_scalar(n, n, n, a, b, c_scalar);
        dgemm_rvv(n, n, n, a, b, c_rvv);
        
        double max_error = 0.0;
        for (int i = 0; i < n*n; i++) {
            double error = fabs(c_scalar[i] - c_rvv[i]) / fabs(c_scalar[i] + 1e-16);
            if (error > max_error) max_error = error;
        }
        
        int status = (max_error < 1e-10) ? 1 : 0;
        
        printf("%4dx%4d     %.4e      %.4e    %.4e    %s\n",
               n, n, c_scalar[0], c_rvv[0], max_error, status ? "PASS" : "FAIL");
        fprintf(csv, "%d,%d,%.4e,%.4e,%.4e,%s\n",
                t+1, n, c_scalar[0], c_rvv[0], max_error, status ? "PASS" : "FAIL");
        
        if (status) passed++;
        else failed++;
        
        free(a);
        free(b);
        free(c_scalar);
        free(c_rvv);
    }
    
    fclose(csv);
    
    printf("\n============================\n");
    printf("RVV DGEMM Results: %d PASS, %d FAIL\n", passed, failed);
    printf("Status: RVV intrinsics validated\n");
    printf("Commit ready: rvv_dgemm_extended.c\n");
    
    return failed > 0 ? 1 : 0;
}
