#include <stdio.h>

/**
	Assignment Description
		Write a login program in C that ask the user
		to enter his ID and his password, if the ID 
		is correct the system will ask the user to enter
		his password up to 3 times, if he enters the password 
		right the systems welcomes him, if the three times are
		incorrect, the system print No more tries. If the user
		ID is incorrect the system print You are not registered
*/

// copy-pasted code because I did not want to use functions yet
void main(void)
{
	const int id_1 = 1234, pass_1 = 7788;
	const int id_2 = 5678, pass_2 = 5566;
	const int id_3 = 9870, pass_3 = 1122;
	int tries = 3;
	
	int id, pass;
	printf("Please enter your id: ");
	scanf("%d", &id);
	
	switch (id)
	{
		case 1234:
			printf("Please enter your password: ");
			scanf("%d", &pass);
			while (--tries)
			{
				if (pass == pass_1)
				{
					printf("Welcome, Ahmed\n");
					break;
				}
				printf("Try again: ");
				scanf("%d", &pass);
			}
			if (!tries)
				printf("Incorrect password for 3 times. No more tries.\n");
			break;
			
		case 5678:
			printf("Please enter your password: ");
			scanf("%d", &pass);
			while (--tries)
			{
				if (pass == pass_2)
				{
					printf("Welcome, Amr\n");
					break;
				}
				printf("Try again: ");
				scanf("%d", &pass);
			}
			if (!tries)
				printf("Incorrect password for 3 times. No more tries.\n");
			break;
			
		case 9870:
			printf("Please enter your password: ");
			scanf("%d", &pass);
			while (--tries)
			{
				if (pass == pass_3)
				{
					printf("Welcome, Wael\n");
					break;
				}
				printf("Try again: ");
				scanf("%d", &pass);
			}
			if (!tries)
				printf("Incorrect password for 3 times. No more tries.\n");
			break;
		
		default:
			printf("You are not registered.\n");
	}
	
}