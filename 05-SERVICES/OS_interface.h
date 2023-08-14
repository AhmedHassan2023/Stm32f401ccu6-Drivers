/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 10 NOV 2022				 ***********************/
/* Layer   	: SERVICES           		 ***********************/
/* SWC      : OS          				 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Priodicity, void (*ptr)(void) );

void OS_voidStart(void);

#endif	/* OS_INTERFACE_H_ */