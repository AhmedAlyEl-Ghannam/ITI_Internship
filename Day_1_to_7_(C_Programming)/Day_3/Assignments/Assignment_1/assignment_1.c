#include <stdio.h>

/**
	Assignment Description
		Write a C program the implement 2 function:
			1- Function to get the maximum of 4 values
			2- Function to get the minimum of 4 values
		The program will ask the user first to enter
		the 4 values, then print the maximum number and 
		minimum number of them.
*/

int myMax(int a, int b);
int myMin(int a, int b);

void main(void)
{
	int x, y, z, m;
	printf("Enter the 1st number: ");
	scanf("%d", &x);
	
	
	printf("Enter the 2nd number: ");
	scanf("%d", &y);
	
	
	printf("Enter the 3rd number: ");
	scanf("%d", &z);
	
	
	printf("Enter the 4th number: ");
	scanf("%d", &m);
	
	printf("Max = %d\n", myMax(myMax(x, y), myMax(z, m)));
	printf("Min = %d\n", myMin(myMin(x, y), myMin(z, m)));
}

int myMax(int a, int b)
{
	return ( (a > b) ? a : b );
}

int myMin(int a, int b)
{
	return ( (a < b) ? a : b );
}