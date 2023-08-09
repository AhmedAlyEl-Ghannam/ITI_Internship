#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long int u64;

typedef struct
{
	u8 x;
	u32 z;
	u16 y;
	u64 d;
} students;

typedef struct
{
	u16 m:16;
	u8  x:2;
	u16 y:6;
	u32 z:4;
	u32 f:4;
	u32 o:4;
	u32 p:4;
} teachers;

void main(void)
{
	printf("%d\n", sizeof(students)); // 24
	// assume the width is the largest element = 8
	// x 0->3 (1 + 3 padding)
	// z 4->7 (4)
	// y 8->15 (2 + 6 padding) 
	// (rest of the row width cannot hold 8 bytes so they are padded instead)
	// d 16->23 (8)
	// Total = 24 bytes
	printf("%d\n", sizeof(teachers)); // 4
	// the largest defined type is u32 which is 4 bytes
	// as long as the initially-allocated 4 bytes are enough
	// for all the defined bitfields, the size will always remain 4 bytes
	// upon defining a new variable that makes the size exceed 4 bytes, a new
	// frame of 4 bytes is allocated to accomodate for it
	// MAKING THE SIZE 8 bytes
}