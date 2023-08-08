#include <stdio.h>

int main(void)
{
	int x = 3;
	// evaluate from right to left (Basically undefined behaviour)
	// 3 (x = 4), 5 (x = 5), 6 (x = 6), 6 (x = 7), 7
	printf("%d, %d, %d, %d, %d \n", x, ++x, x++, x++, ++x);
	return 0;
}