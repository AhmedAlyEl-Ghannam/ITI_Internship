#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

typedef struct ST_cardData_t
{
	u8 cardHolderName[25];
	u8 primaryAccountNumber[20];
	u8 cardExpirationDate[6];
} ST_cardData_t;

typedef enum EN_cardError_t
{
	CARD_OK = 1, WRONG_NAME = -1, WRONG_EXP_DATE = -2, WRONG_PAN = -3
} EN_cardError_t;

typedef enum cardData_sizeLimits_t
{
	INVALID_LIMITS = 0, VALID_LIMITS = 1, NAME_MAX = 24, NAME_MIN = 20, PAN_MAX = 19, PAN_MIN = 16, EXP_LIMIT = 5
} cardData_sizeLimits_t;

u8 verifyInputStrLimits(char *str, cardData_sizeLimits_t MIN, cardData_sizeLimits_t MAX);

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);

void main(void)
{
	//u8 str[50];
	//fgets(str, 50, stdin);
	//fflush(stdin);
	//printf("%s\n%ld\n%c\n", str, sizeof(str), str[24]);
	//verifyInputStrLimits(&str[0]);
	
	//printf("%zu\n", strlen(str));
	
	
	
	ST_cardData_t *card_data = malloc(sizeof(ST_cardData_t));
	
	u8 haha = getCardHolderName(card_data);
	printf("%hhd\n", haha);
	//printf("%hhd\n", verifyInputStrLimits(&str[0], NAME_MIN, NAME_MAX));
}

// how to detect the limits of card name size?
// make the variable a bit longer?
// if I encounter '\0' before the lower limit then it's invalid
// if I encounter an empty space after the upper limit it's invalid
// otherwise, it is accepted
/** Auxiliary Functions */
u8 verifyInputStrLimits(char *str, cardData_sizeLimits_t MIN, cardData_sizeLimits_t MAX)
{
	if (str == NULL)
		return INVALID_LIMITS;
	
	int len = 0;
	int empty_space_counter = 0;
	
	for (len = 0; str[len] != '\0'; len++)
	{
		if (str[len] == ' ')
			empty_space_counter++;
	}

	// len = actual_size + empty_space_counter + null_char
	len = len - empty_space_counter - 1;
	
	if (len <= MAX && len >= MIN)
		return VALID_LIMITS;
	
	return INVALID_LIMITS;
}


// function that reads card holder name and acts according to the input
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
	u8 str[50];
	fgets(str, 50, stdin);
	fflush(stdin);	
	
	u8 *temp = cardData->cardHolderName;
	if (verifyInputStrLimits(&str[0], NAME_MIN, NAME_MAX) == VALID_LIMITS) // true for valid name
	{
		int i;
		for (i = 0; str[i] != '\0'; i++)
			temp[i] = str[i];		
		
		return CARD_OK;
	}
	
	return WRONG_NAME;
}