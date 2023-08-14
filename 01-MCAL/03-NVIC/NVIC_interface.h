/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 23 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : NVIC           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/* Priority Grouping */
#define 	GROUP_3		0x05FA0300		/* 4 bits for Group */
#define 	GROUP_4		0x05FA0400		/* 3 bits for Group and 1 bit for Sub Priority */
#define 	GROUP_5		0x05FA0500		/* 2 bits for Group and 2 bits for Sub Priority */
#define 	GROUP_6		0x05FA0600		/* 1 bits for Group and 3 bits for Sub Priority */
#define 	GROUP_7		0x05FA0700		/* 0 bits for Group and 4 bits for Sub Priority*/


void MNVIC_voidInit(void);

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);

void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group);

void MNVIC_voidSetPriority2(u8 Copy_u8PeriphralIdx,u8 Copy_u8Priority);


#endif	/* NVIC_INTERFACE_H_ */
