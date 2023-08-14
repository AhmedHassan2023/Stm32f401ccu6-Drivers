/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 27 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SYSTICK           		 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef SYSYTICK_PRIVATE_H_
#define SYSYTICK_PRIVATE_H_

struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
	
}SYSTICK_t;

#define STK			((volatile SYSTICK_t *)0xE000E010)

/* CTRL Register Bits */
#define STK_CTRL_ENABLE_BIT		0
#define STK_CTRL_TICKINT_BIT	1
#define STK_CTRL_CLKSOURCE_BIT	2
#define STK_CTRL_COUNTFLAG		16

/* SYSTICK Timer Interrupt Options */
#define ENABLED		1
#define DISABLED	2

/* SYSTICK Timer Clock Source Options */
#define AHB_CLK					1
#define AHB_DIVIDED_BY_CLK		2

/* Interval Options */
#define STK_SINGLE_INTERVAL		0
#define STK_PERIODIC_INTERVAL	1

#endif	/* SYSYTICK_PRIVATE_H_ */