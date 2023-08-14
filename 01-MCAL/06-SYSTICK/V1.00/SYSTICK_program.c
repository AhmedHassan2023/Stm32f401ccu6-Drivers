/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 27 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SYSTICK           		 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

/* Global pointer to Function to hold SYSTICK ISR Address  */
static void (*STK_pvCallBackFunc)(void) = NULL ;

/* Interval Mode Variable */
static u8 MSTK_u8IntervalMode;

void MSTK_voidInit(void)
{
	
	#if SYSTICK_TICKINT == ENABLED
		/* Enable SYSTICK Timer Interrupt */
		SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
	
	#elif SYSTICK_TICKINT == DISABLED 
		/* Disable SYSTICK Timer Interrupt */
		SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
	
	#endif	
	
	#if SYSTICK_CLKSOURCE == AHB_CLK
		/* SYSTICK Timer Clock Source is AHB */
		SET_BIT(STK->CTRL,STK_CTRL_CLKSOURCE_BIT);
		
	#elif SYSTICK_CLKSOURCE == AHB_DIVIDED_BY_CLK
		/* SYSTICK Timer Clock Source is AHB/8 */
		CLR_BIT(STK->CTRL,STK_CTRL_CLKSOURCE_BIT);
		
	#endif
}

void MSTK_voidEnable(void)
{
	/* Enable SYSTICK TIMER */
	SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
}

void MSTK_voidDisable(void)
{
	/* Enable SYSTICK TIMER */
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load Ticks to Load Register */
	STK->LOAD = u32 Copy_u32Ticks ;
	
	/* Start Timer */
	SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
	
	/* Wait till flag is Raised */
	while( (GET_BIT(STK->CTRL,STK_CTRL_COUNTFLAG)) == 0 );
	
	/* Stop Timer */
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
	
	STK->LOAD = 0 ;
	STK->VAL  = 0  ;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pvSTKFunc)(void))
{
	/* Load Ticks to Load Register */
	STK->LOAD = u32 Copy_u32Ticks ;
	
	/* Start Timer */
	SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
	
	/* Save CallBack*/
	STK_pvCallBackFunc = Copy_pvSTKFunc;
	
	/* Set Interval To Single */
	MSTK_u8IntervalMode = STK_SINGLE_INTERVAL	 ;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);

}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pvSTKFunc)(void))
{
	/* Load Ticks to Load Register */
	STK->LOAD = u32 Copy_u32Ticks ;
	
	/* Start Timer */
	SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
	
	/* Save CallBack*/
	STK_pvCallBackFunc = Copy_pvSTKFunc ;
	
	/* Set Interval To Periodic  */
	MSTK_u8IntervalMode = STK_PERIODIC_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
}

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
	
	/* Stop Timer */
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
	
	/* Update Preload value with 0 */
	STK->LOAD = 0 ;
	STK->VAL  = 0  ;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = ((STK->LOAD) - (STK->VAL)) ;
	
	return Local_u32ElapsedTime ;
	
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = STK->VAL ;
	
	return Local_u32RemainTime ;
}

void SysTick_Handler(void)
{
	/* Local Variable To Clear Flag with it */
	u8 Local_u8Temporary;
	
	if(MSTK_u8IntervalMode == STK_SINGLE_INTERVAL)
	{
		/* Disable Interrupt */
		CLR_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
		
		/* Stop Timer */
		CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
	
		/* Update Preload value with 0 */
		STK->LOAD = 0 ;
		STK->VAL  = 0  ;
	}
	
	/* Invoke CallBack Function */
	STK_pvCallBackFunc();
	
	/* Clear Interrupt Flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,STK_CTRL_COUNTFLAG);
}
