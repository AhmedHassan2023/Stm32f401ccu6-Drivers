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
	volatile u32 SR;			/* Status Register 						*/
	volatile u32 DR;			/* Data Register 						*/
	volatile u32 BRR;			/* Baud Rate Register 					*/
	volatile u32 CR1;			/* Control Register 1					*/
	volatile u32 CR2;			/* Control Register 2					*/
	volatile u32 CR3;			/* Control Register 3					*/
	volatile u32 GTPR;			/* Guard Time and Prescaler Register	*/
	
}USART_t;

#define USART1		((volatile USART_t*)0x40011000)


/* Status Register Bits */
#define USART1_SR_PE		0		/* Parity Error 					*/
#define USART1_SR_FE		1		/* Framing Error 					*/
#define USART1_SR_NF		2		/* NOise Detected Flag 				*/
#define USART1_SR_ORE		3		/* Overrun Flag						*/
#define USART1_SR_IDLE		4		/* IDLE Line Detected 				*/
#define USART1_SR_RXNE		5		/* Read Data Register Not Empty 	*/
#define USART1_SR_TC		6		/* Transmission Complete 			*/
#define USART1_SR_TXE		7		/* Transmit Data Register Empty		*/
#define USART1_SR_LBD		8		/* LIN Break Detection Flag			*/
#define USART1_SR_CTS		8		/* CTS Flag							*/


/* Control Register 1 Bits */
#define USART1_CR1_SBK		0		/* Send Break								*/
#define USART1_CR1_RWU		1		/* Receiver Wakeup							*/
#define USART1_CR1_RE		2		/* Receiver Enable 							*/
#define USART1_CR1_TE		3		/* Transmitter Enable						*/
#define USART1_CR1_IDLEIE	4		/* IDLE Interrupt Enable 					*/
#define USART1_CR1_RXNEIE	5		/* RXNE Interrupt Enable 					*/
#define USART1_CR1_TCIE		6		/* Transmission Complete Interrupt Enable 	*/
#define USART1_CR1_TXEIE	7		/* TXE Interrupt Enable 					*/
#define USART1_CR1_PEIE		8		/* PE Interrupt Enable						*/
#define USART1_CR1_PS		9		/* Parity Selection							*/
#define USART1_CR1_PCE		10		/* Parity Control Enable					*/
#define USART1_CR1_WAKE		11		/* Wakeup Method							*/
#define USART1_CR1_M		12		/* Word Length 								*/
#define USART1_CR1_UE 		13		/* USART Enable 							*/
#define USART1_CR1_OVER8	15		/* Over Sampling Mode						*/

#endif	/* USART_PRIVATE_H_ */
