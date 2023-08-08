#include <stdio.h>

void main(void)
{
	int num;
	int sum = 0;
	int i;
	
	for (i = 0; i < 10; i++)
	{
		printf("Please enter a number: ");
		scanf("%d", &num);
		sum += num;
	}
	
	printf("Sum = %d\n", sum);
	printf("Average = %0.1f\n", sum / 10.0);
	
}