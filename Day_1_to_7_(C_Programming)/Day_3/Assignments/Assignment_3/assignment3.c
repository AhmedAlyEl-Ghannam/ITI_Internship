#include <stdio.h>
#include <limits.h>

/**
	Assignment Description
		Write a C code that ask the user to enter
		10 values and save them in an array using a
		for loop. Then print the minimum and the maximum
		of the values.

*/

void main(void)
{
	float element[10];
	float min = INT_MAX;
	float max = INT_MIN;
	
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Enter a number: ");
		scanf("%f", &element[i]);
		
		if (element[i] > max)
			max = element[i];
		
		if (element[i] < min)
			min = element[i];
	}
	
	/**
		Alternatively, we can use bubble sort and just 
		use the first (min) and last (max) values
	*/
	
	printf("Max = %0.1f\n", max);
	printf("Min = %0.1f\n", min);
}
