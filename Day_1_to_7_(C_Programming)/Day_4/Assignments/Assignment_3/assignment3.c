#include <stdio.h>

/**
	Assignment Description
		Write a C function that swaps 2 numbers
		using pointers
*/

void swap(int* x, int* y);

void main(void)
{
	int x = 5;
	int y = 9;
	
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	
	swap(&x, &y);
	
	printf("x = %d\n", x);
	printf("y = %d\n", y);
}

void swap(int* x, int* y)
{
	(*x) ^= (*y);
	(*y) ^= (*x);
	(*x) ^= (*y);
}