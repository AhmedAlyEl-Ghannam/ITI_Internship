#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define NULL ((void*)0)

#define SET_INT0_SENSE_MODE() 	switch (copy_u8SenseMode) 					\
								{											\
									case EXTI_SENSE_FALLING_EDGE: 			\
										CLR_BIT(MCUCR, EXTI_MCUCR_ISC00);	\
										SET_BIT(MCUCR, EXTI_MCUCR_ISC01);	\
										break;								\
									case EXTI_SENSE_RISING_EDGE	: 			\
										SET_BIT(MCUCR, EXTI_MCUCR_ISC00);	\
										SET_BIT(MCUCR, EXTI_MCUCR_ISC01);	\
										break;								\
									case EXTI_SENSE_LOW_LEVEL	: 			\
										CLR_BIT(MCUCR, EXTI_MCUCR_ISC00); 	\
										CLR_BIT(MCUCR, EXTI_MCUCR_ISC01);	\
										break;								\
									case EXTI_SENSE_ANY_CHANGE	: 			\
										SET_BIT(MCUCR, EXTI_MCUCR_ISC00);	\
										CLR_BIT(MCUCR, EXTI_MCUCR_ISC01);	\
										break;								\
								}

#endif