# 0 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/riscv64-linux-gnu/include/stdc-predef.h" 1 3
# 0 "<command-line>" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
# 22 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 1
# 26 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/float.h" 1 3 4
# 27 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 2


# 1 "/usr/riscv64-linux-gnu/include/string.h" 1 3
# 26 "/usr/riscv64-linux-gnu/include/string.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/libc-header-start.h" 1 3
# 33 "/usr/riscv64-linux-gnu/include/bits/libc-header-start.h" 3
# 1 "/usr/riscv64-linux-gnu/include/features.h" 1 3
# 394 "/usr/riscv64-linux-gnu/include/features.h" 3
# 1 "/usr/riscv64-linux-gnu/include/features-time64.h" 1 3
# 20 "/usr/riscv64-linux-gnu/include/features-time64.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/wordsize.h" 1 3
# 21 "/usr/riscv64-linux-gnu/include/features-time64.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/timesize.h" 1 3
# 22 "/usr/riscv64-linux-gnu/include/features-time64.h" 2 3
# 395 "/usr/riscv64-linux-gnu/include/features.h" 2 3
# 502 "/usr/riscv64-linux-gnu/include/features.h" 3
# 1 "/usr/riscv64-linux-gnu/include/sys/cdefs.h" 1 3
# 576 "/usr/riscv64-linux-gnu/include/sys/cdefs.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/wordsize.h" 1 3
# 577 "/usr/riscv64-linux-gnu/include/sys/cdefs.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/long-double.h" 1 3
# 578 "/usr/riscv64-linux-gnu/include/sys/cdefs.h" 2 3
# 503 "/usr/riscv64-linux-gnu/include/features.h" 2 3
# 526 "/usr/riscv64-linux-gnu/include/features.h" 3
# 1 "/usr/riscv64-linux-gnu/include/gnu/stubs.h" 1 3




# 1 "/usr/riscv64-linux-gnu/include/bits/wordsize.h" 1 3
# 6 "/usr/riscv64-linux-gnu/include/gnu/stubs.h" 2 3
# 17 "/usr/riscv64-linux-gnu/include/gnu/stubs.h" 3
# 1 "/usr/riscv64-linux-gnu/include/gnu/stubs-lp64d.h" 1 3
# 18 "/usr/riscv64-linux-gnu/include/gnu/stubs.h" 2 3
# 527 "/usr/riscv64-linux-gnu/include/features.h" 2 3
# 34 "/usr/riscv64-linux-gnu/include/bits/libc-header-start.h" 2 3
# 27 "/usr/riscv64-linux-gnu/include/string.h" 2 3






# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 1 3 4
# 214 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 3 4

# 214 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/riscv64-linux-gnu/include/string.h" 2 3
# 43 "/usr/riscv64-linux-gnu/include/string.h" 3
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/riscv64-linux-gnu/include/string.h" 3
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/riscv64-linux-gnu/include/string.h" 3
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



# 1 "/usr/riscv64-linux-gnu/include/bits/types/locale_t.h" 1 3
# 22 "/usr/riscv64-linux-gnu/include/bits/types/locale_t.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/types/__locale_t.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/bits/types/__locale_t.h" 3
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/riscv64-linux-gnu/include/bits/types/locale_t.h" 2 3

typedef __locale_t locale_t;
# 173 "/usr/riscv64-linux-gnu/include/string.h" 2 3


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 286 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 380 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));







extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/riscv64-linux-gnu/include/string.h" 3
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 458 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/riscv64-linux-gnu/include/strings.h" 1 3
# 23 "/usr/riscv64-linux-gnu/include/strings.h" 3
# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 1 3 4
# 24 "/usr/riscv64-linux-gnu/include/strings.h" 2 3










extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/riscv64-linux-gnu/include/strings.h" 3
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/riscv64-linux-gnu/include/strings.h" 3
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



# 463 "/usr/riscv64-linux-gnu/include/string.h" 2 3



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 489 "/usr/riscv64-linux-gnu/include/string.h" 3
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlcpy (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



extern size_t strlcat (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
# 552 "/usr/riscv64-linux-gnu/include/string.h" 3

# 30 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 2
# 88 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h" 1
# 72 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h"
# 1 "/usr/riscv64-linux-gnu/include/stdlib.h" 1 3
# 26 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/libc-header-start.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3





# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 1 3 4
# 329 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3







# 1 "/usr/riscv64-linux-gnu/include/bits/waitflags.h" 1 3
# 41 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/waitstatus.h" 1 3
# 42 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3
# 56 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/floatn.h" 1 3
# 23 "/usr/riscv64-linux-gnu/include/bits/floatn.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/long-double.h" 1 3
# 24 "/usr/riscv64-linux-gnu/include/bits/floatn.h" 2 3
# 95 "/usr/riscv64-linux-gnu/include/bits/floatn.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/floatn-common.h" 1 3
# 24 "/usr/riscv64-linux-gnu/include/bits/floatn-common.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/long-double.h" 1 3
# 25 "/usr/riscv64-linux-gnu/include/bits/floatn-common.h" 2 3
# 96 "/usr/riscv64-linux-gnu/include/bits/floatn.h" 2 3
# 57 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 98 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;



extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 177 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 505 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/riscv64-linux-gnu/include/sys/types.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/sys/types.h" 3


# 1 "/usr/riscv64-linux-gnu/include/bits/types.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/bits/types.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/wordsize.h" 1 3
# 28 "/usr/riscv64-linux-gnu/include/bits/types.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/timesize.h" 1 3
# 29 "/usr/riscv64-linux-gnu/include/bits/types.h" 2 3


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/riscv64-linux-gnu/include/bits/types.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/typesizes.h" 1 3
# 142 "/usr/riscv64-linux-gnu/include/bits/types.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/time64.h" 1 3
# 143 "/usr/riscv64-linux-gnu/include/bits/types.h" 2 3


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 30 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
# 59 "/usr/riscv64-linux-gnu/include/sys/types.h" 3
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 97 "/usr/riscv64-linux-gnu/include/sys/types.h" 3
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;




# 1 "/usr/riscv64-linux-gnu/include/bits/types/clock_t.h" 1 3






typedef __clock_t clock_t;
# 127 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3

# 1 "/usr/riscv64-linux-gnu/include/bits/types/clockid_t.h" 1 3






typedef __clockid_t clockid_t;
# 129 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/types/time_t.h" 1 3
# 10 "/usr/riscv64-linux-gnu/include/bits/types/time_t.h" 3
typedef __time_t time_t;
# 130 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/types/timer_t.h" 1 3






typedef __timer_t timer_t;
# 131 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3
# 144 "/usr/riscv64-linux-gnu/include/sys/types.h" 3
# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 1 3 4
# 145 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;




# 1 "/usr/riscv64-linux-gnu/include/bits/stdint-intn.h" 1 3
# 24 "/usr/riscv64-linux-gnu/include/bits/stdint-intn.h" 3
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 156 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3


typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
# 176 "/usr/riscv64-linux-gnu/include/sys/types.h" 3
# 1 "/usr/riscv64-linux-gnu/include/endian.h" 1 3
# 24 "/usr/riscv64-linux-gnu/include/endian.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/endian.h" 1 3
# 35 "/usr/riscv64-linux-gnu/include/bits/endian.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/endianness.h" 1 3
# 36 "/usr/riscv64-linux-gnu/include/bits/endian.h" 2 3
# 25 "/usr/riscv64-linux-gnu/include/endian.h" 2 3
# 35 "/usr/riscv64-linux-gnu/include/endian.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/byteswap.h" 1 3
# 33 "/usr/riscv64-linux-gnu/include/bits/byteswap.h" 3
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{

  return __builtin_bswap16 (__bsx);



}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{

  return __builtin_bswap32 (__bsx);



}
# 69 "/usr/riscv64-linux-gnu/include/bits/byteswap.h" 3
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{

  return __builtin_bswap64 (__bsx);



}
# 36 "/usr/riscv64-linux-gnu/include/endian.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/uintn-identity.h" 1 3
# 32 "/usr/riscv64-linux-gnu/include/bits/uintn-identity.h" 3
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
# 37 "/usr/riscv64-linux-gnu/include/endian.h" 2 3
# 177 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3


# 1 "/usr/riscv64-linux-gnu/include/sys/select.h" 1 3
# 30 "/usr/riscv64-linux-gnu/include/sys/select.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/select.h" 1 3
# 31 "/usr/riscv64-linux-gnu/include/sys/select.h" 2 3


# 1 "/usr/riscv64-linux-gnu/include/bits/types/sigset_t.h" 1 3



# 1 "/usr/riscv64-linux-gnu/include/bits/types/__sigset_t.h" 1 3




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 5 "/usr/riscv64-linux-gnu/include/bits/types/sigset_t.h" 2 3


typedef __sigset_t sigset_t;
# 34 "/usr/riscv64-linux-gnu/include/sys/select.h" 2 3



# 1 "/usr/riscv64-linux-gnu/include/bits/types/struct_timeval.h" 1 3







struct timeval
{




  __time_t tv_sec;
  __suseconds_t tv_usec;

};
# 38 "/usr/riscv64-linux-gnu/include/sys/select.h" 2 3

# 1 "/usr/riscv64-linux-gnu/include/bits/types/struct_timespec.h" 1 3
# 11 "/usr/riscv64-linux-gnu/include/bits/types/struct_timespec.h" 3
struct timespec
{



  __time_t tv_sec;




  __syscall_slong_t tv_nsec;
# 31 "/usr/riscv64-linux-gnu/include/bits/types/struct_timespec.h" 3
};
# 40 "/usr/riscv64-linux-gnu/include/sys/select.h" 2 3



typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 59 "/usr/riscv64-linux-gnu/include/sys/select.h" 3
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 91 "/usr/riscv64-linux-gnu/include/sys/select.h" 3

# 102 "/usr/riscv64-linux-gnu/include/sys/select.h" 3
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 127 "/usr/riscv64-linux-gnu/include/sys/select.h" 3
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 153 "/usr/riscv64-linux-gnu/include/sys/select.h" 3

# 180 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 227 "/usr/riscv64-linux-gnu/include/sys/types.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/pthreadtypes.h" 1 3
# 23 "/usr/riscv64-linux-gnu/include/bits/pthreadtypes.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 1 3
# 44 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/pthreadtypes-arch.h" 1 3
# 45 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 2 3

# 1 "/usr/riscv64-linux-gnu/include/bits/atomic_wide_counter.h" 1 3
# 25 "/usr/riscv64-linux-gnu/include/bits/atomic_wide_counter.h" 3
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
# 47 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 2 3




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
# 76 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/struct_mutex.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/bits/struct_mutex.h" 3
struct __pthread_mutex_s
{
  int __lock ;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;
# 58 "/usr/riscv64-linux-gnu/include/bits/struct_mutex.h" 3
  int __kind;




  int __spins;
  __pthread_list_t __list;
# 74 "/usr/riscv64-linux-gnu/include/bits/struct_mutex.h" 3
};
# 77 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 2 3
# 89 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/struct_rwlock.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/bits/struct_rwlock.h" 3
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  unsigned long int __pad1;
  unsigned long int __pad2;
  unsigned int __flags;
# 55 "/usr/riscv64-linux-gnu/include/bits/struct_rwlock.h" 3
};
# 90 "/usr/riscv64-linux-gnu/include/bits/thread-shared-types.h" 2 3




struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
  int __data ;
} __once_flag;
# 24 "/usr/riscv64-linux-gnu/include/bits/pthreadtypes.h" 2 3



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 228 "/usr/riscv64-linux-gnu/include/sys/types.h" 2 3



# 515 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3






extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));



extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern __uint32_t arc4random (void)
     __attribute__ ((__nothrow__ , __leaf__)) ;


extern void arc4random_buf (void *__buf, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     __attribute__ ((__nothrow__ , __leaf__)) ;




extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;






extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));


extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));


extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));



# 1 "/usr/riscv64-linux-gnu/include/alloca.h" 1 3
# 24 "/usr/riscv64-linux-gnu/include/alloca.h" 3
# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 1 3 4
# 25 "/usr/riscv64-linux-gnu/include/alloca.h" 2 3







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 707 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 786 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 814 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 827 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 849 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 870 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 923 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern int system (const char *__command) ;
# 940 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 960 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 980 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
# 1012 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));





extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));






extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 1099 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 1145 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 1155 "/usr/riscv64-linux-gnu/include/stdlib.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/stdlib-float.h" 1 3
# 1156 "/usr/riscv64-linux-gnu/include/stdlib.h" 2 3
# 1167 "/usr/riscv64-linux-gnu/include/stdlib.h" 3

# 73 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h" 2


# 1 "/usr/riscv64-linux-gnu/include/stdio.h" 1 3
# 28 "/usr/riscv64-linux-gnu/include/stdio.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/libc-header-start.h" 1 3
# 29 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3





# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stddef.h" 1 3 4
# 35 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3


# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 38 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3


# 1 "/usr/riscv64-linux-gnu/include/bits/types/__fpos_t.h" 1 3




# 1 "/usr/riscv64-linux-gnu/include/bits/types/__mbstate_t.h" 1 3
# 13 "/usr/riscv64-linux-gnu/include/bits/types/__mbstate_t.h" 3
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 6 "/usr/riscv64-linux-gnu/include/bits/types/__fpos_t.h" 2 3




typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 41 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/types/__fpos64_t.h" 1 3
# 10 "/usr/riscv64-linux-gnu/include/bits/types/__fpos64_t.h" 3
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 42 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/types/__FILE.h" 1 3



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 43 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/types/FILE.h" 1 3



struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 44 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/types/struct_FILE.h" 1 3
# 35 "/usr/riscv64-linux-gnu/include/bits/types/struct_FILE.h" 3
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
# 45 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3


# 1 "/usr/riscv64-linux-gnu/include/bits/types/cookie_io_functions_t.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/bits/types/cookie_io_functions_t.h" 3
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);







typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);







typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);


typedef int cookie_close_function_t (void *__cookie);






typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
# 48 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3





typedef __gnuc_va_list va_list;
# 85 "/usr/riscv64-linux-gnu/include/stdio.h" 3
typedef __fpos_t fpos_t;
# 129 "/usr/riscv64-linux-gnu/include/stdio.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/stdio_lim.h" 1 3
# 130 "/usr/riscv64-linux-gnu/include/stdio.h" 2 3
# 149 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
# 184 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 194 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 211 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;




extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 228 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));






extern int fflush (FILE *__stream);
# 245 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fflush_unlocked (FILE *__stream);
# 264 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));
# 299 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;





extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 334 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__nonnull__ (1)));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nonnull__ (1)));




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));





extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;




extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 463 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                                __attribute__ ((__nonnull__ (1)));
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 490 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 540 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 575 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fgetc (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getc (FILE *__stream) __attribute__ ((__nonnull__ (1)));





extern int getchar (void);






extern int getc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getchar_unlocked (void);
# 600 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fgetc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 611 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fputc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));





extern int putchar (int __c);
# 627 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fputc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));







extern int putc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream) __attribute__ ((__nonnull__ (1)));


extern int putw (int __w, FILE *__stream) __attribute__ ((__nonnull__ (2)));







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2))) __attribute__ ((__nonnull__ (3)));
# 694 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));







extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));







extern int fputs (const char *__restrict __s, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (2)));





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) __attribute__ ((__nonnull__ (4)));
# 766 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));







extern int fseek (FILE *__stream, long int __off, int __whence)
  __attribute__ ((__nonnull__ (1)));




extern long int ftell (FILE *__stream) __attribute__ ((__nonnull__ (1)));




extern void rewind (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 803 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fseeko (FILE *__stream, __off_t __off, int __whence)
  __attribute__ ((__nonnull__ (1)));




extern __off_t ftello (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 829 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos)
  __attribute__ ((__nonnull__ (1)));




extern int fsetpos (FILE *__stream, const fpos_t *__pos) __attribute__ ((__nonnull__ (1)));
# 860 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern void perror (const char *__s) __attribute__ ((__cold__));




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 897 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int pclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));





extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;






extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
# 941 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 959 "/usr/riscv64-linux-gnu/include/stdio.h" 3
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 983 "/usr/riscv64-linux-gnu/include/stdio.h" 3

# 76 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h" 2


# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/limits.h" 1 3 4
# 34 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/limits.h" 3 4
# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/limits.h" 1 3 4
# 205 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/limits.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/limits.h" 1 3 4
# 26 "/usr/riscv64-linux-gnu/include/limits.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/bits/libc-header-start.h" 1 3 4
# 27 "/usr/riscv64-linux-gnu/include/limits.h" 2 3 4
# 195 "/usr/riscv64-linux-gnu/include/limits.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/bits/posix1_lim.h" 1 3 4
# 27 "/usr/riscv64-linux-gnu/include/bits/posix1_lim.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/bits/wordsize.h" 1 3 4
# 28 "/usr/riscv64-linux-gnu/include/bits/posix1_lim.h" 2 3 4
# 161 "/usr/riscv64-linux-gnu/include/bits/posix1_lim.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/bits/local_lim.h" 1 3 4
# 38 "/usr/riscv64-linux-gnu/include/bits/local_lim.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/linux/limits.h" 1 3 4
# 39 "/usr/riscv64-linux-gnu/include/bits/local_lim.h" 2 3 4
# 81 "/usr/riscv64-linux-gnu/include/bits/local_lim.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/bits/pthread_stack_min-dynamic.h" 1 3 4
# 29 "/usr/riscv64-linux-gnu/include/bits/pthread_stack_min-dynamic.h" 3 4
# 1 "/usr/riscv64-linux-gnu/include/bits/pthread_stack_min.h" 1 3 4
# 30 "/usr/riscv64-linux-gnu/include/bits/pthread_stack_min-dynamic.h" 2 3 4
# 82 "/usr/riscv64-linux-gnu/include/bits/local_lim.h" 2 3 4
# 162 "/usr/riscv64-linux-gnu/include/bits/posix1_lim.h" 2 3 4
# 196 "/usr/riscv64-linux-gnu/include/limits.h" 2 3 4



# 1 "/usr/riscv64-linux-gnu/include/bits/posix2_lim.h" 1 3 4
# 200 "/usr/riscv64-linux-gnu/include/limits.h" 2 3 4
# 206 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/limits.h" 2 3 4
# 8 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/syslimits.h" 2 3 4
# 35 "/usr/lib/gcc-cross/riscv64-linux-gnu/13/include/limits.h" 2 3 4
# 79 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h" 2


# 1 "/usr/riscv64-linux-gnu/include/math.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/math.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/libc-header-start.h" 1 3
# 28 "/usr/riscv64-linux-gnu/include/math.h" 2 3












# 1 "/usr/riscv64-linux-gnu/include/bits/math-vector.h" 1 3
# 27 "/usr/riscv64-linux-gnu/include/bits/math-vector.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/libm-simd-decl-stubs.h" 1 3
# 28 "/usr/riscv64-linux-gnu/include/bits/math-vector.h" 2 3
# 41 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 152 "/usr/riscv64-linux-gnu/include/math.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/flt-eval-method.h" 1 3
# 153 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 163 "/usr/riscv64-linux-gnu/include/math.h" 3
typedef float float_t;
typedef double double_t;
# 204 "/usr/riscv64-linux-gnu/include/math.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/fp-logb.h" 1 3
# 205 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 247 "/usr/riscv64-linux-gnu/include/math.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/fp-fast.h" 1 3
# 248 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 312 "/usr/riscv64-linux-gnu/include/math.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/mathcalls-helper-functions.h" 1 3
# 20 "/usr/riscv64-linux-gnu/include/bits/mathcalls-helper-functions.h" 3
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsig (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignaling (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 313 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 1 3
# 53 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));





 extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 119 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));






 extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));



 extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));




 extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));






extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
# 177 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));






extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 213 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));





 extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));




extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));





extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));







extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));

extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 275 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 293 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
# 435 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
# 314 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 329 "/usr/riscv64-linux-gnu/include/math.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/mathcalls-helper-functions.h" 1 3
# 20 "/usr/riscv64-linux-gnu/include/bits/mathcalls-helper-functions.h" 3
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 330 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 1 3
# 53 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));




 extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));





 extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 119 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));




 extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));






 extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));



 extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));




 extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));






extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
# 177 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));






extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 213 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));





 extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));




extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));





extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));







extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));

extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 275 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 293 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));
# 435 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
# 331 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 398 "/usr/riscv64-linux-gnu/include/math.h" 3
# 1 "/usr/riscv64-linux-gnu/include/bits/mathcalls-helper-functions.h" 1 3
# 20 "/usr/riscv64-linux-gnu/include/bits/mathcalls-helper-functions.h" 3
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 399 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 1 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 1 3
# 53 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));





 extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 119 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
 extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));






 extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



 extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));




 extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));






extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 177 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));






extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 213 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));





 extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));




extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));





extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));







extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));

extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 275 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 293 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
# 435 "/usr/riscv64-linux-gnu/include/bits/mathcalls.h" 3
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
# 400 "/usr/riscv64-linux-gnu/include/math.h" 2 3
# 854 "/usr/riscv64-linux-gnu/include/math.h" 3
extern int signgam;
# 934 "/usr/riscv64-linux-gnu/include/math.h" 3
enum
  {
    FP_NAN =

      0,
    FP_INFINITE =

      1,
    FP_ZERO =

      2,
    FP_SUBNORMAL =

      3,
    FP_NORMAL =

      4
  };
# 1472 "/usr/riscv64-linux-gnu/include/math.h" 3

# 82 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h" 2
# 265 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h"
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/include/amd.h" 1
# 39 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/include/amd.h"

# 39 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/include/amd.h"
int amd_order (
    int n,
    const int Ap [ ],
    const int Ai [ ],
    int P [ ],
    double Control [ ],
    double Info [ ]
) ;

long amd_l_order (
    long n,
    const long Ap [ ],
    const long Ai [ ],
    long P [ ],
    double Control [ ],
    double Info [ ]
) ;
# 258 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/include/amd.h"
int amd_preprocess
(
    int n,
    const int Ap [ ],
    const int Ai [ ],
    int Rp [ ],
    int Ri [ ]
) ;

long amd_l_preprocess
(
    long n,
    const long Ap [ ],
    const long Ai [ ],
    long Rp [ ],
    long Ri [ ]
) ;
# 313 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/include/amd.h"
void amd_defaults (double Control [ ]) ;
void amd_l_defaults (double Control [ ]) ;


void amd_control (double Control [ ]) ;
void amd_l_control (double Control [ ]) ;


void amd_info (double Info [ ]) ;
void amd_l_info (double Info [ ]) ;
# 266 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h" 2





 int amd_valid
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ]
) ;

 int amd_aat
(
    int n,
    const int Ap [ ],
    const int Ai [ ],
    int Len [ ],
    int Tp [ ],
    double Info [ ]
) ;

 void amd_1
(
    int n,
    const int Ap [ ],
    const int Ai [ ],
    int P [ ],
    int Pinv [ ],
    int Len [ ],
    int slen,
    int S [ ],
    double Control [ ],
    double Info [ ]
) ;

 void amd_2 (
    int n,
    int Pe [ ],
    int Iw [ ],
    int Len [ ],
    int iwlen,
    int pfree,
    int Nv [ ],
    int Next [ ],
    int Last [ ],
    int Head [ ],
    int Elen [ ],
    int Degree [ ],
    int W [ ],
    double Control [ ],
    double Info [ ]
) ;

 void amd_postorder
(
    int nn,
    int Parent [ ],
    int Npiv [ ],
    int Fsize [ ],
    int Order [ ],
    int Child [ ],
    int Sibling [ ],
    int Stack [ ]
) ;

 int amd_post_tree
(
    int root,
    int k,
    int Child [ ],
    const int Sibling [ ],
    int Order [ ],
    int Stack [ ]



) ;

 void amd_wpreprocess
(
    int n,
    const int Ap [ ],
    const int Ai [ ],
    int Rp [ ],
    int Ri [ ],
    int W [ ],
    int Flag [ ]
) ;

 int amd_preprocess_valid
(
    int n,
    const int Ap [ ],
    const int Ai [ ]
) ;







# 1 "/usr/riscv64-linux-gnu/include/assert.h" 1 3
# 371 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/../amd/amd_internal.h" 2
# 89 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 2





# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_version.h" 1
# 95 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 2





# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_config.h" 1



# 1 "/home/acer/risc-v-hpc/ports/elmer/build-riscv64/umfpack/src/umfpack/../../config.h" 1
# 5 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_config.h" 2
# 101 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 2





# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 1
# 37 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h"
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_symbolic.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_symbolic.h"
int umfpack_di_symbolic
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;

long umfpack_dl_symbolic
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;

int umfpack_zi_symbolic
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ], const double Az [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;

long umfpack_zl_symbolic
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ], const double Az [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;
# 38 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_numeric.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_numeric.h"
int umfpack_di_numeric
(
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    void *Symbolic,
    void **Numeric,
    const double Control [20],
    double Info [90]
) ;

long umfpack_dl_numeric
(
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ],
    void *Symbolic,
    void **Numeric,
    const double Control [20],
    double Info [90]
) ;

int umfpack_zi_numeric
(
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ], const double Az [ ],
    void *Symbolic,
    void **Numeric,
    const double Control [20],
    double Info [90]
) ;

long umfpack_zl_numeric
(
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ], const double Az [ ],
    void *Symbolic,
    void **Numeric,
    const double Control [20],
    double Info [90]
) ;
# 39 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_solve.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_solve.h"
int umfpack_di_solve
(
    int sys,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    double X [ ],
    const double B [ ],
    void *Numeric,
    const double Control [20],
    double Info [90]
) ;

long umfpack_dl_solve
(
    long sys,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ],
    double X [ ],
    const double B [ ],
    void *Numeric,
    const double Control [20],
    double Info [90]
) ;

int umfpack_zi_solve
(
    int sys,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ], const double Az [ ],
    double Xx [ ], double Xz [ ],
    const double Bx [ ], const double Bz [ ],
    void *Numeric,
    const double Control [20],
    double Info [90]
) ;

long umfpack_zl_solve
(
    long sys,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ], const double Az [ ],
    double Xx [ ], double Xz [ ],
    const double Bx [ ], const double Bz [ ],
    void *Numeric,
    const double Control [20],
    double Info [90]
) ;
# 40 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_free_symbolic.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_free_symbolic.h"
void umfpack_di_free_symbolic
(
    void **Symbolic
) ;

void umfpack_dl_free_symbolic
(
    void **Symbolic
) ;

void umfpack_zi_free_symbolic
(
    void **Symbolic
) ;

void umfpack_zl_free_symbolic
(
    void **Symbolic
) ;
# 41 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_free_numeric.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_free_numeric.h"
void umfpack_di_free_numeric
(
    void **Numeric
) ;

void umfpack_dl_free_numeric
(
    void **Numeric
) ;

void umfpack_zi_free_numeric
(
    void **Numeric
) ;

void umfpack_zl_free_numeric
(
    void **Numeric
) ;
# 42 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2


# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_defaults.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_defaults.h"
void umfpack_di_defaults
(
    double Control [20]
) ;

void umfpack_dl_defaults
(
    double Control [20]
) ;

void umfpack_zi_defaults
(
    double Control [20]
) ;

void umfpack_zl_defaults
(
    double Control [20]
) ;
# 45 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_qsymbolic.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_qsymbolic.h"
int umfpack_di_qsymbolic
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    const int Qinit [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;

long umfpack_dl_qsymbolic
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ],
    const long Qinit [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;

int umfpack_zi_qsymbolic
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ], const double Az [ ],
    const int Qinit [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;

long umfpack_zl_qsymbolic
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ], const double Az [ ],
    const long Qinit [ ],
    void **Symbolic,
    const double Control [20],
    double Info [90]
) ;
# 46 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_wsolve.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_wsolve.h"
int umfpack_di_wsolve
(
    int sys,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    double X [ ],
    const double B [ ],
    void *Numeric,
    const double Control [20],
    double Info [90],
    int Wi [ ],
    double W [ ]
) ;

long umfpack_dl_wsolve
(
    long sys,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ],
    double X [ ],
    const double B [ ],
    void *Numeric,
    const double Control [20],
    double Info [90],
    long Wi [ ],
    double W [ ]
) ;

int umfpack_zi_wsolve
(
    int sys,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ], const double Az [ ],
    double Xx [ ], double Xz [ ],
    const double Bx [ ], const double Bz [ ],
    void *Numeric,
    const double Control [20],
    double Info [90],
    int Wi [ ],
    double W [ ]
) ;

long umfpack_zl_wsolve
(
    long sys,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ], const double Az [ ],
    double Xx [ ], double Xz [ ],
    const double Bx [ ], const double Bz [ ],
    void *Numeric,
    const double Control [20],
    double Info [90],
    long Wi [ ],
    double W [ ]
) ;
# 47 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2


# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_triplet_to_col.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_triplet_to_col.h"
int umfpack_di_triplet_to_col
(
    int n_row,
    int n_col,
    int nz,
    const int Ti [ ],
    const int Tj [ ],
    const double Tx [ ],
    int Ap [ ],
    int Ai [ ],
    double Ax [ ],
    int Map [ ]
) ;

long umfpack_dl_triplet_to_col
(
    long n_row,
    long n_col,
    long nz,
    const long Ti [ ],
    const long Tj [ ],
    const double Tx [ ],
    long Ap [ ],
    long Ai [ ],
    double Ax [ ],
    long Map [ ]
) ;

int umfpack_zi_triplet_to_col
(
    int n_row,
    int n_col,
    int nz,
    const int Ti [ ],
    const int Tj [ ],
    const double Tx [ ], const double Tz [ ],
    int Ap [ ],
    int Ai [ ],
    double Ax [ ], double Az [ ],
    int Map [ ]
) ;

long umfpack_zl_triplet_to_col
(
    long n_row,
    long n_col,
    long nz,
    const long Ti [ ],
    const long Tj [ ],
    const double Tx [ ], const double Tz [ ],
    long Ap [ ],
    long Ai [ ],
    double Ax [ ], double Az [ ],
    long Map [ ]
) ;
# 50 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_col_to_triplet.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_col_to_triplet.h"
int umfpack_di_col_to_triplet
(
    int n_col,
    const int Ap [ ],
    int Tj [ ]
) ;

long umfpack_dl_col_to_triplet
(
    long n_col,
    const long Ap [ ],
    long Tj [ ]
) ;

int umfpack_zi_col_to_triplet
(
    int n_col,
    const int Ap [ ],
    int Tj [ ]
) ;

long umfpack_zl_col_to_triplet
(
    long n_col,
    const long Ap [ ],
    long Tj [ ]
) ;
# 51 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_transpose.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_transpose.h"
int umfpack_di_transpose
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    const int P [ ],
    const int Q [ ],
    int Rp [ ],
    int Ri [ ],
    double Rx [ ]
) ;

long umfpack_dl_transpose
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ],
    const long P [ ],
    const long Q [ ],
    long Rp [ ],
    long Ri [ ],
    double Rx [ ]
) ;

int umfpack_zi_transpose
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ], const double Az [ ],
    const int P [ ],
    const int Q [ ],
    int Rp [ ],
    int Ri [ ],
    double Rx [ ], double Rz [ ],
    int do_conjugate
) ;

long umfpack_zl_transpose
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ], const double Az [ ],
    const long P [ ],
    const long Q [ ],
    long Rp [ ],
    long Ri [ ],
    double Rx [ ], double Rz [ ],
    long do_conjugate
) ;
# 52 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_scale.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_scale.h"
int umfpack_di_scale
(
    double X [ ],
    const double B [ ],
    void *Numeric
) ;

long umfpack_dl_scale
(
    double X [ ],
    const double B [ ],
    void *Numeric
) ;

int umfpack_zi_scale
(
    double Xx [ ], double Xz [ ],
    const double Bx [ ], const double Bz [ ],
    void *Numeric
) ;

long umfpack_zl_scale
(
    double Xx [ ], double Xz [ ],
    const double Bx [ ], const double Bz [ ],
    void *Numeric
) ;
# 53 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2


# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_lunz.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_lunz.h"
int umfpack_di_get_lunz
(
    int *lnz,
    int *unz,
    int *n_row,
    int *n_col,
    int *nz_udiag,
    void *Numeric
) ;

long umfpack_dl_get_lunz
(
    long *lnz,
    long *unz,
    long *n_row,
    long *n_col,
    long *nz_udiag,
    void *Numeric
) ;

int umfpack_zi_get_lunz
(
    int *lnz,
    int *unz,
    int *n_row,
    int *n_col,
    int *nz_udiag,
    void *Numeric
) ;

long umfpack_zl_get_lunz
(
    long *lnz,
    long *unz,
    long *n_row,
    long *n_col,
    long *nz_udiag,
    void *Numeric
) ;
# 56 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_numeric.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_numeric.h"
int umfpack_di_get_numeric
(
    int Lp [ ],
    int Lj [ ],
    double Lx [ ],
    int Up [ ],
    int Ui [ ],
    double Ux [ ],
    int P [ ],
    int Q [ ],
    double Dx [ ],
    int *do_recip,
    double Rs [ ],
    void *Numeric
) ;

long umfpack_dl_get_numeric
(
    long Lp [ ],
    long Lj [ ],
    double Lx [ ],
    long Up [ ],
    long Ui [ ],
    double Ux [ ],
    long P [ ],
    long Q [ ],
    double Dx [ ],
    long *do_recip,
    double Rs [ ],
    void *Numeric
) ;

int umfpack_zi_get_numeric
(
    int Lp [ ],
    int Lj [ ],
    double Lx [ ], double Lz [ ],
    int Up [ ],
    int Ui [ ],
    double Ux [ ], double Uz [ ],
    int P [ ],
    int Q [ ],
    double Dx [ ], double Dz [ ],
    int *do_recip,
    double Rs [ ],
    void *Numeric
) ;

long umfpack_zl_get_numeric
(
    long Lp [ ],
    long Lj [ ],
    double Lx [ ], double Lz [ ],
    long Up [ ],
    long Ui [ ],
    double Ux [ ], double Uz [ ],
    long P [ ],
    long Q [ ],
    double Dx [ ], double Dz [ ],
    long *do_recip,
    double Rs [ ],
    void *Numeric
) ;
# 57 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_symbolic.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_symbolic.h"
int umfpack_di_get_symbolic
(
    int *n_row,
    int *n_col,
    int *n1,
    int *nz,
    int *nfr,
    int *nchains,
    int P [ ],
    int Q [ ],
    int Front_npivcol [ ],
    int Front_parent [ ],
    int Front_1strow [ ],
    int Front_leftmostdesc [ ],
    int Chain_start [ ],
    int Chain_maxrows [ ],
    int Chain_maxcols [ ],
    void *Symbolic
) ;

long umfpack_dl_get_symbolic
(
    long *n_row,
    long *n_col,
    long *n1,
    long *nz,
    long *nfr,
    long *nchains,
    long P [ ],
    long Q [ ],
    long Front_npivcol [ ],
    long Front_parent [ ],
    long Front_1strow [ ],
    long Front_leftmostdesc [ ],
    long Chain_start [ ],
    long Chain_maxrows [ ],
    long Chain_maxcols [ ],
    void *Symbolic
) ;

int umfpack_zi_get_symbolic
(
    int *n_row,
    int *n_col,
    int *n1,
    int *nz,
    int *nfr,
    int *nchains,
    int P [ ],
    int Q [ ],
    int Front_npivcol [ ],
    int Front_parent [ ],
    int Front_1strow [ ],
    int Front_leftmostdesc [ ],
    int Chain_start [ ],
    int Chain_maxrows [ ],
    int Chain_maxcols [ ],
    void *Symbolic
) ;

long umfpack_zl_get_symbolic
(
    long *n_row,
    long *n_col,
    long *n1,
    long *nz,
    long *nfr,
    long *nchains,
    long P [ ],
    long Q [ ],
    long Front_npivcol [ ],
    long Front_parent [ ],
    long Front_1strow [ ],
    long Front_leftmostdesc [ ],
    long Chain_start [ ],
    long Chain_maxrows [ ],
    long Chain_maxcols [ ],
    void *Symbolic
) ;
# 58 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_save_numeric.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_save_numeric.h"
int umfpack_di_save_numeric
(
    void *Numeric,
    char *filename
) ;

long umfpack_dl_save_numeric
(
    void *Numeric,
    char *filename
) ;

int umfpack_zi_save_numeric
(
    void *Numeric,
    char *filename
) ;

long umfpack_zl_save_numeric
(
    void *Numeric,
    char *filename
) ;
# 59 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_load_numeric.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_load_numeric.h"
int umfpack_di_load_numeric
(
    void **Numeric,
    char *filename
) ;

long umfpack_dl_load_numeric
(
    void **Numeric,
    char *filename
) ;

int umfpack_zi_load_numeric
(
    void **Numeric,
    char *filename
) ;

long umfpack_zl_load_numeric
(
    void **Numeric,
    char *filename
) ;
# 60 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_save_symbolic.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_save_symbolic.h"
int umfpack_di_save_symbolic
(
    void *Symbolic,
    char *filename
) ;

long umfpack_dl_save_symbolic
(
    void *Symbolic,
    char *filename
) ;

int umfpack_zi_save_symbolic
(
    void *Symbolic,
    char *filename
) ;

long umfpack_zl_save_symbolic
(
    void *Symbolic,
    char *filename
) ;
# 61 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_load_symbolic.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_load_symbolic.h"
int umfpack_di_load_symbolic
(
    void **Symbolic,
    char *filename
) ;

long umfpack_dl_load_symbolic
(
    void **Symbolic,
    char *filename
) ;

int umfpack_zi_load_symbolic
(
    void **Symbolic,
    char *filename
) ;

long umfpack_zl_load_symbolic
(
    void **Symbolic,
    char *filename
) ;
# 62 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_determinant.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_get_determinant.h"
int umfpack_di_get_determinant
(
    double *Mx,
    double *Ex,
    void *NumericHandle,
    double User_Info [90]
) ;

long umfpack_dl_get_determinant
(
    double *Mx,
    double *Ex,
    void *NumericHandle,
    double User_Info [90]
) ;

int umfpack_zi_get_determinant
(
    double *Mx,
    double *Mz,
    double *Ex,
    void *NumericHandle,
    double User_Info [90]
) ;

long umfpack_zl_get_determinant
(
    double *Mx,
    double *Mz,
    double *Ex,
    void *NumericHandle,
    double User_Info [90]
) ;
# 63 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2


# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_status.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_status.h"
void umfpack_di_report_status
(
    const double Control [20],
    int status
) ;

void umfpack_dl_report_status
(
    const double Control [20],
    long status
) ;

void umfpack_zi_report_status
(
    const double Control [20],
    int status
) ;

void umfpack_zl_report_status
(
    const double Control [20],
    long status
) ;
# 66 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_info.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_info.h"
void umfpack_di_report_info
(
    const double Control [20],
    const double Info [90]
) ;

void umfpack_dl_report_info
(
    const double Control [20],
    const double Info [90]
) ;

void umfpack_zi_report_info
(
    const double Control [20],
    const double Info [90]
) ;

void umfpack_zl_report_info
(
    const double Control [20],
    const double Info [90]
) ;
# 67 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_control.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_control.h"
void umfpack_di_report_control
(
    const double Control [20]
) ;

void umfpack_dl_report_control
(
    const double Control [20]
) ;

void umfpack_zi_report_control
(
    const double Control [20]
) ;

void umfpack_zl_report_control
(
    const double Control [20]
) ;
# 68 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_matrix.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_matrix.h"
int umfpack_di_report_matrix
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    int col_form,
    const double Control [20]
) ;

long umfpack_dl_report_matrix
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ],
    long col_form,
    const double Control [20]
) ;

int umfpack_zi_report_matrix
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ], const double Az [ ],
    int col_form,
    const double Control [20]
) ;

long umfpack_zl_report_matrix
(
    long n_row,
    long n_col,
    const long Ap [ ],
    const long Ai [ ],
    const double Ax [ ], const double Az [ ],
    long col_form,
    const double Control [20]
) ;
# 69 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_triplet.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_triplet.h"
int umfpack_di_report_triplet
(
    int n_row,
    int n_col,
    int nz,
    const int Ti [ ],
    const int Tj [ ],
    const double Tx [ ],
    const double Control [20]
) ;

long umfpack_dl_report_triplet
(
    long n_row,
    long n_col,
    long nz,
    const long Ti [ ],
    const long Tj [ ],
    const double Tx [ ],
    const double Control [20]
) ;

int umfpack_zi_report_triplet
(
    int n_row,
    int n_col,
    int nz,
    const int Ti [ ],
    const int Tj [ ],
    const double Tx [ ], const double Tz [ ],
    const double Control [20]
) ;

long umfpack_zl_report_triplet
(
    long n_row,
    long n_col,
    long nz,
    const long Ti [ ],
    const long Tj [ ],
    const double Tx [ ], const double Tz [ ],
    const double Control [20]
) ;
# 70 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_vector.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_vector.h"
int umfpack_di_report_vector
(
    int n,
    const double X [ ],
    const double Control [20]
) ;

long umfpack_dl_report_vector
(
    long n,
    const double X [ ],
    const double Control [20]
) ;

int umfpack_zi_report_vector
(
    int n,
    const double Xx [ ], const double Xz [ ],
    const double Control [20]
) ;

long umfpack_zl_report_vector
(
    long n,
    const double Xx [ ], const double Xz [ ],
    const double Control [20]
) ;
# 71 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_symbolic.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_symbolic.h"
int umfpack_di_report_symbolic
(
    void *Symbolic,
    const double Control [20]
) ;

long umfpack_dl_report_symbolic
(
    void *Symbolic,
    const double Control [20]
) ;

int umfpack_zi_report_symbolic
(
    void *Symbolic,
    const double Control [20]
) ;

long umfpack_zl_report_symbolic
(
    void *Symbolic,
    const double Control [20]
) ;
# 72 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_numeric.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_numeric.h"
int umfpack_di_report_numeric
(
    void *Numeric,
    const double Control [20]
) ;

long umfpack_dl_report_numeric
(
    void *Numeric,
    const double Control [20]
) ;

int umfpack_zi_report_numeric
(
    void *Numeric,
    const double Control [20]
) ;

long umfpack_zl_report_numeric
(
    void *Numeric,
    const double Control [20]
) ;
# 73 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_perm.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_report_perm.h"
int umfpack_di_report_perm
(
    int np,
    const int Perm [ ],
    const double Control [20]
) ;

long umfpack_dl_report_perm
(
    long np,
    const long Perm [ ],
    const double Control [20]
) ;

int umfpack_zi_report_perm
(
    int np,
    const int Perm [ ],
    const double Control [20]
) ;

long umfpack_zl_report_perm
(
    long np,
    const long Perm [ ],
    const double Control [20]
) ;
# 74 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2


# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_timer.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_timer.h"
double umfpack_timer ( void ) ;
# 77 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_tictoc.h" 1
# 11 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack_tictoc.h"
void umfpack_tic (double stats [2]) ;

void umfpack_toc (double stats [2]) ;
# 78 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umfpack.h" 2
# 107 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 2
# 249 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
typedef double Align ;
# 265 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
union Unit_union
{
    struct
    {
 int
     size,


     prevsize ;



    } header ;
    Align xxxxxx ;
} ;

typedef union Unit_union Unit ;
# 319 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
typedef struct
{
    double
 flops,
 relpt,
 relpt2,
 droptol,
 alloc_init,
 front_alloc_init,
 rsmin,
 rsmax,
 min_udiag,
 max_udiag,
 rcond ;

    int
 scale ;

    int valid ;


    Unit
 *Memory ;
    int
 ihead,
 itail,

 ibig,
 size ;

    int
 *Rperm,


 *Cperm,



 *Upos,
 *Lpos,
 *Lip,
 *Lilen,
 *Uip,
 *Uilen,
 *Upattern ;

    int
 ulen,
 npiv,
 nnzpiv ;

    double
 *D ;

    int do_recip ;
    double *Rs ;



    int
 n_row, n_col,
 n1 ;


    int
 tail_usage,

 init_usage,
 max_usage,

 ngarbage,
 nrealloc,
 ncostly,
 isize,
 nLentries,
 nUentries,

 lnz,
 all_lnz,
 unz,
 all_unz,
 maxfrsize ;

    int maxnrows, maxncols ;

} NumericType ;







typedef struct
{

    int
 e,
 f ;

} Tuple ;
# 431 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
typedef struct
{
    int

 cdeg,
 rdeg,
 nrowsleft,
 ncolsleft,
 nrows,
 ncols,
 next ;
# 452 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
} Element ;
# 495 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
typedef struct
{
# 522 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
    int *E ;






    double *Wx, *Wy ;

    int
 *Wp,
 *Wrp,
 *Wm,
 *Wio,
 *Woi,
 *Woo,
 *Wrow,
 *NewRows,
 *NewCols ;



    int
 *Lpattern,
 *Upattern,
 ulen, llen ;

    int
 *Diagonal_map,
 *Diagonal_imap ;



    int
 n_row, n_col,
 nz,
 n1,
 elen,
 npiv,
 ndiscard,
 Wrpflag,
 nel,
 noff_diagonal,
 prior_element,
 rdeg0, cdeg0,
 rrdeg, ccdeg,
 Candidates [128],
 nCandidates,
 ksuper,
 firstsuper,
 jsuper,
 ncand,
 nextcand,
 lo,
 hi,
 pivrow,
 pivcol,
 do_extend,
 do_update,
 nforced,
 any_skip,
 do_scan2row,
 do_scan2col,
 do_grow,
 pivot_case,
 frontid,
 nfr ;





    int
 *Front_new1strow ;





    int Pivrow [64],
 Pivcol [64] ;

    double
 *Flublock,
 *Flblock,
 *Fublock,
 *Fcblock ;

    int
 *Frows,

 *Fcols,

 *Frpos,


 *Fcpos,



 fnrows,
 fncols,
 fnr_curr,
 fnc_curr,
 fcurr_size,
 fnrows_max,
 fncols_max,
 nb,
 fnpiv,
 fnzeros,
 fscan_row,
 fscan_col,
 fnrows_new,
 fncols_new,
 pivrow_in_front,
 pivcol_in_front ;
# 669 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
} WorkType ;
# 681 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h"
typedef struct
{

    double
 num_mem_usage_est,
 num_mem_size_est,
 peak_sym_usage,
 sym,
 dnum_mem_init_usage,
 amd_lunz,
 lunz_bound ;

    int valid,
 max_nchains,
 nchains,
 *Chain_start,
 *Chain_maxrows,
 *Chain_maxcols,
 maxnrows,
 maxncols,
 *Front_npivcol,
 *Front_1strow,
 *Front_leftmostdesc,
 *Front_parent,
 *Cperm_init,
 *Rperm_init,
 *Cdeg, *Rdeg,
 *Esize,
 dense_row_threshold,
 n1,
 nempty,
 *Diagonal_map,
 esize,
 nfr,
 n_row, n_col,
 nz,
 nb,
 num_mem_init_usage,
 nempty_row, nempty_col,

 strategy,
 ordering,
 fixQ,
 prefer_diagonal,
 nzaat,
 nzdiag,
 amd_dmax ;

} SymbolicType ;






# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_dump.h" 1
# 737 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_internal.h" 2
# 23 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_symbolic_usage.h" 1






 double umfdi_symbolic_usage
(
    int n_row,
    int n_col,
    int nchains,
    int nfr,
    int esize,
    int prefer_diagonal
) ;
# 24 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_colamd.h" 1
# 114 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_colamd.h"
typedef struct Colamd_Col_struct
{
    int start ;

    int length ;
    union
    {
 int thickness ;

 int parent ;

    } shared1 ;
    union
    {
 int score ;
 int order ;
    } shared2 ;
    union
    {
 int headhash ;

 int hash ;
 int prev ;

    } shared3 ;
    union
    {
 int degree_next ;
 int hash_next ;
    } shared4 ;



    int nextcol ;
    int lastcol ;


} Colamd_Col ;

typedef struct Colamd_Row_struct
{
    int start ;
    int length ;
    union
    {
 int degree ;
 int p ;
    } shared1 ;
    union
    {
 int mark ;
 int first_column ;
    } shared2 ;



    int thickness ;

    int front ;




} Colamd_Row ;
# 223 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_colamd.h"
void umf_i_colamd_set_defaults
(
    double knobs [20]
) ;

int umf_i_colamd
(
    int n_row,
    int n_col,
    int Alen,
    int A [],
    int p [],
    double knobs [20],
    int stats [20]


    , int Front_npivcol [ ]
    , int Front_nrows [ ]
    , int Front_ncols [ ]
    , int Front_parent [ ]
    , int Front_cols [ ]
    , int *p_nfr
    , int InFront [ ]

) ;
# 25 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_set_stats.h" 1






 void umf_i_set_stats
(
    double Info [ ],
    SymbolicType *Symbolic,
    double max_usage,
    double num_mem_size,
    double flops,
    double lnz,
    double unz,
    double maxfrsize,
    double ulen,
    double npiv,
    double maxnrows,
    double maxncols,
    int scale,
    int prefer_diagonal,
    int what
) ;
# 26 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_analyze.h" 1






 int umf_i_analyze
(
    int n_row,
    int n_col,
    int Ai [ ],
    int Ap [ ],
    int Up [ ],
    int fixQ,
    int Front_ncols [ ],
    int W [ ],
    int Link [ ],
    int Front_nrows [ ],
    int Front_npivcol [ ],
    int Front_parent [ ],
    int *nfr_out,
    int *p_ncompactions
) ;
# 27 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_transpose.h" 1






 int umfdi_transpose
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],
    const int P [ ],
    const int Q [ ],
    int nq,
    int Rp [ ],
    int Ri [ ],
    double Rx [ ],
    int W [ ],
    int check





) ;
# 28 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_is_permutation.h" 1






 int umf_i_is_permutation
(
    const int P [ ],
    int W [ ],
    int n,
    int r
) ;
# 29 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_malloc.h" 1
# 14 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_malloc.h"
 void *umf_i_malloc
(
    int n_objects,
    size_t size_of_object
) ;
# 30 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_free.h" 1






 void *umf_i_free
(
    void *p
) ;
# 31 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_2by2.h" 1






 void umfdi_2by2
(
    int n,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],



    double tol,
    int scale,
    int Cperm1 [ ],



    int InvRperm [ ],
    int n1,
    int nempty,
    int Degree [ ],
    int P [ ],
    int *p_nweak,
    int *p_nmatched,
    int Ri [ ],
    int Rp [ ],
    double Rs [ ],
    int Head [ ],
    int Next [ ],
    int Si [ ],
    int Sp [ ]
) ;
# 32 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2
# 1 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/include/umf_singletons.h" 1






 int umf_i_singletons
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const int Quser [ ],
    int strategy,
    int Cdeg [ ],
    int Cperm [ ],
    int Rdeg [ ],
    int Rperm [ ],
    int InvRperm [ ],
    int *n1,
    int *n1c,
    int *n1r,
    int *nempty_col,
    int *nempty_row,
    int *is_sym,
    int *max_rdeg,
    int Rp [ ],
    int Ri [ ],
    int W [ ],
    int Next [ ]
) ;
# 33 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c" 2

typedef struct
{
    int *Front_npivcol ;
    int *Front_nrows ;
    int *Front_ncols ;
    int *Front_parent ;
    int *Front_cols ;
    int *InFront ;
    int *Ci ;
    int *Cperm1 ;
    int *Rperm1 ;
    int *InvRperm1 ;
    int *Si ;
    int *Sp ;
    double *Rs ;
    int *Rperm_2by2 ;

} SWType ;

static void free_work
(
    SWType *SW
) ;

static void error
(
    SymbolicType **Symbolic,
    SWType *SW
) ;
# 89 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
static void do_amd
(
    int n,
    const int Ap [ ],
    const int Ai [ ],
    int Q [ ],
    int Qinv [ ],
    int Sdeg [ ],
    int Clen,
    int Ci [ ],
    double amd_Control [ ],
    double amd_Info [ ],
    SymbolicType *Symbolic,
    double Info [ ]
)
{

    if (n == 0)
    {
 Symbolic->amd_dmax = 0 ;
 Symbolic->amd_lunz = 0 ;
 Info [36] = 0 ;
 Info [37] = 0 ;
 Info [39] = 0 ;
 Info [38] = 0 ;
    }
    else
    {
 amd_1 (n, Ap, Ai, Q, Qinv, Sdeg, Clen, Ci, amd_Control, amd_Info) ;


 Symbolic->amd_dmax = amd_Info [13] ;
 Symbolic->amd_lunz = 2 * amd_Info [9] + n ;
 Info [36] = Symbolic->amd_lunz ;
 Info [37] = 1. * amd_Info [10] +
     2. * amd_Info [12] ;
 Info [39] = Symbolic->amd_dmax ;
 Info [38] = amd_Info [6] ;
 Info [12] += amd_Info [8] ;
    }
}
# 139 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
static int prune_singletons
(
    int n1,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],



    int Cperm1 [ ],
    int InvRperm1 [ ],
    int Si [ ],
    int Sp [ ]




)
{
    int row, k, pp, p, oldcol, newcol, newrow, nzdiag, do_nzdiag ;




    nzdiag = 0 ;
    do_nzdiag = (Ax != (double *) 0) ;
# 178 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    pp = 0 ;
    for (k = n1 ; k < n_col ; k++)
    {
 oldcol = Cperm1 [k] ;
 newcol = k - n1 ;

                             ;
 Sp [newcol] = pp ;
 for (p = Ap [oldcol] ; p < Ap [oldcol+1] ; p++)
 {
     row = Ai [p] ;
     ;
     ;
     newrow = InvRperm1 [row] - n1 ;
     ;
     if (newrow >= 0)
     {
  ;
  Si [pp++] = newrow ;
  if (do_nzdiag)
  {



      if (newrow == newcol)
      {
# 223 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
   if (((Ax [p]) != 0.))
   {
       nzdiag++ ;
   }

      }
  }
     }
     ;
 }
    }
    Sp [n_col - n1] = pp ;

    return (nzdiag) ;
}





static void combine_ordering
(
    int n1,
    int nempty_col,
    int n_col,
    int Cperm_init [ ],
    int Cperm1 [ ],
    int Qinv [ ]
)
{
    int k, oldcol, newcol, knew ;
# 262 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    for (k = 0 ; k < n1 ; k++)
    {
 ;
 Cperm_init [k] = Cperm1 [k] ;
    }
    for (k = n1 ; k < n_col - nempty_col ; k++)
    {

 oldcol = Cperm1 [k] ;
 newcol = k - n1 ;
 knew = Qinv [newcol] ;
 knew += n1 ;

                               ;
 ;
 ;
 Cperm_init [knew] = oldcol ;
    }
    for (k = n_col - nempty_col ; k < n_col ; k++)
    {
 Cperm_init [k] = Cperm1 [k] ;
    }
# 292 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
}





 int umfpack_di_qsymbolic
(
    int n_row,
    int n_col,
    const int Ap [ ],
    const int Ai [ ],
    const double Ax [ ],



    const int Quser [ ],
    void **SymbolicHandle,
    const double Control [20],
    double User_Info [90]
)
{





    double knobs [20], flops, f, r, c, force_fixQ,
 Info2 [90], drow, dcol, dtail_usage, dlf, duf, dmax_usage,
 dhead_usage, dlnz, dunz, dmaxfrsize, dClen, dClen_analyze, sym,
 amd_Info [20], dClen_amd, dr, dc, cr, cc, cp,
 amd_Control [5], stats [2], tol ;
    double *Info ;
    int i, nz, j, newj, status, f1, f2, maxnrows, maxncols, nfr, col,
 nchains, maxrows, maxcols, p, nb, nn, *Chain_start, *Chain_maxrows,
 *Chain_maxcols, *Front_npivcol, *Ci, Clen, colamd_stats [20],
 fpiv, n_inner, child, parent, *Link, row, *Front_parent,
 analyze_compactions, k, chain, is_sym, *Si, *Sp, n2, do_UMF_analyze,
 fpivcol, fallrows, fallcols, *InFront, *F1, snz, *Front_1strow, f1rows,
 kk, *Cperm_init, *Rperm_init, newrow, *InvRperm1, *Front_leftmostdesc,
 Clen_analyze, strategy, Clen_amd, fixQ, prefer_diagonal, nzdiag, nzaat,
 *Wq, *Sdeg, *Fr_npivcol, nempty, *Fr_nrows, *Fr_ncols, *Fr_parent,
 *Fr_cols, nempty_row, nempty_col, user_auto_strategy, fail, max_rdeg,
 head_usage, tail_usage, lnz, unz, esize, *Esize, rdeg, *Cdeg, *Rdeg,
 *Cperm1, *Rperm1, n1, oldcol, newcol, n1c, n1r, *Rperm_2by2, oldrow,
 dense_row_threshold, tlen, aggressive, scale, *Rp, *Ri ;

    SymbolicType *Symbolic ;
    SWType SWspace, *SW ;
# 354 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    umfpack_tic (stats) ;





    drow = ((Control != (double *) 0) ? (((Control [1]) != (Control [1])) ? 0.2 : Control [1]) : 0.2) ;
    dcol = ((Control != (double *) 0) ? (((Control [2]) != (Control [2])) ? 0.2 : Control [2]) : 0.2) ;
    nb = ((Control != (double *) 0) ? (((Control [4]) != (Control [4])) ? 32 : Control [4]) : 32) ;
    strategy = ((Control != (double *) 0) ? (((Control [5]) != (Control [5])) ? 0 : Control [5]) : 0) ;
    tol = ((Control != (double *) 0) ? (((Control [12]) != (Control [12])) ? 0.01 : Control [12]) : 0.01) ;
    scale = ((Control != (double *) 0) ? (((Control [16]) != (Control [16])) ? 1 : Control [16]) : 1) ;
    force_fixQ = ((Control != (double *) 0) ? (((Control [13]) != (Control [13])) ? 0 : Control [13]) : 0) ;
    amd_defaults (amd_Control) ;
    amd_Control [0] =
 ((Control != (double *) 0) ? (((Control [14]) != (Control [14])) ? 10.0 : Control [14]) : 10.0) ;
    aggressive =
 (((Control != (double *) 0) ? (((Control [19]) != (Control [19])) ? 1 : Control [19]) : 1) != 0) ;
    amd_Control [1] = aggressive ;

    nb = (((2) > (nb)) ? (2) : (nb)) ;
    nb = (((nb) < (64)) ? (nb) : (64)) ;
    ;
    if (nb % 2 == 1) nb++ ;
   
              ;

    tol = (((0.0) > ((((tol) < (1.0)) ? (tol) : (1.0)))) ? (0.0) : ((((tol) < (1.0)) ? (tol) : (1.0)))) ;
    if (scale != 0 && scale != 2)
    {
 scale = 1 ;
    }

    if (User_Info != (double *) 0)
    {

 Info = User_Info ;
    }
    else
    {

 Info = Info2 ;
    }

    for (i = 0 ; i < 90 ; i++)
    {
 Info [i] = (-1) ;
    }

    nn = (((n_row) > (n_col)) ? (n_row) : (n_col)) ;
    n_inner = (((n_row) < (n_col)) ? (n_row) : (n_col)) ;

    Info [0] = (0) ;
    Info [1] = n_row ;
    Info [16] = n_col ;
    Info [3] = (double) (sizeof (Unit)) ;
    Info [4] = (double) (sizeof (int)) ;
    Info [5] = (double) (sizeof (long)) ;
    Info [6] = (double) (sizeof (void *)) ;
    Info [7] = (double) (sizeof (double)) ;
    Info [12] = 0 ;

    if (!Ai || !Ap || !SymbolicHandle)
    {
 Info [0] = (-5) ;
 return ((-5)) ;
    }

    *SymbolicHandle = (void *) 0 ;

    if (n_row <= 0 || n_col <= 0)
    {
 Info [0] = (-6) ;
 return ((-6)) ;
    }

    nz = Ap [n_col] ;
    ;
    Info [2] = nz ;
    if (nz < 0)
    {
 Info [0] = (-8) ;
 return ((-8)) ;
    }





    if (n_row != n_col)
    {


 strategy = 1 ;
 ;
    }

    if (strategy < 0
     || strategy > 3)
    {

 strategy = 0 ;
    }

    if (Quser != (int *) 0)
    {


 if (strategy == 2)
 {
     strategy = 3 ;
 }
 if (strategy != 3)
 {
     strategy = 1 ;
 }
    }

    user_auto_strategy = (strategy == 0) ;
# 485 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    dClen = ( (((double) nz) < 0 || ((double) n_row) < 0 || ((double) n_col) < 0) ? (-1) : ((((2 * ((double) nz)) > (4 * ((double) n_col))) ? (2 * ((double) nz)) : (4 * ((double) n_col))) + (int) (((double) n_col + 1) * sizeof (Colamd_Col) / sizeof (int)) + (int) (((double) n_row + 1) * sizeof (Colamd_Row) / sizeof (int)) + ((double) n_col) + (((double) nz) / 5)) )
                 ;




    dClen_analyze = (((double) n_col) + (((((double) nz)) > (((double) n_col))) ? (((double) nz)) : (((double) n_col))) + 3*((double) nn)+1 + ((double) n_col))
                              ;
    dClen = (((dClen) > (dClen_analyze)) ? (dClen) : (dClen_analyze)) ;


    dClen_amd = 2.4 * (double) nz + 8 * (double) n_inner ;

    dClen_amd += (double) (((nn) > (nz)) ? (nn) : (nz)) ;
    dClen = (((dClen) > (dClen_amd)) ? (dClen) : (dClen_amd)) ;


    Info [13] =
 ((ceil ((sizeof (int) * ((double) dClen)) / sizeof (Unit))) + (ceil ((sizeof (int) * ((double) nz)) / sizeof (Unit))) + 4 * (ceil ((sizeof (int) * ((double) n_row)) / sizeof (Unit))) + 4 * (ceil ((sizeof (int) * ((double) n_col)) / sizeof (Unit))) + 2 * (ceil ((sizeof (int) * ((double) n_col + 1)) / sizeof (Unit))) + (ceil ((sizeof (double) * ((double) n_row)) / sizeof (Unit)))) +
 umfdi_symbolic_usage (n_row, n_col, n_col, n_col, n_col, (1)) ;

    if (((!((dClen * sizeof (int)) * (1.0+1e-8) <= (double) 0x7fffffff
# 506 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
       )) || ((dClen * sizeof (int)) != (dClen * sizeof (int)))))
    {




 ;
 Info [0] = (-1) ;
 return ((-1)) ;
    }


    Clen = ( ((nz) < 0 || (n_row) < 0 || (n_col) < 0) ? (-1) : ((((2 * (nz)) > (4 * (n_col))) ? (2 * (nz)) : (4 * (n_col))) + (int) ((n_col + 1) * sizeof (Colamd_Col) / sizeof (int)) + (int) ((n_row + 1) * sizeof (Colamd_Row) / sizeof (int)) + (n_col) + ((nz) / 5)) ) ;
    Clen_analyze = ((n_col) + ((((nz)) > ((n_col))) ? ((nz)) : ((n_col))) + 3*(nn)+1 + (n_col)) ;
    Clen = (((Clen) > (Clen_analyze)) ? (Clen) : (Clen_analyze)) ;
    Clen_amd = 2.4 * nz + 8 * n_inner ;
    Clen_amd += (((nn) > (nz)) ? (nn) : (nz)) ;
    Clen = (((Clen) > (Clen_amd)) ? (Clen) : (Clen_amd)) ;
# 536 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    Symbolic = (SymbolicType *) umf_i_malloc (1, sizeof (SymbolicType)) ;

    if (!Symbolic)
    {


 ;
 Info [0] = (-1) ;
 error (&Symbolic, (SWType *) 0) ;
 return ((-1)) ;
    }


    Symbolic->valid = 0 ;
    Symbolic->Chain_start = (int *) 0 ;
    Symbolic->Chain_maxrows = (int *) 0 ;
    Symbolic->Chain_maxcols = (int *) 0 ;
    Symbolic->Front_npivcol = (int *) 0 ;
    Symbolic->Front_parent = (int *) 0 ;
    Symbolic->Front_1strow = (int *) 0 ;
    Symbolic->Front_leftmostdesc = (int *) 0 ;
    Symbolic->Esize = (int *) 0 ;
    Symbolic->esize = 0 ;

    Symbolic->Cperm_init = (int *) umf_i_malloc (n_col+1, sizeof (int)) ;
    Symbolic->Rperm_init = (int *) umf_i_malloc (n_row+1, sizeof (int)) ;
    Symbolic->Cdeg = (int *) umf_i_malloc (n_col+1, sizeof (int)) ;
    Symbolic->Rdeg = (int *) umf_i_malloc (n_row+1, sizeof (int)) ;
    Symbolic->Diagonal_map = (int *) 0 ;

    Cperm_init = Symbolic->Cperm_init ;
    Rperm_init = Symbolic->Rperm_init ;
    Cdeg = Symbolic->Cdeg ;
    Rdeg = Symbolic->Rdeg ;

    if (!Cperm_init || !Rperm_init || !Cdeg || !Rdeg)
    {
 ;
 Info [0] = (-1) ;
 error (&Symbolic, (SWType *) 0) ;
 return ((-1)) ;
    }

    Symbolic->n_row = n_row ;
    Symbolic->n_col = n_col ;
    Symbolic->nz = nz ;
    Symbolic->nb = nb ;





    if (Quser != (int *) 0)
    {

 if (!umf_i_is_permutation (Quser, Cperm_init, n_col, n_col))
 {
     Info [0] = (-15) ;
     error (&Symbolic, (SWType *) 0) ;
     return ((-15)) ;
 }
    }
# 622 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    SW = &SWspace ;





    SW->Si = (int *) umf_i_malloc (nz, sizeof (int)) ;
    SW->Sp = (int *) umf_i_malloc (n_col + 1, sizeof (int)) ;
    SW->InvRperm1 = (int *) umf_i_malloc (n_row, sizeof (int)) ;
    SW->Cperm1 = (int *) umf_i_malloc (n_col, sizeof (int)) ;


    SW->Ci = (int *) umf_i_malloc (Clen, sizeof (int)) ;
    SW->Front_npivcol = (int *) umf_i_malloc (n_col + 1, sizeof (int)) ;
    SW->Front_nrows = (int *) umf_i_malloc (n_col, sizeof (int)) ;
    SW->Front_ncols = (int *) umf_i_malloc (n_col, sizeof (int)) ;
    SW->Front_parent = (int *) umf_i_malloc (n_col, sizeof (int)) ;
    SW->Front_cols = (int *) umf_i_malloc (n_col, sizeof (int)) ;
    SW->Rperm1 = (int *) umf_i_malloc (n_row, sizeof (int)) ;
    SW->InFront = (int *) umf_i_malloc (n_row, sizeof (int)) ;


    SW->Rperm_2by2 = (int *) 0 ;


    SW->Rs = (double *) 0 ;

    Ci = SW->Ci ;
    Fr_npivcol = SW->Front_npivcol ;
    Fr_nrows = SW->Front_nrows ;
    Fr_ncols = SW->Front_ncols ;
    Fr_parent = SW->Front_parent ;
    Fr_cols = SW->Front_cols ;
    Cperm1 = SW->Cperm1 ;
    Rperm1 = SW->Rperm1 ;
    Si = SW->Si ;
    Sp = SW->Sp ;
    InvRperm1 = SW->InvRperm1 ;
    Rperm_2by2 = (int *) 0 ;
    InFront = SW->InFront ;

    if (!Ci || !Fr_npivcol || !Fr_nrows || !Fr_ncols || !Fr_parent || !Fr_cols
 || !Cperm1 || !Rperm1 || !Si || !Sp || !InvRperm1 || !InFront)
    {
 ;
 Info [0] = (-1) ;
 error (&Symbolic, SW) ;
 return ((-1)) ;
    }

   
                                 ;
    ;







    ;

    status = umf_i_singletons (n_row, n_col, Ap, Ai, Quser, strategy,
 Cdeg, Cperm1, Rdeg,
 Rperm1, InvRperm1, &n1, &n1c, &n1r, &nempty_col, &nempty_row, &is_sym,
 &max_rdeg, Rperm_init, Ci, Ci + nz, Ci + nz + n_row) ;





    if (status != (0))
    {
 ;
 Info [0] = status ;
 error (&Symbolic, SW) ;
 return (status) ;
    }
    Info [11] = nempty_col ;
    Info [9] = nempty_row ;
    Info [10] = 0 ;
    Info [8] = 0 ;
    Info [56] = n1c ;
    Info [57] = n1r ;
    Info [59] = is_sym ;

    nempty = (((nempty_col) < (nempty_row)) ? (nempty_col) : (nempty_row)) ;
    Symbolic->nempty_row = nempty_row ;
    Symbolic->nempty_col = nempty_col ;


    ;

    Symbolic->n1 = n1 ;
    Symbolic->nempty = nempty ;
    ;
    n2 = nn - n1 - nempty ;

    dense_row_threshold =
 ((int) (((16.0) > ((drow) * 16.0 * sqrt ((double) (n_col - n1 - nempty_col)))) ? (16.0) : ((drow) * 16.0 * sqrt ((double) (n_col - n1 - nempty_col))))) ;
    Symbolic->dense_row_threshold = dense_row_threshold ;

    if (!is_sym)
    {




 strategy = 1 ;
 ;
    }
# 742 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    Wq = Rperm_init ;
    Sdeg = Cperm_init ;
    sym = (-1) ;
    nzaat = (-1) ;
    nzdiag = (-1) ;
    for (i = 0 ; i < 20 ; i++)
    {
 amd_Info [i] = (-1) ;
    }

    if (strategy != 1)
    {



 ;
 ;





 nzdiag = prune_singletons (n1, nn, Ap, Ai, Ax,



     Cperm1, InvRperm1, Si, Sp



     ) ;


 if (Quser != (int *) 0)
 {

     Rp = Ci ;
     Ri = Ci + (n_row) + 1 ;
     (void) umfdi_transpose (n2, n2, Sp, Si, (double *) 0,
  (int *) 0, (int *) 0, 0,
  Rp, Ri, (double *) 0, Wq, (0)



  ) ;
 }
 else
 {

     Rp = Sp ;
     Ri = Si ;
 }
 ;

 nzaat = amd_aat (n2, Rp, Ri, Sdeg, Wq, amd_Info) ;
 sym = amd_Info [3] ;
 Info [58] = n2 ;
# 812 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    }


    Symbolic->sym = sym ;
    Symbolic->nzaat = nzaat ;
    Symbolic->nzdiag = nzdiag ;
    Symbolic->amd_dmax = (-1) ;

    Info [33] = sym ;
    Info [34] = nzaat ;
    Info [35] = nzdiag ;





    if (strategy == 0)
    {
 if (sym < 0.10)
 {

     strategy = 1 ;
     ;
 }
 else if (sym >= 0.7 && nzdiag == n2)
 {

     strategy = 3 ;
     ;
 }
 else
 {



     strategy = 2 ;
     ;
 }
    }
# 864 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    if (strategy == 2)
    {
 double sym2 ;
 int *Blen, *W, nz_papat, nzd2, nweak, unmatched, Clen3 ;





 ;
# 883 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 SW->Rperm_2by2 = (int *) umf_i_malloc (nn, sizeof (int)) ;
 Rperm_2by2 = SW->Rperm_2by2 ;
 if (Rperm_2by2 == (int *) 0)
 {
     ;
     Info [0] = (-1) ;
     error (&Symbolic, SW) ;
     return ((-1)) ;
 }


 Clen3 = Clen - ((((nn) > (nz)) ? (nn) : (nz)) + 1) ;
 Ri = Ci + Clen3 ;
 ;


 Rp = Fr_npivcol ;
 Blen = Fr_ncols ;
 W = Fr_cols ;

 if (scale != 0)
 {
     SW->Rs = (double *) umf_i_malloc (nn, sizeof (double)) ;
     if (SW->Rs == (double *) 0)
     {
  ;
  Info [0] = (-1) ;
  error (&Symbolic, SW) ;
  return ((-1)) ;
     }
 }
# 922 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 umfdi_2by2 (nn, Ap, Ai, Ax,



  tol, scale, Cperm1,



  InvRperm1, n1, nempty, Sdeg, Rperm_2by2, &nweak, &unmatched,
  Ri, Rp, SW->Rs, Blen, W, Ci, Wq) ;
 ;
 Info [51] = nweak ;
 Info [52] = unmatched ;

 SW->Rs = (double *) umf_i_free ((void *) SW->Rs) ;


 (void) umfdi_transpose (n2, n2, Sp, Si, (double *) 0, Rperm_2by2,
     (int *) 0, 0, Rp, Ri, (double *) 0, W, (0)



     ) ;
 ;
# 954 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 for (i = 0 ; i < 20 ; i++)
 {
     amd_Info [i] = (-1) ;
 }
 nz_papat = amd_aat (n2, Rp, Ri, Sdeg, Wq, amd_Info) ;
 sym2 = amd_Info [3] ;
 nzd2 = amd_Info [4] ;

 Info [53] = sym2 ;
 Info [54] = nz_papat ;
 Info [55] = nzd2 ;

 ;





 if (user_auto_strategy)
 {
     if ((sym2 > 1.1 * sym) && (nzd2 > 0.9 * n2))
     {

  ;
  strategy = 2 ;
     }
     else if (sym2 < 0.7 * sym)
     {

  ;
  strategy = 1 ;
     }
     else if (sym2 < 0.25)
     {
  ;
  strategy = 1 ;
     }
     else if (sym2 >= 0.51)
     {
  ;
  strategy = 2 ;
     }
     else if (sym2 >= 0.999 * sym)
     {

  ;
  strategy = 2 ;
     }
     else
     {

  ;
  strategy = 1 ;
     }
 }





 if (strategy == 2)
 {
     if (Quser == (int *) 0)
     {


  int *Qinv = Fr_npivcol ;
  ;
  do_amd (n2, Rp, Ri, Wq, Qinv, Sdeg, Clen3, Ci,
      amd_Control, amd_Info, Symbolic, Info) ;

  combine_ordering (n1, nempty, nn, Cperm_init, Cperm1, Qinv) ;
     }

     for (k = 0 ; k < n1 ; k++)
     {
  oldcol = Cperm1 [k] ;
  i = k ;
  oldrow = Rperm1 [k] ;
  W [oldcol] = oldrow ;
     }
     for (k = n1 ; k < nn - nempty ; k++)
     {
  oldcol = Cperm1 [k] ;
  i = Rperm_2by2 [k - n1] + n1 ;
  oldrow = Rperm1 [i] ;
  W [oldcol] = oldrow ;
     }
     for (k = nn - nempty ; k < nn ; k++)
     {
  oldcol = Cperm1 [k] ;
  i = k ;
  oldrow = Rperm1 [k] ;
  W [oldcol] = oldrow ;
     }
     for (k = 0 ; k < nn ; k++)
     {
  Rperm_2by2 [k] = W [k] ;
     }




 }


    }





    if (strategy == 3)
    {


 ;
 ;
 Symbolic->ordering = 1 ;
 fixQ = (1) ;
 prefer_diagonal = (1) ;
    }
    else if (strategy == 2)
    {


 ;
 ;
 Symbolic->ordering = 1 ;
 fixQ = (1) ;
 prefer_diagonal = (1) ;
    }
    else
    {


 ;
 ;
 Symbolic->ordering = 0 ;
 fixQ = (0) ;
 prefer_diagonal = (0) ;
    }

    if (Quser != (int *) 0)
    {
 Symbolic->ordering = 2 ;
    }

    if (force_fixQ > 0)
    {
 fixQ = (1) ;
 ;
    }
    else if (force_fixQ < 0)
    {
 fixQ = (0) ;
 ;
    }

    ;
    ;
    ;


    Symbolic->strategy = strategy ;
    Symbolic->fixQ = fixQ ;
    Symbolic->prefer_diagonal = prefer_diagonal ;

    Info [18] = strategy ;
    Info [19] = Symbolic->ordering ;
    Info [31] = fixQ ;
    Info [32] = prefer_diagonal ;





    if (strategy == 3 && Quser == (int *) 0)
    {

 int *Qinv = Fr_npivcol ;
 ;
 ;
 do_amd (n2, Sp, Si, Wq, Qinv, Sdeg, Clen, Ci,
  amd_Control, amd_Info, Symbolic, Info) ;

 combine_ordering (n1, nempty, nn, Cperm_init, Cperm1, Qinv) ;
    }
# 1151 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    if (Quser != (int *) 0)
    {
 for (k = 0 ; k < n_col ; k++)
 {
     Cperm_init [k] = Cperm1 [k] ;
 }
    }





    if (strategy == 1 && Quser == (int *) 0)
    {
# 1174 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 (void) prune_singletons (n1, n_col, Ap, Ai,
     (double *) 0,



     Cperm1, InvRperm1, Ci, Cperm_init



     ) ;





 umf_i_colamd_set_defaults (knobs) ;
 knobs [0] = drow ;
 knobs [1] = dcol ;
 knobs [2] = aggressive ;
# 1205 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 (void) umf_i_colamd (
  n_row - n1 - nempty_row,
  n_col - n1 - nempty_col,
  Clen, Ci, Cperm_init, knobs, colamd_stats,
  Fr_npivcol, Fr_nrows, Fr_ncols, Fr_parent, Fr_cols, &nfr,
  InFront) ;
 ;
 ;


 Info [8] = colamd_stats [0] ;
 Info [10] = colamd_stats [1] ;
 Info [12] = colamd_stats [2] ;


 do_UMF_analyze =
     colamd_stats [0] > 0 ||
     colamd_stats [1] > 0 ;



 combine_ordering (n1, nempty_col, n_col, Cperm_init, Cperm1, Ci) ;
# 1240 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    }
    else
    {






 do_UMF_analyze = (1) ;

    }

    Cperm_init [n_col] = (-1) ;
# 1280 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    if (do_UMF_analyze)
    {

 int *W, *Bp, *Bi, *Cperm2, ok, *P, Clen2, bsize, Clen0 ;







 (void) prune_singletons (n1, n_col, Ap, Ai,
     (double *) 0,



     Cperm_init, InvRperm1, Si, Sp



     ) ;
# 1318 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 Clen0 = Clen - (nn+1 + 2*nn + n_col) ;
 Bp = Ci + Clen0 ;
 Link = Bp + (nn+1) ;
 W = Link + nn ;
 Cperm2 = W + nn ;
 ;
 ;
 ;






 for (row = 0 ; row < n_row - n1 ; row++)
 {
     W [row] = (0) ;
 }
 P = Link ;

 k = 0 ;

 for (col = 0 ; col < n_col - n1 ; col++)
 {

     for (p = Sp [col] ; p < Sp [col+1] ; p++)
     {
  row = Si [p] ;
  if (!W [row])
  {

      W [row] = (1) ;
      P [k++] = row ;
  }
     }
 }



 nempty_row = n_row - n1 - k ;
 if (k < n_row - n1)
 {


     for (row = 0 ; row < n_row - n1 ; row++)
     {
  if (!W [row])
  {

      P [k++] = row ;
  }
     }
 }
# 1401 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 Clen2 = Clen0 ;
 snz = Sp [n_col - n1] ;
 bsize = (((snz) > (1)) ? (snz) : (1)) ;
 Clen2 -= bsize ;
 Bi = Ci + Clen2 ;
 ;

 (void) umfdi_transpose (n_row - n1, n_col - n1 - nempty_col,
     Sp, Si, (double *) 0,
     P, (int *) 0, 0, Bp, Bi, (double *) 0, W, (0)



     ) ;






 ;
 ;


 for (i = 0 ; i <= n_row - n1 ; i++)
 {
     Bp [i] += Clen2 ;
 }
 ;
 ;
# 1449 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
 ok = umf_i_analyze (
  n_row - n1 - nempty_row,
  n_col - n1 - nempty_col,
  Ci, Bp, Cperm2, fixQ, W, Link,
  Fr_ncols, Fr_nrows, Fr_npivcol,
  Fr_parent, &nfr, &analyze_compactions) ;
 if (!ok)
 {

     Info [0] = (-911) ;
     error (&Symbolic, SW) ;
     return ((-911)) ;
 }
 Info [12] += analyze_compactions ;





 if (!fixQ)
 {

    
                                                ;


     for (k = 0 ; k < n_col - n1 - nempty_col ; k++)
     {
  W [k] = Cperm_init [n1 + Cperm2 [k]] ;
     }

     for (k = 0 ; k < n_col - n1 - nempty_col ; k++)
     {
  Cperm_init [n1 + k] = W [k] ;
     }
 }

 ;

    }
# 1498 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    SW->Si = (int *) umf_i_free ((void *) SW->Si) ;
    SW->Sp = (int *) umf_i_free ((void *) SW->Sp) ;
    SW->Cperm1 = (int *) umf_i_free ((void *) SW->Cperm1) ;
    ;
# 1511 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    nchains = 0 ;
    for (i = 0 ; i < nfr ; i++)
    {
 if (Fr_parent [i] != i+1)
 {
     nchains++ ;
 }
    }

    Symbolic->nchains = nchains ;
    Symbolic->nfr = nfr ;
    Symbolic->esize
 = (max_rdeg > dense_row_threshold) ? (n_col - n1 - nempty_col) : 0 ;


    Info [14] = umfdi_symbolic_usage (n_row, n_col, nchains,
     nfr, Symbolic->esize, prefer_diagonal) ;


    Info [13] =
 ((ceil ((sizeof (int) * ((double) Clen)) / sizeof (Unit))) + (ceil ((sizeof (int) * ((double) nz)) / sizeof (Unit))) + 4 * (ceil ((sizeof (int) * ((double) n_row)) / sizeof (Unit))) + 4 * (ceil ((sizeof (int) * ((double) n_col)) / sizeof (Unit))) + 2 * (ceil ((sizeof (int) * ((double) n_col + 1)) / sizeof (Unit))) + (ceil ((sizeof (double) * ((double) n_row)) / sizeof (Unit)))) + Info [14] ;
    Symbolic->peak_sym_usage = Info [13] ;

    ;
# 1551 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    Symbolic->Front_npivcol = (int *) umf_i_malloc (nfr+1, sizeof (int)) ;
    Symbolic->Front_parent = (int *) umf_i_malloc (nfr+1, sizeof (int)) ;
    Symbolic->Front_1strow = (int *) umf_i_malloc (nfr+1, sizeof (int)) ;
    Symbolic->Front_leftmostdesc = (int *) umf_i_malloc (nfr+1, sizeof (int)) ;
    Symbolic->Chain_start = (int *) umf_i_malloc (nchains+1, sizeof (int)) ;
    Symbolic->Chain_maxrows = (int *) umf_i_malloc (nchains+1, sizeof (int)) ;
    Symbolic->Chain_maxcols = (int *) umf_i_malloc (nchains+1, sizeof (int)) ;

    fail = (!Symbolic->Front_npivcol || !Symbolic->Front_parent ||
 !Symbolic->Front_1strow || !Symbolic->Front_leftmostdesc ||
 !Symbolic->Chain_start || !Symbolic->Chain_maxrows ||
 !Symbolic->Chain_maxcols) ;

    if (Symbolic->esize > 0)
    {
 Symbolic->Esize = (int *) umf_i_malloc (Symbolic->esize, sizeof (int)) ;
 fail = fail || !Symbolic->Esize ;
    }

    if (fail)
    {
 ;
 Info [0] = (-1) ;
 error (&Symbolic, SW) ;
 return ((-1)) ;
    }
   
                                 ;
   

                                      ;

    Front_npivcol = Symbolic->Front_npivcol ;
    Front_parent = Symbolic->Front_parent ;
    Front_1strow = Symbolic->Front_1strow ;
    Front_leftmostdesc = Symbolic->Front_leftmostdesc ;

    Chain_start = Symbolic->Chain_start ;
    Chain_maxrows = Symbolic->Chain_maxrows ;
    Chain_maxcols = Symbolic->Chain_maxcols ;

    Esize = Symbolic->Esize ;






    if (do_UMF_analyze)
    {

 ;

 for (row = 0 ; row < n_row ; row++)
 {
     InFront [row] = nfr ;
 }

 for (k = 0 ; k < n1 ; k++)
 {
     row = Rperm1 [k] ;
     InFront [row] = (-1) ;
 }
 ;
 newj = n1 ;
 for (i = 0 ; i < nfr ; i++)
 {
     fpivcol = Fr_npivcol [i] ;
     f1rows = 0 ;

     for (kk = 0 ; kk < fpivcol ; kk++, newj++)
     {
  j = Cperm_init [newj] ;
 
                            ;
  for (p = Ap [j] ; p < Ap [j+1] ; p++)
  {
      row = Ai [p] ;
      if (InFront [row] == nfr)
      {

   ;
   InFront [row] = i ;
   f1rows++ ;
      }
  }
     }
     Front_1strow [i] = f1rows ;
    
                       ;
 }

    }
    else
    {







 ;
 for (i = 0 ; i <= nfr ; i++)
 {
     Front_1strow [i] = 0 ;
 }

 for (k = 0 ; k < n1 ; k++)
 {
     row = Rperm1 [k] ;
     Ci [row] = (-1) ;
 }

 for ( ; k < n_row - nempty_row ; k++)
 {
     row = Rperm1 [k] ;
     i = InFront [k - n1] ;
     ;
     if (i != (-1))
     {
  Front_1strow [i]++ ;
     }

     Ci [row] = i ;
 }

 for ( ; k < n_row ; k++)
 {
     row = Rperm1 [k] ;
     Ci [row] = nfr ;
 }


 for (row = 0 ; row < n_row ; row++)
 {
     InFront [row] = Ci [row] ;
 }

    }
# 1719 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    k = n1 ;
    for (i = 0 ; i < nfr ; i++)
    {
 fpivcol = Fr_npivcol [i] ;

                                                 ;
 k += fpivcol ;

 Front_npivcol [i] = fpivcol ;
 Front_parent [i] = Fr_parent [i] ;
    }


    ;
    Front_npivcol [nfr] = n_col - k ;
    Front_parent [nfr] = (-1) ;






    for (k = 0 ; k < n1 ; k++)
    {
 Rperm_init [k] = Rperm1 [k] ;
    }


    for (i = 0 ; i < nfr ; i++)
    {
 f1rows = Front_1strow [i] ;

                                              ;
 ;
 Front_1strow [i] = k ;
 k += f1rows ;
    }


    ;
    Front_1strow [nfr] = k ;
    ;


    F1 = Ci ;
    ;

    for (i = 0 ; i <= nfr ; i++)
    {
 F1 [i] = Front_1strow [i] ;
    }

    for (row = 0 ; row < n_row ; row++)
    {
 i = InFront [row] ;
 if (i != (-1))
 {
     newrow = F1 [i]++ ;
     ;
     Rperm_init [newrow] = row ;
 }
    }
    Rperm_init [n_row] = (-1) ;
# 1804 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    if (prefer_diagonal)
    {
 int *Diagonal_map ;
 ;
 ;


 Symbolic->Diagonal_map = (int *) umf_i_malloc (n_col+1, sizeof (int)) ;
 Diagonal_map = Symbolic->Diagonal_map ;
 if (Diagonal_map == (int *) 0)
 {

     ;
     Info [0] = (-1) ;
     error (&Symbolic, SW) ;
     return ((-1)) ;
 }


 for (newrow = 0 ; newrow < nn ; newrow++)
 {
     oldrow = Rperm_init [newrow] ;
     ;
     Ci [oldrow] = newrow ;
 }
 if (strategy == 2)
 {
     ;
     for (newcol = 0 ; newcol < nn ; newcol++)
     {
  oldcol = Cperm_init [newcol] ;

  oldrow = Rperm_2by2 [oldcol] ;
  newrow = Ci [oldrow] ;
  Diagonal_map [newcol] = newrow ;
     }
 }
 else
 {
     for (newcol = 0 ; newcol < nn ; newcol++)
     {
  oldcol = Cperm_init [newcol] ;

  oldrow = oldcol ;
  newrow = Ci [oldrow] ;
  Diagonal_map [newcol] = newrow ;
     }
 }
# 1887 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    }





    for (i = 0 ; i <= nfr ; i++)
    {
 Front_leftmostdesc [i] = (-1) ;
    }

    for (i = 0 ; i < nfr ; i++)
    {

 ;
 j = i ;
 while (j != (-1) && Front_leftmostdesc [j] == (-1))
 {
     ;
     Front_leftmostdesc [j] = i ;
     j = Front_parent [j] ;
     ;
 }
    }





    maxnrows = 1 ;
    maxncols = 1 ;
    dmaxfrsize = 1 ;


    nchains = 0 ;
    Chain_start [0] = 0 ;
    maxrows = 1 ;
    maxcols = 1 ;
    ;

    for (i = 0 ; i < nfr ; i++)
    {

 fpivcol = Front_npivcol [i] ;
 fallrows = Fr_nrows [i] ;
 fallcols = Fr_ncols [i] ;
 parent = Front_parent [i] ;
 fpiv = (((fpivcol) < (fallrows)) ? (fpivcol) : (fallrows)) ;
 maxrows = (((maxrows) > (fallrows)) ? (maxrows) : (fallrows)) ;
 maxcols = (((maxcols) > (fallcols)) ? (maxcols) : (fallcols)) ;



                                                          ;

 if (parent != i+1)
 {

     double s ;
     ;


     ;
     if (maxrows % 2 == 0) maxrows++ ;

     ;

     Chain_maxrows [nchains] = maxrows ;
     Chain_maxcols [nchains] = maxcols ;




     s = (double) maxrows * (double) maxcols ;
     dmaxfrsize = (((dmaxfrsize) > (s)) ? (dmaxfrsize) : (s)) ;


     maxnrows = (((maxnrows) > (maxrows)) ? (maxnrows) : (maxrows)) ;
     maxncols = (((maxncols) > (maxcols)) ? (maxncols) : (maxcols)) ;

     ;


     nchains++ ;
     Chain_start [nchains] = i+1 ;
     maxrows = 1 ;
     maxcols = 1 ;
 }
    }


    dmaxfrsize = ceil (dmaxfrsize) ;
    ;
    ;






    Symbolic->maxnrows = maxnrows ;
    Symbolic->maxncols = maxncols ;
    ;





    if (max_rdeg > dense_row_threshold)
    {



 ;
 for (newrow = 0 ; newrow < n_row ; newrow++)
 {
     oldrow = Rperm_init [newrow] ;
     ;
     Ci [oldrow] = newrow ;
 }
 for (col = n1 ; col < n_col - nempty_col ; col++)
 {
     oldcol = Cperm_init [col] ;
     esize = Cdeg [oldcol] ;
     ;
     for (p = Ap [oldcol] ; p < Ap [oldcol+1] ; p++)
     {
  oldrow = Ai [p] ;
  newrow = Ci [oldrow] ;
  if (newrow >= n1 && Rdeg [oldrow] > dense_row_threshold)
  {
      esize-- ;
  }
     }
     ;
     Esize [col - n1] = esize ;
 }

    }
# 2035 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    for (k = 0 ; k < n_col ; k++)
    {
 Ci [k] = Cdeg [Cperm_init [k]] ;
    }
    for (k = 0 ; k < n_col ; k++)
    {
 Cdeg [k] = Ci [k] ;
    }
    for (k = 0 ; k < n_row ; k++)
    {
 Ci [k] = Rdeg [Rperm_init [k]] ;
    }
    for (k = 0 ; k < n_row ; k++)
    {
 Rdeg [k] = Ci [k] ;
    }
# 2060 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    dlnz = n_inner ;
    dunz = dlnz ;


    head_usage = 1 ;
    dhead_usage = 1 ;


    tail_usage = 2 ;
    dtail_usage = 2 ;


    tail_usage += (((((sizeof (int *) * (n_row+1))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (double *) * (n_row+1))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + 2 ;
    dtail_usage += (ceil ((sizeof (int *) * ((double) n_row+1)) / sizeof (Unit))) + (ceil ((sizeof (double *) * ((double) n_row+1)) / sizeof (Unit))) + 2 ;
   
                          ;


    for (k = 0 ; k < n1 ; k++)
    {
 lnz = Cdeg [k] - 1 ;
 unz = Rdeg [k] - 1 ;
 dlnz += lnz ;
 dunz += unz ;

                                                   ;
 head_usage += (((((sizeof (int) * (lnz))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (double) * (lnz))) + (sizeof (Unit)) - 1) / (sizeof (Unit))))
      + (((((sizeof (int) * (unz))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (double) * (unz))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) ;
 dhead_usage += (ceil ((sizeof (int) * ((double) lnz)) / sizeof (Unit))) + (ceil ((sizeof (double) * ((double) lnz)) / sizeof (Unit)))
      + (ceil ((sizeof (int) * ((double) unz)) / sizeof (Unit))) + (ceil ((sizeof (double) * ((double) unz)) / sizeof (Unit))) ;
    }
    ;


    for (k = n1 ; k < n_col - nempty_col; k++)
    {
 esize = Esize ? Esize [k-n1] : Cdeg [k] ;
 ;
 ;
 if (esize > 0)
 {
     tail_usage += ((((((sizeof (Element) * (1))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (int) * ((1) + (esize)))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (double) * ((1) * (esize)))) + (sizeof (Unit)) - 1) / (sizeof (Unit))))) + 1 ;
     dtail_usage += ((ceil ((sizeof (Element) * ((double) 1)) / sizeof (Unit))) + (ceil ((sizeof (int) * ((double) (1) + (esize))) / sizeof (Unit))) + (ceil ((sizeof (double) * ((double) (1) * (esize))) / sizeof (Unit)))) + 1 ;
 }
    }


    if (Esize)
    {
 int nrow_elements = 0 ;
 for (k = n1 ; k < n_row - nempty_row ; k++)
 {
     rdeg = Rdeg [k] ;
     if (rdeg > dense_row_threshold)
     {
  tail_usage += ((((((sizeof (Element) * (1))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (int) * ((rdeg) + (1)))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (double) * ((rdeg) * (1)))) + (sizeof (Unit)) - 1) / (sizeof (Unit))))) + 1 ;
  dtail_usage += ((((((sizeof (Element) * (1))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (int) * ((rdeg) + (1)))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (double) * ((rdeg) * (1)))) + (sizeof (Unit)) - 1) / (sizeof (Unit))))) + 1 ;
  nrow_elements++ ;
     }
 }
 Info [8] = nrow_elements ;
    }

   
                                                   ;


    if (Esize)
    {

 for (row = n1 ; row < n_row ; row++)
 {
     rdeg = Rdeg [row] ;
     tlen = (rdeg > dense_row_threshold) ? 1 : rdeg ;
     tail_usage += 1 + (((((sizeof (Tuple) * ((((4) > ((tlen) + 1)) ? (4) : ((tlen) + 1))))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) ;
     dtail_usage += 1 + (ceil ((sizeof (Tuple) * ((double) (((4) > ((tlen) + 1)) ? (4) : ((tlen) + 1)))) / sizeof (Unit))) ;
 }

 for (col = n1 ; col < n_col - nempty_col ; col++)
 {

     esize = Esize [col - n1] ;
     tlen = (esize > 0) + (Cdeg [col] - esize) ;
     tail_usage += 1 + (((((sizeof (Tuple) * ((((4) > ((tlen) + 1)) ? (4) : ((tlen) + 1))))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) ;
     dtail_usage += 1 + (ceil ((sizeof (Tuple) * ((double) (((4) > ((tlen) + 1)) ? (4) : ((tlen) + 1)))) / sizeof (Unit))) ;
 }
 for ( ; col < n_col ; col++)
 {
     tail_usage += 1 + (((((sizeof (Tuple) * ((((4) > ((0) + 1)) ? (4) : ((0) + 1))))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) ;
     dtail_usage += 1 + (ceil ((sizeof (Tuple) * ((double) (((4) > ((0) + 1)) ? (4) : ((0) + 1)))) / sizeof (Unit))) ;
 }
    }
    else
    {

 for (row = n1 ; row < n_row ; row++)
 {
     tlen = Rdeg [row] ;
     tail_usage += 1 + (((((sizeof (Tuple) * ((((4) > ((tlen) + 1)) ? (4) : ((tlen) + 1))))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) ;
     dtail_usage += 1 + (ceil ((sizeof (Tuple) * ((double) (((4) > ((tlen) + 1)) ? (4) : ((tlen) + 1)))) / sizeof (Unit))) ;
 }

 for (col = n1 ; col < n_col ; col++)
 {
     tail_usage += 1 + (((((sizeof (Tuple) * ((((4) > ((1) + 1)) ? (4) : ((1) + 1))))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) ;
     dtail_usage += 1 + (ceil ((sizeof (Tuple) * ((double) (((4) > ((1) + 1)) ? (4) : ((1) + 1)))) / sizeof (Unit))) ;
 }
    }

    Symbolic->num_mem_init_usage = head_usage + tail_usage ;
   
                                                        ;

    ;


    dmax_usage = dhead_usage + dtail_usage ;
    dmax_usage = (((Symbolic->num_mem_init_usage) > (ceil (dmax_usage))) ? (Symbolic->num_mem_init_usage) : (ceil (dmax_usage))) ;
    Info [25] = dmax_usage ;


    Symbolic->dnum_mem_init_usage = dmax_usage ;


    tail_usage -= (((((sizeof (int *) * (n_row+1))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) + (((((sizeof (double *) * (n_row+1))) + (sizeof (Unit)) - 1) / (sizeof (Unit)))) ;
    dtail_usage -= (ceil ((sizeof (int *) * ((double) n_row+1)) / sizeof (Unit))) + (ceil ((sizeof (double *) * ((double) n_row+1)) / sizeof (Unit))) ;






    Link = Ci ;
    for (i = 0 ; i < nfr ; i++)
    {
 Link [i] = (-1) ;
    }

    flops = 0 ;

    for (chain = 0 ; chain < nchains ; chain++)
    {
 double fsize ;
 f1 = Chain_start [chain] ;
 f2 = Chain_start [chain+1] - 1 ;


 dr = Chain_maxrows [chain] ;
 dc = Chain_maxcols [chain] ;
 fsize =
       nb*nb
     + dr*nb
     + nb*dc
     + dr*dc ;
 dtail_usage += (ceil ((sizeof (double) * ((double) fsize)) / sizeof (Unit))) ;
 dmax_usage = (((dmax_usage) > (dhead_usage + dtail_usage)) ? (dmax_usage) : (dhead_usage + dtail_usage)) ;

 for (i = f1 ; i <= f2 ; i++)
 {


     fpivcol = Front_npivcol [i] ;
     fallrows = Fr_nrows [i] ;
     fallcols = Fr_ncols [i] ;
     parent = Front_parent [i] ;
     fpiv = (((fpivcol) < (fallrows)) ? (fpivcol) : (fallrows)) ;
     f = (double) fpiv ;
     r = fallrows - fpiv ;
     c = fallcols - fpiv ;


     for (child = Link [i] ; child != (-1) ; child = Link [child])
     {
  ;
  ;

  cp = (((Front_npivcol [child]) < (Fr_nrows [child])) ? (Front_npivcol [child]) : (Fr_nrows [child])) ;
  cr = Fr_nrows [child] - cp ;
  cc = Fr_ncols [child] - cp ;
  ;
  dtail_usage -= (((ceil ((sizeof (Element) * ((double) 1)) / sizeof (Unit))) + (ceil ((sizeof (int) * ((double) (cc) + (cr))) / sizeof (Unit))) + (ceil ((sizeof (double) * ((double) (cc) * (cr))) / sizeof (Unit)))) + 1 + (cr + cc) * (((((sizeof (Tuple) * (1))) + (sizeof (Unit)) - 1) / (sizeof (Unit))))) ;

     }




     flops += 1. * (f*r + (f-1)*f/2)

  + 2. * (f*r*c + (r+c)*(f-1)*f/2 + (f-1)*f*(2*f-1)/6);


     dlf = (f*f-f)/2 + f*r ;
     duf = (f*f-f)/2 + f*c ;
     dlnz += dlf ;
     dunz += duf ;


     dhead_usage +=
  (ceil ((sizeof (double) * ((double) dlf + duf)) / sizeof (Unit)))
  + (ceil ((sizeof (int) * ((double) r + c + f)) / sizeof (Unit))) ;

     if (parent != (-1))
     {

  dtail_usage += (((ceil ((sizeof (Element) * ((double) 1)) / sizeof (Unit))) + (ceil ((sizeof (int) * ((double) (c) + (r))) / sizeof (Unit))) + (ceil ((sizeof (double) * ((double) (c) * (r))) / sizeof (Unit)))) + 1 + (r + c) * (((((sizeof (Tuple) * (1))) + (sizeof (Unit)) - 1) / (sizeof (Unit))))) ;


  Link [i] = Link [parent] ;
  Link [parent] = i ;
     }


     dmax_usage = (((dmax_usage) > (dhead_usage + dtail_usage)) ? (dmax_usage) : (dhead_usage + dtail_usage)) ;

 }


 dtail_usage -= (ceil ((sizeof (double) * ((double) fsize)) / sizeof (Unit))) ;
    }

    dhead_usage = ceil (dhead_usage) ;
    dmax_usage = ceil (dmax_usage) ;
    Symbolic->num_mem_size_est = dhead_usage ;
    Symbolic->num_mem_usage_est = dmax_usage ;
    Symbolic->lunz_bound = dlnz + dunz - n_inner ;







    umf_i_set_stats (
 Info,
 Symbolic,
 dmax_usage,
 dhead_usage,
 flops,
 dlnz,
 dunz,
 dmaxfrsize,
 (double) n_col,
 (double) n_inner,
 (double) maxnrows,
 (double) maxncols,
 (1),
 prefer_diagonal,
 (20 - 40)) ;
# 2335 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    Symbolic->valid = 41937 ;
    *SymbolicHandle = (void *) Symbolic ;
# 2350 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
    free_work (SW) ;

   
                                 ;
   

                                             ;





    umfpack_toc (stats) ;
    Info [17] = stats [0] ;
    Info [15] = stats [1] ;

    return ((0)) ;
}






static void free_work
(
    SWType *SW
)
{
    if (SW)
    {
 SW->Rperm_2by2 = (int *) umf_i_free ((void *) SW->Rperm_2by2) ;
 SW->InvRperm1 = (int *) umf_i_free ((void *) SW->InvRperm1) ;
 SW->Rs = (double *) umf_i_free ((void *) SW->Rs) ;
 SW->Si = (int *) umf_i_free ((void *) SW->Si) ;
 SW->Sp = (int *) umf_i_free ((void *) SW->Sp) ;
 SW->Ci = (int *) umf_i_free ((void *) SW->Ci) ;
 SW->Front_npivcol = (int *) umf_i_free ((void *) SW->Front_npivcol);
 SW->Front_nrows = (int *) umf_i_free ((void *) SW->Front_nrows) ;
 SW->Front_ncols = (int *) umf_i_free ((void *) SW->Front_ncols) ;
 SW->Front_parent = (int *) umf_i_free ((void *) SW->Front_parent) ;
 SW->Front_cols = (int *) umf_i_free ((void *) SW->Front_cols) ;
 SW->Cperm1 = (int *) umf_i_free ((void *) SW->Cperm1) ;
 SW->Rperm1 = (int *) umf_i_free ((void *) SW->Rperm1) ;
 SW->InFront = (int *) umf_i_free ((void *) SW->InFront) ;
    }
}
# 2405 "/home/acer/risc-v-hpc/ports/elmer/umfpack/src/umfpack/umfpack_qsymbolic.c"
static void error
(
    SymbolicType **Symbolic,
    SWType *SW
)
{

    free_work (SW) ;
    umfpack_di_free_symbolic ((void **) Symbolic) ;
    ;
}
