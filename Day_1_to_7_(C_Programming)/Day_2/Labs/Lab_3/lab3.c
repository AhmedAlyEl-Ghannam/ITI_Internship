#include <stdio.h>

void main(void)
{
	int num = 0;
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	// can also mask the whole number except for LSB
	// and test it using bitwise operators
	// (num & 1) = 1 -> odd
	// (num & 1) = 0 -> even
	
	if (num % 2 == 0)
	{
		printf("Your number is Even\n");
	}
	else // num%2=1
	{
		printf("Your number is odd\n");
	}
	
	; // this stray semicolon is considered an empty line
}