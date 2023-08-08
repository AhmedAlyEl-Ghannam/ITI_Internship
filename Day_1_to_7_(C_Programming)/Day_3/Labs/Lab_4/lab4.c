#include <stdio.h>


int fact(int n);

void main(void)
{
	int arr[10] = {0};
	
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Enter a number: ");
		scanf("%d", &arr[i]);
	}
	
	for (i = 9; i >= 0; i--)
		printf("%d\n", arr[i]);
}
