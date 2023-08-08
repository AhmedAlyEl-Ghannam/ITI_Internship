#include <stdio.h>

void main(void)
{
	int x = 1, y = 2;
	int z = x+++ +y; // 1 + 2 = 3 (x = 2)
	int v = x++ + ++x; // 2 + 4 = 6 (x = 3 then x = 4)
	printf("%d\n", z);
	printf("%d\n", v);
}