#include <stdio.h>

// multiply both and stores the result in arr1
void arr_mul(int* arr1, int* arr2, int size);
// alternatively, we can simply store it in a 3rd array
/* void arr_mul(int* arr1, int* arr2, int* mul, int size); */

void main(void)
{
	int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arr2[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	arr_mul(&arr1[0], &arr2[0], 10);
	
	int i;
	for (i = 0; i < 10; i++)
		printf("%d\n", arr1[i]);
	
	/* int mul[10] = {0};
	arr_mul(&arr1[0], &arr2[0], &mul[0], 10);
	
	for (i = 0; i < 10; i++)
		printf("%d\n", mul[i]); */
}

void arr_mul(int* arr1, int* arr2, int size)
{
	int i;
	for (i = 0; i < size; i++)
		(*(arr1 + i)) *= (*(arr2 + i));
}

/* void arr_mul(int* arr1, int* arr2, int* mul, int size)
{
	int i;
	for (i = 0; i < size; i++)
		(*(mul + i)) = (*(arr1 + i)) * (*(arr2 + i));
} */