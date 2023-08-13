#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "card.h"

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
	
	u16 len = 0;
	u16 empty_space_counter = 0;
	
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

u8 creditCardNumberVerification_LuhnAlgorithm(char* card_number, u8 card_number_len)
{
	u8 digit_sum = 0;
	u8 temp = 0;
	
	// adding unchanged values (even-index + last digit)
	int i;
	for (i = 0; i < (card_number_len - 1); i++)
	{
		if (i % 2 != 0) // add unchanged values
			digit_sum += card_number[i] - '0';
		else // doubled digits
		{
			temp = (card_number[i] - '0') * 2;
			if (temp > 9)
			{
				while (temp)
				{
					digit_sum += (temp % 10);
					temp /= 10;
				}
			}
			else
				digit_sum += temp;
		}
	}
	
	// adding the last digit
	digit_sum += card_number[card_number_len - 1] - '0';
	
	if (digit_sum % 10 == 0)
		return 1; // indicates valid card number
	else
		return 0; // indicates invalid card number
}

u8 noSpacesPAN(char *card_number, u8 card_number_len)
{
	char *str = card_number;
	int i;
    int count = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; 
    //str[count] = '\0';
	return count;
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
		u16 i;
		for (i = 0; str[i] != '\0'; i++)
			temp[i] = str[i];		
		
		return CARD_OK;
	}
	
	return WRONG_NAME;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
	u8 str[50];
	fgets(str, 50, stdin);
	fflush(stdin);	
	
	u8 *temp = cardData->cardExpirationDate;
	if (verifyInputStrLimits(&str[0], EXP_LIMIT, EXP_LIMIT) == VALID_LIMITS) // true for valid expiry date
	{
		u16 i;
		for (i = 0; str[i] != '\0'; i++)
			temp[i] = str[i];		
		
		return CARD_OK;
	}
	
	return WRONG_EXP_DATE;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
	u8 str[50];
	fgets(str, 50, stdin); // must be entered with no spaces
	fflush(stdin);	
	
	u8 size = verifyInputStrLimits(&str[0], 16, 25);
	
	if (size != INVALID_LIMITS) // true for valid PAN size (16-19)
	{
		if (creditCardNumberVerification_LuhnAlgorithm(&str[0], size)) // true if it passed Luhn Algorithm test
		{
			u8 *temp = cardData->primaryAccountNumber;
			u16 i;
			for (i = 0; str[i] != '\0'; i++)
				temp[i] = str[i];		
		
			return CARD_OK;
		}
	}
	
	return WRONG_PAN;
}
