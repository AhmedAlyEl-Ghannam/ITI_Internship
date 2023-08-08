#include <stdio.h>


int fact(int n);

void main(void)
{
	float arr[10] = {0};
	float sum = 0;
	
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Enter a number: ");
		scanf("%f", &arr[i]);
		sum += arr[i];
	}
	
	printf("Sum of array elements = %0.2f\n", sum);
	printf("Average of array elements = %0.2f\n", sum / 10.0);
}
