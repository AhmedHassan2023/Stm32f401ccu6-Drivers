/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 27 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SYSTICK           		 ***********************/
/* Version 	: 1.10             			 ***********************/
/***************************************************************/

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_


/* SYSTICK Timer Interrupt Enable , Options :	1- ENABLED
												2- DISABLED		*/
#define SYSTICK_TICKINT		DISABLED

/* SYSTICK time Clock Source, Options :		1- AHB_CLK
											2- AHB_DIVIDED_BY_8_CLK*/
#define SYSTICK_CLKSOURCE		AHB_DIVIDED_BY_8_CLK

/* Clock Source : 	1- HSE --> 25 MHZ 
					2- HSI --> 16 MHZ	*/
#define CLK_IN_MHZ		25.00



#endif	/* SYSTICK_CONFIG_H_ */
