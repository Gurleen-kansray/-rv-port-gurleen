/* RISC-V backend — scalar for now, RVV intrinsics planned */
#define BACKEND "riscv-scalar"
typedef struct { float x, y, z, w; } vec4f;
static inline vec4f vec4f_add(vec4f a, vec4f b) {
    return (vec4f){ a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w };
}
static inline float vec4f_dot(vec4f a, vec4f b) {
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}
