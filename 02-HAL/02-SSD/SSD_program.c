/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 SEP 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : SSD           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


void SSD_voidInit(SSD_t* Copy_u8SSD)
{
	MGPIO_voidSetPinDirection(Copy_u8SSD->Port,PIN_A,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(Copy_u8SSD->Port,PIN_B,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(Copy_u8SSD->Port,PIN_C,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(Copy_u8SSD->Port,PIN_D,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(Copy_u8SSD->Port,PIN_E,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(Copy_u8SSD->Port,PIN_F,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(Copy_u8SSD->Port,PIN_G,OUTPUT_PUSH_PULL,LOW_SPEED);
}

void SSD_voidSetNumber(SSD_t* Copy_u8SSD,u8 Copy_u8Number)
{
	u8 Local_u8SSDValue[10]=SSD_ARR_VAL;

	if(Copy_u8SSD->Com_Type == SSD_u8ComCathode)
	{
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN_A,GET_BIT(Local_u8SSDValue[Copy_u8Number],0));
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN_B,GET_BIT(Local_u8SSDValue[Copy_u8Number],1));
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN_C,GET_BIT(Local_u8SSDValue[Copy_u8Number],2));
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN_D,GET_BIT(Local_u8SSDValue[Copy_u8Number],3));
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN_E,GET_BIT(Local_u8SSDValue[Copy_u8Number],4));
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN_F,GET_BIT(Local_u8SSDValue[Copy_u8Number],5));
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN_G,GET_BIT(Local_u8SSDValue[Copy_u8Number],6));
	}
	else if(Copy_u8SSD->Com_Type == SSD_u8ComAnode)
	{
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN0,GET_BIT(Local_u8SSDValue[Copy_u8Number],0) ^ 0x01);
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN1,GET_BIT(Local_u8SSDValue[Copy_u8Number],1) ^ 0x01);
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN2,GET_BIT(Local_u8SSDValue[Copy_u8Number],2) ^ 0x01);
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN3,GET_BIT(Local_u8SSDValue[Copy_u8Number],3) ^ 0x01);
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN4,GET_BIT(Local_u8SSDValue[Copy_u8Number],4) ^ 0x01);
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN5,GET_BIT(Local_u8SSDValue[Copy_u8Number],5) ^ 0x01);
		MGPIO_voidSetPinValue(Copy_u8SSD->Port,PIN6,GET_BIT(Local_u8SSDValue[Copy_u8Number],6) ^ 0x01);
	}

}



