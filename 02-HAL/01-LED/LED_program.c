/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 14 SEP 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : LED           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void LED_voidTurnON(LED_t* Copy_u8LED)
{
	//MGPIO_voidSetPinDirection(Copy_u8LED->Port,Copy_u8LED->Pin,OUTPUT_PUSH_PULL,LOW_SPEED);

	if(Copy_u8LED->Connection_Type== SRC)
	{
		MGPIO_voidSetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,GPIO_u8PIN_HIGH);

	}

	if(Copy_u8LED->Connection_Type== SINK)
	{
		MGPIO_voidSetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,GPIO_u8PIN_LOW);
	}
}

void LED_voidTurnOFF(LED_t* Copy_u8LED)
{
	//MGPIO_voidSetPinDirection(Copy_u8LED->Port,Copy_u8LED->Pin,OUTPUT_PUSH_PULL,LOW_SPEED);

	if(Copy_u8LED->Connection_Type== SRC)
	{
		MGPIO_voidSetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,GPIO_u8PIN_LOW);
	}

	if(Copy_u8LED->Connection_Type== SINK)
	{
		MGPIO_voidSetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,GPIO_u8PIN_HIGH);
	}

}

