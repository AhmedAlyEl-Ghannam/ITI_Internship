#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "STD_Types.h"

typedef struct ST_terminalData_t
{
	f32 transAmount;
	f32 maxTransAmount;
	u8 transactionDate[11];
} ST_terminalData_t;

typedef enum EN_terminalError_t
{
	TERMINAL_OK,
	WRONG_DATE,
	EXPIRED_CARD,
	INVALID_CARD,
	INVALID_AMOUNT,
	INVALID_MAX_AMOUNT
} EN_terminalError_t;

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
EN_terminalError_t getTransationAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, f32 maxAmount);
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData); // optional (I already implemented it in Card Module—Luhn)

#endif