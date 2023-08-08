#include <stdio.h>

void main(void)
{
	int x, y;
	printf("Please enter the 1st number: ");
	scanf("%d", &x);
	printf("Please enter the 2nd number: ");
	scanf("%d", &y);
	printf("x + y = %d\nx * y = %d\n", x + y, x * y);
}