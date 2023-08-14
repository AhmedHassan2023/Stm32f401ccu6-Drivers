/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 03 DEC 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : USART           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

typedef struct
{
	u32 volatile SR;
	u32 volatile DR;
	u32 volatile BRR;
	u32 volatile CR1;
	u32 volatile CR2;
	u32 volatile CR3;
	u32 volatile GTPR;
}MUSART;

#define USART1		((volatile MUSART*)0x40011000)





#endif
