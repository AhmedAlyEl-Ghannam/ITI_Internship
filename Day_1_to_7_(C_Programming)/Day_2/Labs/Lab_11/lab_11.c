#include <stdio.h>

void main(void)
{
	int num = 0;
	int fact = 1;
	
	printf("Please enter a number to calculate its factorial: ");
	scanf("%d", &num);
	
	do
	{
		if (num <= 1)
			break;
		
		fact *= num;
	} while (--num > 1);
	
	printf("%d\n", fact);
}