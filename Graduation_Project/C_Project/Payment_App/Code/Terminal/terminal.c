#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

u8 isValidDate(u8 *str)
{
	
}


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
	u8 temp[10]; // DD/MM/YYYY
	fgets(temp, 10, stdin);
	fflush(stdin);
	u8 size;
	for (size = 0; temp[size] != '\0'; size++);
	if (size == 10)
	{
		if (isValidDate(&temp[0]))
		{
			u8 i;
			u8 *tran_date = termData->transactionDate;
			for (i = 0; temp[i] != '\0'; i++)
				tran_date[i] = temp[i];
			return TERMINAL_OK
		}
	}
	
	return WRONG_DATE;
}

