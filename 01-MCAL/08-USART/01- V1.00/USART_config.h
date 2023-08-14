/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 03 DEC 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : USART           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/* Baud Rate Register Value Options : 	1- 9600   --> 0xA2C
 * 										2- 115200 --> 0x   */
#define USART1_BUAD_RATE_VALUE 		0xA2C

#define USART1_TIME_OUT				50000

#endif	/* USART_CONFIG_H_ */
