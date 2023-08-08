#include <stdio.h>

/**
	Assignment Description
		Write a c program that draw a pyramid of stars 
		with height entered by the user
						*	
					   *** 
					  ***** 
*/

void main(void)
{
	int height;
	printf("Enter the height of the pyramid: ");
	scanf("%d", &height);
	
	int i, j, k; // loop counters
	
	for (i = 1; i <= height; i++)
	{
		for (j = 1; j <= (height - i); j++)
			printf(" "); // height - i times
		
		for (k = 1; k <= (i * 2 - 1); k++)
			printf("*"); // n times (n is odd = i * 2 - 1)
		
		printf("\n"); // at the end of each line
	}
	
}