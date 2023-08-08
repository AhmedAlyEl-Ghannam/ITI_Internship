#include <stdio.h>

// Bubble Sort

void main(void)
{
	int x[10] = {0};
	int i, j;
	for (i = 0; i < 10; i++)
	{
		printf("Enter an element: ");
		scanf("%d", &x[i]);
	}
	
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
	
	for (i = 0; i < 10; i++)
		printf("%d ", x[i]);
	printf("\n");
}