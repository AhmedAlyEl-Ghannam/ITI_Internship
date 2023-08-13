#ifndef CARD_H_
#define CARD_H_

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
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);

#endif