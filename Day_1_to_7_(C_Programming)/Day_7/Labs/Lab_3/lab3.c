#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

void main(void)
{
	u16* ptr = NULL;
	
	// dynamic array size
	u8 size;
	printf("Enter the number of elements: ");
	scanf("%hhd", &size);
	
	// allocating memory for the dynamic array
	ptr = (u16*)malloc(sizeof(u16) * size);
	
	if (ptr == NULL)
	{
		printf("Memory was not allocated successfully!\n");
		return;
	}
	
	// storing elements
	int i, j;
	for (i = 0; i < size; i++)
		scanf("%hd", (ptr + i));
	
	// bubble sorting
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				ptr[j] ^= ptr[j + 1];
				ptr[j + 1] ^= ptr[j];
				ptr[j] ^= ptr[j + 1];
			}
		}
	}
	
	// printing 
	for (i = 0; i < size; i++)
		printf("%d ", ptr[i]);
	printf("\n");
	
	free(ptr);
}
