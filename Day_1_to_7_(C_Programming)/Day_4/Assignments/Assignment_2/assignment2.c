#include <stdio.h>

/**
	Assignment Description
		Write a C code that define 3 int variables x, y and z and 3 pointers to
		int p, q and r. Set x, y, z to three distinct values. Set p, q, r to the 
		addresses of x, y, z respectively.
		a- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
		b- Print the message: Swapping pointers.
		c- Execute the swap code: r = p; p = q; q = r;
		d- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
		
		Can you expect the output before you run the program … ?
*/

void main(void)
{
	int x = 1, y = 2, z = 3;
	int* p = &x;
	int* q = &y;
	int* r = &z;
	
	printf("Value of x = %d\n", x); // 1
	printf("Value of y = %d\n", y); // 2
	printf("Value of z = %d\n", z); // 3
	printf("Value of p = %p\n", p); // address of x
	printf("Value of q = %p\n", q); // address of y
	printf("Value of r = %p\n", r); // address of z
	printf("Value of p = %d\n", *p); // 1
	printf("Value of q = %d\n", *q); // 2
	printf("Value of r = %d\n", *r); // 3
	
	printf("Swapping pointers...\n");
	
	r = p; // r -> x
	p = q; // p -> y
	q = r; // q -> x
	
	// no dereferencing/changing x, y, z so they remain unchanged
	printf("Value of x = %d\n", x); // 1
	printf("Value of y = %d\n", y); // 2
	printf("Value of z = %d\n", z); // 3
	printf("Value of p = %p\n", p); // address of y
	printf("Value of q = %p\n", q); // address of x
	printf("Value of r = %p\n", r); // address of x
	printf("Value of p = %d\n", *p); // 2
	printf("Value of q = %d\n", *q); // 1
	printf("Value of r = %d\n", *r); // 1
}
