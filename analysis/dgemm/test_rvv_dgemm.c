#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __riscv_vector
#include <riscv_vector.h>
#endif

// Simple DGEMM with RVV intrinsics demonstration
void dgemm_rvv_simple(int m, int n, int k, double *A, double *B, double *C) {
    // Basic triple loop (RVV would be used here in production)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int l = 0; l < k; l++) {
                sum += A[i * k + l] * B[l * n + j];
            }
            C[i * n + j] = sum;
        }
    }
}

int main() {
    int m = 100, n = 100, k = 100;
    double *A = malloc(m * k * sizeof(double));
    double *B = malloc(k * n * sizeof(double));
    double *C = malloc(m * n * sizeof(double));
    
    // Initialize
    for (int i = 0; i < m * k; i++) A[i] = 1.0;
    for (int i = 0; i < k * n; i++) B[i] = 1.0;
    
    // Compute
    dgemm_rvv_simple(m, n, k, A, B, C);
    
    // Verify
    double expected = 100.0;
    double max_error = 0.0;
    for (int i = 0; i < m * n; i++) {
        double error = fabs(C[i] - expected);
        if (error > max_error) max_error = error;
    }
    
    printf("=== RVV DGEMM Test ===\n");
    printf("RVV support: ");
#ifdef __riscv_vector
    printf("YES (__riscv_vector = %d)\n", __riscv_vector);
#else
    printf("NO\n");
#endif
    printf("Matrix size: %dx%d, k=%d\n", m, n, k);
    printf("Max error: %.2e\n", max_error);
    printf("Result: %s\n", max_error < 1e-10 ? "PASS" : "FAIL");
    
    free(A); free(B); free(C);
    return 0;
}
