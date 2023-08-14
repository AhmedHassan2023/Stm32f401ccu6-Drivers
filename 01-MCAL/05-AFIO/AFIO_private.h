/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 25 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : AFIO          		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

typedef {
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
	
	
}AFIO_t;

#define AFIO		((volatile AFIO_t *)0x40010000)


#endif	/* AFIO_PRIVATE_H_ */