#include <stdio.h>
#include <math.h>
#define N 100
#define TOL 1e-8
void thomas_solve(double *a, double *b, double *c, double *d, double *x, int n) {
    double w[100], g[100];
    w[0] = b[0]; g[0] = d[0] / w[0];
    for (int i = 1; i < n; i++) {
        w[i] = b[i] - a[i] * c[i-1] / w[i-1];
        g[i] = (d[i] - a[i] * g[i-1]) / w[i];
    }
    x[n-1] = g[n-1];
    for (int i = n-2; i >= 0; i--)
        x[i] = g[i] - c[i] * x[i+1] / w[i];
}
int main() {
    double a[N], b[N], c[N], d[N], x[N];
    int pass = 0, fail = 0; double worst = 0.0;
    /* Tridiagonal: diag=2, off=-1, rhs=1 => x[i]=(i+1)*(N-i)/2 / N+1 style */
    for (int i = 0; i < N; i++) { a[i]=-1.0; b[i]=2.0; c[i]=-1.0; d[i]=1.0; }
    thomas_solve(a, b, c, d, x, N);
    /* Verify Ax=b residual instead of exact solution */
    double res_worst = 0.0;
    for (int i = 0; i < N; i++) {
        double ax = b[i]*x[i];
        if (i>0) ax += a[i]*x[i-1];
        if (i<N-1) ax += c[i]*x[i+1];
        double res = fabs(ax - d[i]);
        if (res > res_worst) res_worst = res;
        if (res < TOL) pass++; else fail++;
    }
    printf("Sparse Tridiagonal Solve: %d/%d residuals within TOL=1e-8\n", pass, N);
    printf("Worst residual: %.2e\n", res_worst);
    if (fail == 0) printf("SPARSE SOLVER VALIDATED\n");
    else printf("SPARSE SOLVER FAILED\n");
    return 0;
}
