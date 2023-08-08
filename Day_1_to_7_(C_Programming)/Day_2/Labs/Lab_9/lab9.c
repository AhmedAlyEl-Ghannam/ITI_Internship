#include <stdio.h>

void main(void)
{
	int num = 0;
	printf("Please enter the answer of 3x4: ");
	scanf("%d", &num);
	while (num != 12)
	{
		printf("Incorrect. Try again: ");
		scanf("%d", &num);
	}
	
	printf("Arigato\n");
	
}