/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 OCT 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : LED MATRIX          		 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void LEDMRX_voidInit(void)
{
	/* ROW Pins Modes Output Push PUll Low Speed */
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);

	/* COLUMN Pins Modes Output Push PUll Low Speed */
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
}

void LEDMRX_voidDisplay(u8 *Copy_u8DataArray)
{
	while(1)
	{
		
		/* Disable all columns */
		LEDMRX_voidDisableAllColumns();
		
		/* Enable Column 0 */
		LEDMRX_voidSetRowValues(Copy_u8DataArray[0]);
		MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
		
		/* Enable Column 1 */
		LEDMRX_voidDisableAllColumns();
		LEDMRX_voidSetRowValues(Copy_u8DataArray[1]);
		MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
		
		/* Enable Column 2 */
		LEDMRX_voidDisableAllColumns();
		LEDMRX_voidSetRowValues(Copy_u8DataArray[2]);
		MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
		
		/* Enable Column 3 */
		LEDMRX_voidDisableAllColumns();
		LEDMRX_voidSetRowValues(Copy_u8DataArray[3]);
		MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
		
		/* Enable Column 4 */
		LEDMRX_voidDisableAllColumns();
		LEDMRX_voidSetRowValues(Copy_u8DataArray[4]);
		MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
		
		/* Enable Column 5 */
		LEDMRX_voidDisableAllColumns();
		LEDMRX_voidSetRowValues(Copy_u8DataArray[5]);
		MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
		
		/* Enable Column 6 */
		LEDMRX_voidDisableAllColumns();
		LEDMRX_voidSetRowValues(Copy_u8DataArray[6]);
		MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
		
		/* Enable Column 7 */
		LEDMRX_voidDisableAllColumns();
		LEDMRX_voidSetRowValues(Copy_u8DataArray[7]);
		MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,GPIO_u8PIN_LOW);
		MSTK_voidSetBusyWait(2500);	//2.5 msec
	
	}
}

static void LEDMRX_voidDisableAllColumns(void)
{
	/* Disable all columns */
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,GPIO_u8PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,GPIO_u8PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,GPIO_u8PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,GPIO_u8PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,GPIO_u8PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,GPIO_u8PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,GPIO_u8PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,GPIO_u8PIN_HIGH);
}

static void LEDMRX_voidSetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Local_u8BIT);
}