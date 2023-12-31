/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 29 NOV 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : STP           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_voidSendSynchronous( u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter ;
	u8 Local_u8Bit;
	for(Local_s8Counter = 7;Local_s8Counter>=0;Local_s8Counter--)
	{
		/* Send bit by bit starting from MSB*/
		Local_u8Bit = GIT_BIT(Copy_u8DataToSend,Local_s8Counter);
		
		MGPIO_voidSetPinValue(STP_SERIAL_DATA,Local_u8Bit);
		
		/* Send Pulse to Shift Clock */
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK,GPIO_u8PIN_HIGH);
		MSYSTICK_voidSetBusyWait(1, MICRO_SEC);
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK,GPIO_u8PIN_LOW);
		MSYSTICK_voidSetBusyWait(1, MICRO_SEC);
		
		/* Send Pulse to Store Clock */
		MGPIO_voidSetPinValue(STP_STORE_CLOCK,GPIO_u8PIN_HIGH);
		MSYSTICK_voidSetBusyWait(1, MICRO_SEC);
		MGPIO_voidSetPinValue(STP_STORE_CLOCK,GPIO_u8PIN_LOW);
		MSYSTICK_voidSetBusyWait(1, MICRO_SEC);
		
	}
	
}