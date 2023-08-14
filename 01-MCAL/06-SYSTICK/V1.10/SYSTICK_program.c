/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 27 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SYSTICK           		 ***********************/
/* Version 	: 1.10             			 ***********************/
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
		CLR_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
	
	#endif	
	
	#if SYSTICK_CLKSOURCE == AHB_CLK
		/* SYSTICK Timer Clock Source is AHB */
		SET_BIT(STK->CTRL,STK_CTRL_CLKSOURCE_BIT);
		
	#elif SYSTICK_CLKSOURCE == AHB_DIVIDED_BY_8_CLK
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

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks, u8 Copy_u8TickType)
{
	#if SYSTICK_CLKSOURCE == AHB_DIVIDED_BY_8_CLK
		f32 Local_f32TickTime = 1.00 / (CLK_IN_MHZ / 8.00);
	#else 
		f32 Local_f32TickTime = 1.00 / CLK_IN_MHZ;
	#endif
	
	u32 Local_u3NoOfTicks = Copy_u32Ticks / Local_f32TickTime ;
	
	if(Copy_u8TickType == MILLI_SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks * 1000 ;
	}
	else if (Copy_u8TickType == MICRO_SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks ;
	}
	else if (Copy_u8TickType == SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks * 1000000 ;
	}
	else
	{
	}
	
	if(Copy_u32Ticks < 16777216)
	{
		SetBusy(Copy_u32Ticks);
	}
	else if(Copy_u32Ticks > 16777216)
	{
		while(Copy_u32Ticks > 0)
		{
			if(Copy_u32Ticks > 16777216)
			{
				SetBusy(16777216);
				Copy_u32Ticks -= 16777216;
			}
			else
			{
				SetBusy(Copy_u32Ticks);
				Copy_u32Ticks = 0;
			}
		}
	}
	
}

void SetBusy(u32 Copy_u32Ticks)
{
	/* Load Ticks to Load Register */
	STK->LOAD = 0x00000000;
	STK->LOAD = Copy_u32Ticks ;
	
	/* Start Timer */
	SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
	
	/* Wait till flag is Raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);
	//while( (GET_BIT(STK->CTRL, 16)) == 0 );
	
	/* Stop Timer */
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);

	STK->LOAD = 0 ;
	STK->VAL  = 0  ;
	
}
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,u8 Copy_u8TickType, void (*Copy_pvSTKFunc)(void))
{
	#if SYSTICK_CLKSOURCE == AHB_DIVIDED_BY_8_CLK
		f32 Local_f32TickTime = 1.00 / (CLK_IN_MHZ / 8.00);
	#else 
		f32 Local_f32TickTime = 1.00 / CLK_IN_MHZ;
	#endif
	
	u32 Local_u3NoOfTicks = Copy_u32Ticks / Local_f32TickTime ;
	
	if(Copy_u8TickType == MILLI_SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks * 1000 ;
	}
	else if (Copy_u8TickType == MICRO_SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks ;
	}
	else if (Copy_u8TickType == SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks * 1000000 ;
	}
	else
	{
	}
	
	if(Copy_u32Ticks < 16777216)
	{
		/* Disable the Counter */
		CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
		STK->VAL = 0x00000000;
		
		/* Update the Load Register with  the Number of Ticks */
		STK->LOAD = Copy_u32Ticks ;
		
		/* Start Timer */
		SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
		
		/* Save CallBack*/
		STK_pvCallBackFunc = Copy_pvSTKFunc;
		
		/* Set Interval To Single */
		MSTK_u8IntervalMode = STK_SINGLE_INTERVAL	 ;
		
		/* Enable STK Interrupt */
		SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
			
	}
	

}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,u8 Copy_u8TickType, void (*Copy_pvSTKFunc)(void))
{
	#if SYSTICK_CLKSOURCE == AHB_DIVIDED_BY_8_CLK
		f32 Local_f32TickTime = 1.00 / (CLK_IN_MHZ / 8.00);
	#else 
		f32 Local_f32TickTime = 1.00 / CLK_IN_MHZ;
	#endif
	
	u32 Local_u3NoOfTicks = Copy_u32Ticks / Local_f32TickTime ;
	
	if(Copy_u8TickType == MILLI_SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks * 1000 ;
	}
	else if (Copy_u8TickType == MICRO_SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks ;
	}
	else if (Copy_u8TickType == SEC)
	{
		Copy_u32Ticks = Local_u3NoOfTicks * 1000000 ;
	}
	else
	{
	}
	
	if(Copy_u32Ticks < 16777216)
	{
		/* Disable the Counter */
		CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
		STK->VAL = 0x00000000;
		
		/* Update the Load Register with  the Number of Ticks */
		STK->LOAD = Copy_u32Ticks ;
		
		/* Start Timer */
		SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
		
		/* Save CallBack*/
		STK_pvCallBackFunc = Copy_pvSTKFunc;
		
		/* Set Interval To Periodic*/
		MSTK_u8IntervalMode = STK_PERIODIC_INTERVAL	 ;
		
		/* Enable STK Interrupt */
		SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
			
	}
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
	u8 Local_u8Temporary = 0 ;
	
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
	Local_u8Temporary = GET_BIT(STK->CTRL, STK_CTRL_COUNTFLAG_BIT);
}
