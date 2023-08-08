#include <stdio.h>

/**
	Assignment Description
		Write a C code that ask the user to enter his ID, 
		if the ID is valid it will ask the user to enter his
		password, if the password is correct the program will
		print the user name, if the password is incorrect the
		program will print Incorrect Password. In case of not 
		existing ID, the program will print Incorrect ID
*/

void main(void)
{
	unsigned long int stored_id, stored_pass;
	stored_id = 19015292;
	stored_pass = 7318669;
	
	int id, pass;
	
	printf("Please enter your id: ");
	scanf("%d", &id);
	if (id == stored_id)
	{
		printf("Please enter your password: ");
		scanf("%d", &pass);
		if (pass == stored_pass)
			printf("Welcome, Ahmed\n");
		else
			printf("Incorrect Password\n");
	}
	else
		printf("Incorrect ID\n");
}