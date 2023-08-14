/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 27 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SYSTICK           		 ***********************/
/* Version 	: 1.10             			 ***********************/
/***************************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/* Tick Type:	1- MICR_SEC
 * 				2- MILL_SEC
 * 				3- SEC
 * 								*/
#define MICRO_SEC		0
#define MILLI_SEC		1
#define SEC				2


/* Global Variable */
void (*Callback)(void);

void MSTK_voidInit(void);

void MSTK_voidEnable(void);

void MSTK_voidDisable(void);

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks, u8 Copy_u8TickType);

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,u8 Copy_u8TickType, void (*Copy_pvSTKFunc)(void));

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,u8 Copy_u8TickType, void (*Copy_pvSTKFunc)(void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);



#endif	/* SYSTICK_INTERFACE_H_ */
