#include <stdio.h>

void sum_sub(int* x, int* y);

void main(void)
{
	int x, y;
	printf("Please enter 1st value: ");
	scanf("%d", &x);
	printf("Please enter 2nd value: ");
	scanf("%d", &y);
	
	sum_sub(&x, &y);
	
	printf("Sum = %d\n", x);
	printf("Sub = %d\n", y);
}

void sum_sub(int* x, int* y)
{
	int sum, sub;
	
	sum = (*x) + (*y);
	sub = (*x) - (*y);
	
	(*x) = sum;
	(*y) = sub;
}
