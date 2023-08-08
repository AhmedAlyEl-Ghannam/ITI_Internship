#include <stdio.h>

/**
	Assignment Description
		Write a C code that defines a function which takes
		an array as input argument and apply the bubble 
		sorting algorithm on it, then print the result.

*/

void bubble_sort(int* arr, int size);

void main(void)
{
	int arr[10] = {0};
	
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Enter a value: ");
		scanf("%d", &arr[i]);
	}
		
	bubble_sort(&arr[0], 10);
	
	for (i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}

void bubble_sort(int* arr, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if ((*(arr + j)) > (*(arr + j + 1)))
			{
				(*(arr + j)) ^= (*(arr + j + 1));
				(*(arr + j + 1)) ^= (*(arr + j));
				(*(arr + j)) ^= (*(arr + j + 1));
			}
		}
	}
}