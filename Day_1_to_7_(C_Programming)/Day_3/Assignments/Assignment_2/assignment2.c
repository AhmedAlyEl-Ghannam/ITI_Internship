#include <stdio.h>

/**
	Assignment Description
		Write a C program to act as simple calculator, first
		it will ask the user to enter the operation ID, depending
		on the operation, the program will ask the user either to
		enter 1 operand or 2 operands and the program will execute 
		the operation and print the result. Each operation should 
		be implemented in a stand a long function.

*/

void add(void);
void subtract(void);
void multiply(void);
void divide(void);
void my_and(void);
void my_or(void);
void my_not(void);
void my_xor(void);
void my_rem(void);
void inc(void);
void dec(void);

void main(void)
{
	int choice;
	
	printf("1. Add\n");
	printf("2. Subtract\n");
	printf("3. Multiply\n");
	printf("4. Divide\n");
	printf("5. And\n");
	printf("6. Or\n");
	printf("7. Not\n");
	printf("8. Xor\n");
	printf("9. Remainder\n");
	printf("10. Increment\n");
	printf("11. Decrement\n");
	printf("Enter the desired operation ID: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 	add(); 			break;
		case 2: 	subtract(); 	break;
		case 3: 	multiply(); 	break;
		case 4: 	divide(); 		break;
		case 5: 	my_and(); 		break;
		case 6: 	my_or(); 		break;
		case 7: 	my_not(); 		break;
		case 8: 	my_xor(); 		break;
		case 9: 	my_rem(); 		break;
		case 10: 	inc(); 			break;
		case 11: 	dec(); 			break;
		default:	printf("Invalid ID\n");
	}
}

void add(void)
{
	int x, y;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	
	printf("%d + %d = %d\n", x, y, x + y);
}

void subtract(void)
{
	int x, y;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	
	printf("%d - %d = %d\n", x, y, x - y);
}

void multiply(void)
{
	int x, y;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	
	printf("%d * %d = %d\n", x, y, x * y);
}

void divide(void)
{
	float x, y;
	printf("Enter 1st number: ");
	scanf("%f", &x);
	printf("Enter 2nd number: ");
	scanf("%f", &y);
	
	printf("%0.1f * %0.1f = %0.2f\n", x, y, y != 0 ? x / y : y);
}

void my_and(void)
{
	int x, y;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	
	printf("%d & %d = %d\n", x, y, x & y);
}

void my_or(void)
{
	int x, y;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	
	printf("%d | %d = %d\n", x, y, x | y);
}

void my_not(void)
{
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
	
	printf("~%d = %d\n", x, ~x);
}

void my_xor(void)
{
	int x, y;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	
	printf("%d ^ %d = %d\n", x, y, x ^ y);
}

void my_rem(void)
{
	int x, y;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	
	printf("%d %% %d = %d\n", x, y, y != 0 ? x % y : y);
}

void inc(void)
{
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
		
	printf("%d++ = %d\n", x, x + 1);
}


void dec(void)
{
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
		
	printf("%d-- = %d\n", x, x - 1);
}