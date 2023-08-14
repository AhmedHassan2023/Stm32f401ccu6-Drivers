/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 03 DEC 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : USART           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


void MUSART_voidInit(void);

void MUSART_voidSendSynch(u8 Copy_u8Data);

u8 MUSART_u8ReceiveData(void);


#endif