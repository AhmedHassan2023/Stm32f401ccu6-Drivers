/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 10 NOV 2022				 ***********************/
/* Layer   	: SERVICES           		 ***********************/
/* SWC      : OS          				 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


void OS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Priodicity, void (*Copy_pvTaskFunc)(void) )
{
	SystemTasks[Copy_u8Priority].Priodicity = Copy_u16Priodicity;
	SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;

	
}

void OS_voidStart(void)
{
	/* Initializatin */
	MSYSTICk_voidConfig();
	
	/* Tick time = 1ms */
	MSYSTICK_voidSetIntervalPeriodic(1000, MICRO_SEC,Schedualr)
	
	
}

volatile u16 TickCounts =0 ;

void Schedualr(void)
{
	u8 i;
	
	for (i=0;i<TASK_NUM;i++)
	{
		if( (TickCounts % SystemTasks[i].Priodicity) == 0 )
		{
			SystemTasks[i].TaskFunc();
		}
		else
		{
			/* Do nothing */
		}
	}
	TickCounts++;
	
}