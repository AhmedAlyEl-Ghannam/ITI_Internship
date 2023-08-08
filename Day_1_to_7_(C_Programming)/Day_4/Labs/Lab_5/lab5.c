#include <stdio.h>
// calculate the sum of an array using a pointer to its 1st element
int arr_sum(int *arr, int size);

void main(void)
{
	int arr[10] = {0};
	
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Enter a value: ");
		scanf("%d", &arr[i]);
	}
	
	printf("Sum = %d\n", arr_sum(&arr[0], 10));
}

int arr_sum(int *arr, int size)
{
	int sum = 0;
	int i;
	for (i = 0; i < size; i++)
		sum += (*(arr + i)); // sum += arr[i];
	
	return sum;
}