#include <stdio.h>

int max(int a, int b);

void main(void)
{
	int a, b;
	printf("Enter the 1st number: ");
	scanf("%d", &a);
	fflush(stdin);
	printf("Enter the 2nd number: ");
	scanf("%d", &b);
	
	printf("Max = %d\n", max(a, b));
}

int max(int a, int b)
{
	return ( (a > b) ? a : b );
}