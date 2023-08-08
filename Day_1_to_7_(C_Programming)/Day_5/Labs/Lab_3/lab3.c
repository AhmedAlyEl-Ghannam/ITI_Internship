#include <stdio.h>

/**
	unsigned integers
*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long int u64;

/**
	signed integers
*/
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long int s64;

/**
	floats
*/
typedef float f32;
typedef double f64;
typedef long double f128;

void main(void)
{	
	printf("Size of u8 = %ld\n", sizeof(u8));
	printf("Size of u16 = %ld\n", sizeof(u16));
	printf("Size of u32 = %ld\n", sizeof(u32));
	printf("Size of u64 = %ld\n", sizeof(u64));
	
	printf("Size of s8 = %ld\n", sizeof(s8));
	printf("Size of s16 = %ld\n", sizeof(s16));
	printf("Size of s32 = %ld\n", sizeof(s32));
	printf("Size of s64 = %ld\n", sizeof(s64));
	
	printf("Size of f32 = %ld\n", sizeof(f32));
	printf("Size of f64 = %ld\n", sizeof(f64));
	printf("Size of f128 = %ld\n", sizeof(f128));
	
	u8 x = 128;
	s8 y = 128;
	
	printf("x = %d, y = %d\n", x, y);
}

