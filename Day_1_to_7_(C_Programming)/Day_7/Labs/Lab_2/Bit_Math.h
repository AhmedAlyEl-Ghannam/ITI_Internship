#ifndef BIT_MATH_H_
#define BIT_MATH_H_

// POS starts from 0 ###

#define CLR_BIT(VAR, POS) 	 (  VAR &= ~(1<<POS) )
#define SET_BIT(VAR, POS) 	  ( VAR |= (1<<POS) )
#define TOG_BIT(VAR, POS) 	  ( VAR ^= (1<<POS) )
#define GET_BIT(VAR, POS) 	( (VAR >> POS) & 0x01 )

#endif