#include <stdio.h>
#include <stdlib.h>
#include "Luhn.h"


// detect 16-number credit card
// (0-15) start from index 1 until 13 (last digit is not changed)
// checked: 1 3 5 7 9 11 13
// double each of these digits
// if any of these results is larger than 9, add its digit together to form a new number
// take the sum of all digits (modified 1-13) && (unmodified 0-15 disregarding old 1-13 values) 
// if the sum%10 == 0, then the account is possibly valid
// else, it is not

s8 creditCardNumberVerification_LuhnAlgorithm(char* card_number)
{
	if (card_number == NULL)
		return -1;
	
	u8 digit_sum = 0;
	u8 temp = 0;
	
	u16 card_number_len = calculate_StringLength(&card_number[0]);
	
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

u16 calculate_StringLength(char* str)
{
	u16 len;
	for (len = 0; str[len] != '\0'; len++);
	return len;
}