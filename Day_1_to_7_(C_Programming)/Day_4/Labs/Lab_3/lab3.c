#include <stdio.h>

int sum(int* x, int* y);

void main(void)
{
	int x, y;
	printf("Please enter 1st value: ");
	scanf("%d", &x);
	printf("Please enter 2nd value: ");
	scanf("%d", &y);
	
	printf("Sum = %d\n", sum(&x, &y));
}

int sum(int* x, int* y)
{
	return ((*x) + (*y));
}
