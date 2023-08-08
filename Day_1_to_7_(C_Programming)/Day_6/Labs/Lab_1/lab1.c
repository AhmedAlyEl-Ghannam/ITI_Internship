#include <stdio.h>
#include "STD_Types.h"

struct employee
{
	u16 salary;
	u16 bonus;
	u16 deduction;
};

void main(void)
{
	struct employee Ahmed, Amr, Waleed;
	u16 budget = 0;
	
	printf("Please enter Ahmed's salary: ");
	scanf("%hd", &(Ahmed.salary));
	printf("Please enter Ahmed's bonus: ");
	scanf("%hd", &(Ahmed.bonus));
	printf("Please enter Ahmed's deduction: ");
	scanf("%hd", &(Ahmed.deduction));
	
	budget += Ahmed.salary + Ahmed.bonus - Ahmed.deduction;
	
	printf("Please enter Amr's salary: ");
	scanf("%hd", &(Amr.salary));
	printf("Please enter Amr's bonus: ");
	scanf("%hd", &(Amr.bonus));
	printf("Please enter Amr's deduction: ");
	scanf("%hd", &(Amr.deduction));
	
	budget += Amr.salary + Amr.bonus - Amr.deduction;
	
	printf("Please enter Waleed's salary: ");
	scanf("%hd", &(Waleed.salary));
	printf("Please enter Waleed's bonus: ");
	scanf("%hd", &(Waleed.bonus));
	printf("Please enter Waleed's deduction: ");
	scanf("%hd", &(Waleed.deduction));
	
	budget += Waleed.salary + Waleed.bonus - Waleed.deduction;
	
	printf("Total value needed is: %hd\n", budget);
}

