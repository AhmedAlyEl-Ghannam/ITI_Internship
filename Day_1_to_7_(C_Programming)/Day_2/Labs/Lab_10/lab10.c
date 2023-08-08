#include <stdio.h>

void main(void)
{
	int num = 0;
	int count = 1;
	printf("Please enter a number to display its multiplication table: ");
	scanf("%d", &num);
	while (count <= 12)
	{
		printf("%d x %d = %d\n", num, count, num * count);
		count++;
	}
	
	/* 
	for (count = 1; count <= 12; count++)
		printf("%d x %d = %d\n", num, count, num * count); 
	*/
	
}