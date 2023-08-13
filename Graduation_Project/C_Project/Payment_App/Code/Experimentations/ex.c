#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	unsigned integers
*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long int u64;

/**
	signed integers
*/
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long int s64;

/**
	floats
*/
typedef float f32;
typedef double f64;
typedef long double f128;

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

u8 creditCardNumberVerification_LuhnAlgorithm(char* card_number, u8 size);

EN_cardError_t getCardPAN(ST_cardData_t *cardData);
u8 noSpacesPAN(char *card_number, u8 card_number_len);

void main(void)
{
	//u8 str[50];
	//fgets(str, 50, stdin);
	//fflush(stdin);
	//printf("%s\n%ld\n%c\n", str, sizeof(str), str[24]);
	//verifyInputStrLimits(&str[0]);
	
	//printf("%zu\n", strlen(str));
	
	
	
	ST_cardData_t *card_data = malloc(sizeof(ST_cardData_t));
	
	//char temp[] = "5078 0348 6637 0302";
	//printf("BEFORE: %ld   %s\nAFTER: %hhd   %s\n", sizeof(temp), temp, noSpacesPAN(temp, 20), temp);
	
	u8 haha = getCardPAN(card_data);
	printf("%hhd\n", haha);
	//printf("%s\n", card_data->primaryAccountNumber);
	//printf("%hhd\n", verifyInputStrLimits(&str[0], NAME_MIN, NAME_MAX));
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
		printf("verifyInputStrLimits Loop: %d  %c\n", len, str[len]);
	}

	// len = actual_size + empty_space_counter + null_char
	len = len - empty_space_counter - 1;
	printf("verifyInputStrLimits: %d\n", len);
	
	if (len <= MAX && len >= MIN)
		return len;		
	
	return INVALID_LIMITS;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
	u8 str[50];
	fgets(str, 50, stdin); // must be entered with no spaces
	fflush(stdin);	
	
	u8 haha = verifyInputStrLimits(&str[0], 16, 25);
	
	if (haha != INVALID_LIMITS) // true for valid PAN size (16-19)
	{
		if (creditCardNumberVerification_LuhnAlgorithm(&str[0], haha)) // true if it passed Luhn Algorithm test
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
