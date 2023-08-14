/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 25 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : EXTI          		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* Global pointer to Function to hold EXTI0 ISR Address  */
static void (*EXTI0_pvCallBackFunc)(void) = NULL ;

void MEXTI_voidInit(u8 Copy_u8EXTILine, u8 Copy_u8Port, u8 Copy_u8SenseMode)
{
	switch(Copy_u8EXTILine)
	{
		case EXTI0:
		case EXTI1:
		case EXTI2:
		case EXTI3:
			SYSCFG->EXTICR1 &=~((0b1111) << (Copy_u8EXTILine * 4));
			SYSCFG->EXTICR1 |=((Copy_u8Port) << (Copy_u8EXTILine * 4));
			break;
		
		case EXTI4:
		case EXTI5:
		case EXTI6:
		case EXTI7:
			SYSCFG->EXTICR2 &=~((0b1111) << ((Copy_u8EXTILine - 4) * 4));
			SYSCFG->EXTICR2 |=((Copy_u8Port) << ((Copy_u8EXTILine - 4)* 4));
			break;
		
		case EXTI8	:
		case EXTI9	:
		case EXTI10	:
		case EXTI11	:
			SYSCFG->EXTICR3 &=~((0b1111) << ((Copy_u8EXTILine - 8) * 4));
			SYSCFG->EXTICR3 |=((Copy_u8Port) << ((Copy_u8EXTILine - 8)* 4));
			break;
			
		case EXTI12:
		case EXTI13:
		case EXTI14:
		case EXTI15:
			SYSCFG->EXTICR4 &=~((0b1111) << ((Copy_u8EXTILine - 12) * 4));
			SYSCFG->EXTICR4 |=((Copy_u8Port) << ((Copy_u8EXTILine - 12)* 4));
			break;
		
		default:
			break;
	}
	
	switch(Copy_u8SenseMode)
	{
		case RISINGE_EDGE	:
			SET_BIT(EXTI->RTSR,Copy_u8EXTILine);
			break;
		
		case FALLING_EDGE	:
			SET_BIT(EXTI->FTSR,Copy_u8EXTILine);
			break;
		
		case ON_CHANGE_EDGE	:
			SET_BIT(EXTI->RTSR,Copy_u8EXTILine);
			SET_BIT(EXTI->FTSR,Copy_u8EXTILine);
			break;
		
		default:
			break;
	}
	
	/* Enable EXTI Line */
	SET_BIT(EXTI->IMR,Copy_u8EXTILine);
}

void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI->IMR,Copy_u8EXTILine);
	
}

void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI->IMR,Copy_u8EXTILine);
}

void MEXTI_voidSetSWIntTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI->SWIER,Copy_u8EXTILine);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine, u8 Copy_u8SenseMode)
{
	switch(Copy_u8SenseMode)
	{
		case RISINGE_EDGE 	: 	SET_BIT(EXTI->RTSR,EXTI_LINE);	break;
		case FALLING_EDGE	:	SET_BIT(EXTI->FTSR,EXTI_LINE);	break;
		case ON_CHANGE_EDGE :	SET_BIT(EXTI->RTSR,EXTI_LINE);
								SET_BIT(EXTI->FTSR,EXTI_LINE);	break;
		
		default:	break;
	}
	
	/* Enable EXTI Line */
	SET_BIT(EXTI->IMR,Copy_u8EXTILine);
	
}

void EXTI0_voidSetCallBack(void (*Copy_pvEXTI0Func)(void))
{
	EXTI0_pvCallBackFunc = Copy_pvEXTI0Func ;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_pvCallBackFunc();
	
	/* Clear Pending Bit */
	SET_BIT(EXTI->PR,0);
}
