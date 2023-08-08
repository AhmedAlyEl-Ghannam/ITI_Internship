#include <stdio.h>

/**
	Assignment Description
		Write a code that takes 2 numbers and print their 
		summation, subtraction, anding, oring, and Xoring
*/

int main(void)
{
	int x, y;
	
	printf("Please enter a value for x: ");
	scanf("%d", &x);
	printf("Please enter a value for y: ");
	scanf("%d", &y);
	
	printf("x + y = %d\n", x + y);
	printf("x - y = %d\n", x - y);
	printf("x & y = %d\n", x & y);
	printf("x | y = %d\n", x | y);
	printf("x ^ y = %d\n", x ^ y);
	
	return 0;
}