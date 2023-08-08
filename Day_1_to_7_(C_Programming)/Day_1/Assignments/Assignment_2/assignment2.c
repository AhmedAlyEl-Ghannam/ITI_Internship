#include <stdio.h>

/**
	Assignment Description
		Write a code that scan 3 numbers from the user 
		and print them in reversed order
*/

int main(void)
{
	int x, y, z;
	
	printf("Please enter the 1st number: ");
	scanf("%d", &x);
	printf("Please enter the 2nd number: ");
	scanf("%d", &y);
	printf("Please enter the 3rd number: ");
	scanf("%d", &z);
	
	printf("3rd Number: %d\n", z);
	printf("2nd Number: %d\n", y);
	printf("1st Number: %d\n", x);
	
	return 0;
}