/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 25 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : EXTI          		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct
 {
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;

typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 CMPCR;
		
}SYSCFG_t;

/* Pointer to EXTI Base Address */
#define EXTI		((volatile EXTI_t *)0x40013C00)

/* Pointer to System Configuration Controller Base Address */
#define SYSCFG 		((volatile SYSCFG_t *)0x40013800)

#define LINE0		0
#define LINE1		1
#define LINE2		2
#define LINE3		3
#define LINE4		4
#define LINE5		5
#define LINE6		6




#endif	/* EXTI_PRIVATE_H_ */
