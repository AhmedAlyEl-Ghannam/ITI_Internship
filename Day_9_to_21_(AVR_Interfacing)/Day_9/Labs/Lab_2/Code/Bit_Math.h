/*
 * Bit_Math.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(X, POS) (X |= (0x01 << POS))
#define CLR_BIT(X, POS) ( X &= ~(0x01 << POS) )
#define TOG_BIT(X, POS) ( X ^= (0x01 << POS) )
#define GET_BIT(X, POS) ( (X >> POS) & 0x01 )

#endif /* BIT_MATH_H_ */
