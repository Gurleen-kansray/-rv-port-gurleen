#define BACKEND "sse2"
#include <xmmintrin.h>
typedef __m128 vec4f;
static inline vec4f vec4f_add(vec4f a, vec4f b) { return _mm_add_ps(a, b); }
static inline float vec4f_dot(vec4f a, vec4f b) {
    __m128 t = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ps(t, _mm_movehl_ps(t, t));
    s = _mm_add_ss(s, _mm_shuffle_ps(s, s, 1));
    float r; _mm_store_ss(&r, s); return r;
}
