#include <stdio.h>
#include <math.h>

/* Standalone ODE correctness gate — no library needed */
/* Solves dy/dt = -y, y(0)=1, exact: y(t)=e^{-t} */
/* RK4 integration, 1000 steps, TOL=1e-6 */

#define N 1000
#define T_END 5.0
#define TOL 1e-6

double rk4_step(double y, double h) {
    double k1 = -y;
    double k2 = -(y + 0.5*h*k1);
    double k3 = -(y + 0.5*h*k2);
    double k4 = -(y + h*k3);
    return y + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4);
}

int main() {
    double h = T_END / N;
    double y = 1.0, t = 0.0;
    int pass = 0, fail = 0;
    double worst = 0.0;

    for (int i = 0; i < N; i++) {
        y = rk4_step(y, h);
        t += h;
        double exact = exp(-t);
        double err = fabs(y - exact);
        if (err > worst) worst = err;
        if (err < TOL) pass++;
        else fail++;
    }

    printf("ODE RK4: %d/1000 steps within TOL=1e-6\n", pass);
    printf("Worst error: %.2e\n", worst);
    if (fail == 0)
        printf("ODE SOLVER VALIDATED\n");
    else
        printf("ODE SOLVER FAILED: %d steps out of tolerance\n", fail);
    return 0;
}
