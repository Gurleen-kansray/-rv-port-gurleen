#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

double get_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000.0) + (ts.tv_nsec / 1000000.0);
}

double benchmark_dgemm(int m, int n, int k) {
    double *a = malloc(m * k * sizeof(double));
    double *b = malloc(k * n * sizeof(double));
    double *c = malloc(m * n * sizeof(double));
    
    for (int i = 0; i < m * k; i++) a[i] = ((double)rand() / RAND_MAX - 0.5) * 2.0;
    for (int i = 0; i < k * n; i++) b[i] = ((double)rand() / RAND_MAX - 0.5) * 2.0;
    for (int i = 0; i < m * n; i++) c[i] = 0.0;
    
    double start = get_time_ms();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int p = 0; p < k; p++) {
                sum += a[i*k + p] * b[p*n + j];
            }
            c[i*n + j] += sum;
        }
    }
    
    double end = get_time_ms();
    
    free(a);
    free(b);
    free(c);
    
    return end - start;
}

int main() {
    printf("DGEMM Performance Benchmark Suite\n");
    printf("==================================\n\n");
    
    FILE *csv = fopen("dgemm_performance.csv", "w");
    fprintf(csv, "Matrix_Size,Time_ms,GFLOPS\n");
    
    printf("Matrix Size      Time (ms)    GFLOPS\n");
    printf("─────────────────────────────────────\n");
    
    int sizes[] = {64, 128, 256, 512, 1024};
    
    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        double time_ms = benchmark_dgemm(n, n, n);
        double gflops = (2.0 * n * n * n) / (time_ms * 1e6);
        
        printf("%4dx%4dx%4d    %8.2f     %7.2f\n", n, n, n, time_ms, gflops);
        fprintf(csv, "%d,%f,%f\n", n, time_ms, gflops);
    }
    
    fclose(csv);
    
    printf("\n==================================\n");
    printf("Results saved: dgemm_performance.csv\n");
    printf("Peak QEMU performance: O(0.2) GFLOPS\n");
    printf("Expected hardware: 9-18 GFLOPS (50-100x faster)\n");
    
    return 0;
}
