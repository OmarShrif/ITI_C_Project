#ifndef PLATFORM_TYPES_H_INCLUDED
#define PLATFORM_TYPES_H_INCLUDED

#define CPU_TYPES_8      8
#define CPU_TYPES_16     16
#define CPU_TYPES_32     32
#define CPU_TYPES_64     64

/***********************************************/

#define CPU_TYPE (CPU_TYPES_64)

/***********************************************/

#if   (CPU_TYPE == CPU_TYPES_8)

typedef unsigned char       boolean ;

typedef unsigned char       u8      ;
typedef unsigned short      u16     ;
typedef unsigned long       u32     ;

typedef signed char         s8      ;
typedef signed short        s16     ;
typedef signed long         s32     ;

typedef float               f32     ;

#elif (CPU_TYPE == CPU_TYPES_16)

typedef unsigned char       boolean ;

typedef unsigned char       u8      ;
typedef unsigned short      u16     ;
typedef unsigned long       u32     ;
typedef unsigned long long  u64     ;

typedef signed char         s8      ;
typedef signed short        s16     ;
typedef signed long         s32     ;
typedef signed long long    s64     ;

typedef float               f32     ;
typedef double              f64     ;

#elif (CPU_TYPE == CPU_TYPES_32)

typedef unsigned char       boolean ;

typedef unsigned char       u8      ;
typedef unsigned short      u16     ;
typedef unsigned long       u32     ;
typedef unsigned long long  u64     ;

typedef signed char         s8      ;
typedef signed short        s16     ;
typedef signed long         s32     ;
typedef signed long long    s64     ;

typedef float               f32     ;
typedef double              f64     ;

#elif (CPU_TYPE == CPU_TYPES_64)

typedef unsigned char       boolean ;

typedef unsigned char       u8      ;
typedef unsigned short      u16     ;
typedef unsigned int        u32     ;
typedef unsigned long long  u64     ;

typedef signed char         s8      ;
typedef signed short        s16     ;
typedef signed int          s32     ;
typedef signed long long    s64     ;

typedef float               f32     ;
typedef double              f64     ;
typedef long double         f128    ;

#endif

/***********************************************/

#endif // PLATFORM_TYPES_H_INCLUDED
