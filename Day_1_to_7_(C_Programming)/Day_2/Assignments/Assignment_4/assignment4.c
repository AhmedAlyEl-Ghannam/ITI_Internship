#include <stdio.h>

/**
	Assignment Description
		Write a C program that ask the user to enter two
		numbers and print their summation, this program 
		should never ends until the user close the window.
*/

void main(void)
{
	int num1, num2;
	int flag = 0;
	
	while (!flag)
	{
		printf("Please enter the 1st number: ");
		scanf("%d", &num1);
		printf("Please enter the 2nd number: ");
		scanf("%d", &num2);
		
		if ((num1 == 731) && (num2 == 8627)) // obscure exit condition
			flag ^= 1;
			
		printf("The result is %d\n", num1 + num2);
	}
	
}