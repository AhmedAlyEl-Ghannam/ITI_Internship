#include <stdio.h>

/**
	Assignment Description
		Write a C code that ask the user to enter 10 numbers, 
		then ask him to enter another number to search on it in 
		the 10 numbers and print its location in case it is found. 
		In case the number is not found, it will print number no 
		exist.
*/

void main(void)
{
	int num[10] = {0};
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Please enter a number: ");
		scanf("%d", &num[i]);
	}
	
	int search = 0;
	printf("Enter a value to search for: ");
	scanf("%d", &search);
	
	switch (search)
	{
		case num[0]:
			printf("Value found at element number %d\n", 1);
			break;
			
		case num[1]:
			printf("Value found at element number %d\n", 2);
			break;
			
		case num[2]:
			printf("Value found at element number %d\n", 3);
			break;
			
		case num[3]:
			printf("Value found at element number %d\n", 4);
			break;
			
		case num[4]:
			printf("Value found at element number %d\n", 5);
			break;
			
		case num[5]:
			printf("Value found at element number %d\n", 6);
			break;
		
		case num[6]:
			printf("Value found at element number %d\n", 7);
			break;
		
		case num[7]:
			printf("Value found at element number %d\n", 8);
			break;
		
		case num[8]:
			printf("Value found at element number %d\n", 9);
			break;
		
		case num[9]:
			printf("Value found at element number %d\n", 10);
			break;
			
		default:
			printf("Number does not exist.\n");
	
	}
}