#include <stdio.h>

/**
	Extra Assignment Description
		Swap the 1st and last byte of an integer using pointers
*/

void byte_swap(int* x, size_t n);

void main(void)
{
	int x = 0xF659; // 0000 0000 0000 0000 1111 0110 0101 1001
	printf("X before byte swap = %d\n%ld\n", x, sizeof(x)); // 4 == 1 nibble
	byte_swap(&x, sizeof(x));
	printf("X after byte swap = %d\n", x);
}

void byte_swap(int* x, size_t n)
{
	int b0 = ((*x) & 0xFF) << ((n - 1)*8);
	int b1 = (*x) & (0xFF << ((n - 2)*8));
	int b2 = (*x) & (0xFF << ((n - 3)*8));
	int b3 = ((*x) & (0xFF << ((n - 1)*8))) >> ((n - 1)*8);
	(*x) = b0 | b1 | b2 | b3;
}