/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 25 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : EXTI          		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define RISINGE_EDGE		0
#define FALLING_EDGE		1
#define ON_CHANGE_EDGE		2

#define EXTI0		0
#define EXTI1		1
#define EXTI2		2
#define EXTI3		3
#define EXTI4		4
#define EXTI5		5
#define EXTI6		6
#define EXTI7		7
#define EXTI8		8
#define EXTI9		9
#define EXTI10		10
#define EXTI11		11
#define EXTI12		12
#define EXTI13		13
#define EXTI14		14
#define EXTI15		15

void MEXTI_voidInit(u8 Copy_u8EXTILine, u8 Copy_u8Port, u8 Copy_u8SenseMode);

void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine);

void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);

void MEXTI_voidSetSWIntTrigger(u8 Copy_u8EXTILine);

void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine, u8 Copy_u8SenseMode);

void EXTI0_voidSetCallBack(void (*Copy_pvEXTI0Func)(void));



#endif	/* EXTI_INTERFACE_H_ */
