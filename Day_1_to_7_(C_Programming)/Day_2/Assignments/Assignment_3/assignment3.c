#include <stdio.h>

/**
	Assignment Description
		Write a code that will ask the user to enter 3 numbers, 
		the program will print the maximum number of them.
*/

void main(void)
{
	int num1, num2, num3;
	
	printf("Please enter a number: ");
	scanf("%d", &num1);
	printf("Please enter a number: ");
	scanf("%d", &num2);
	printf("Please enter a number: ");
	scanf("%d", &num3);
	
	int max = num1;
	
	if (max <= num2)
		max = num2;
	
	if (max <= num3)
		max = num3;
	
	printf("Maximum number is %d\n", max);
}