#include <stdio.h>

void main(void)
{
	int id;
	printf("Please enter your ID: ");
	scanf("%d", &id);
	
	switch (id)
	{
		case 1234:
			printf("Welcome Ahmed\n");
			break;
			
		case 5678:
			printf("Welcome Youssef\n");
			break;
			
		case 1145:
			printf("Welcome Mina\n");
			break;
			
		default:
			printf("Wrong ID\n");
			break;
	}
}