/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 27 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SYSTICK           		 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_


/* SYSTICK Timer Interrupt Enable , Options :	1- ENABLED
												2- DISABLED		*/
#define SYSTICK_TICKINT		DISABLED

/* SYSTICK time Clock Source, Options :		1- AHB_CLK
											2- AHB_DIVIDED_BY_CLK	*/
#define SYSTICK_CLKSOURCE		AHB_CLK



#endif	/* SYSTICK_CONFIG_H_ */