#include <stdio.h>
#include "simd.h"
int main() {
    vec4f a = {1.0f, 2.0f, 3.0f, 4.0f};
    vec4f b = {5.0f, 6.0f, 7.0f, 8.0f};
    printf("backend : %s\n", BACKEND);
    printf("dot(a,b) = %.1f\n", vec4f_dot(a, b));
    return 0;
}
