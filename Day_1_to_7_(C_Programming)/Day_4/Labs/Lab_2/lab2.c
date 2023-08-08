#include <stdio.h>

void main(void)
{
	int x = 10;
	printf("X before change: %d\n", x);
	int *ptr = &x;
	*ptr = 20;
	printf("X after change: %d\n", x);
}