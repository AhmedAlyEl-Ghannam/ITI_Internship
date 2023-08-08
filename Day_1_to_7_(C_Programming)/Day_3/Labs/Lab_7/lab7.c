#include <stdio.h>

// Binary Search
void main(void)
{
	int x[10] = {0};
	int i, j;
	for (i = 0; i < 10; i++)
	{
		printf("Enter an element: ");
		scanf("%d", &x[i]);
	}
	
	// Bubble sort
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10-i-1; j++)
		{
			// > for ascending 
			// < for descending
			if (x[j] > x[j + 1])
			{
				x[j] ^= x[j + 1];
				x[j + 1] ^= x[j];
				x[j] ^= x[j + 1];
			}
		}
	}
	
	int search_for;
	printf("Enter a value to search for: ");
	scanf("%d", &search_for);
	
	// actual searching
	int start = 0, end = 9, mid, flag = 0;
	while (start <= end)
	{
		mid = start + ((end - start) / 2) ;
		if (search_for == x[mid])
		{
			flag ^= 1;
			break;
		}
		else if (search_for < x[mid])
			end = mid - 1;
		else // (search_for > x[mid])
			start = mid + 1;
	}
	
	if (flag)
		printf("Value exists\n");
	else
		printf("Value not found\n");
}