/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 OCT 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : LED MATRIX          		 ***********************/
/* Version 	: 1.10             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

static u8 DisplaySpeed = LED_MATRIX_INIT_SPEED ;
static u8 DisplayState = LED_MATRIX_RESMUE_DISPLAY ;

void LEDMRX_voidInit(void)
{
	u8 Local_u8RowIterator = 0 ;
	u8 Local_u8ColIterator = 0 ;
	
	/* ROW Pins Modes Output Push PUll Low Speed */
	for(Local_u8RowIterator=0;Local_u8RowIterator<8;Local_u8RowIterator++)
	{
		MGPIO_voidSetPinDirection(LedMatrixRow[Local_u8RowIterator].PORT,LedMatrixRow[Local_u8RowIterator].PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	}

	/* COLUMN Pins Modes Output Push PUll Low Speed */
	for(Local_u8ColIterator=0;Local_u8ColIterator<8;Local_u8ColIterator++)
	{
		MGPIO_voidSetPinDirection(LedMatrixCol[Local_u8ColIterator].PORT,LedMatrixCol[Local_u8ColIterator].PIN,OUTPUT_PUSH_PULL,LOW_SPEED);
	}

}

void LEDMRX_voidDisplay(u8 *Copy_u8DataArray)
{
	u8 Local_u8ColIterator = 0 ;
	
	for(Local_u8ColIterator=0;Local_u8ColIterator<8;Local_u8ColIterator++)
	{
		/* Disable all columns */
		LEDMRX_voidDisableAllColumns();
		
		/* Set Row Value of Index = Local_u8ColIterator */
		LEDMRX_voidSetRowValues(Copy_u8DataArray[Local_u8ColIterator]);
		
		/* Enable Column of Index = Local_u8ColIterator */
		MGPIO_voidSetPinValue(LedMatrixCol[Local_u8ColIterator].PORT,LedMatrixCol[Local_u8ColIterator].PIN,GPIO_u8PIN_LOW);
		
		/* Wait 2.5 msec*/
		MSTK_voidSetBusyWait(2.5,MILLI_SEC);

		
	}
}

static void LEDMRX_voidDisableAllColumns(void)
{
	u8 Local_u8ColIterator = 0;

	/* Disable all columns */
	for(Local_u8ColIterator=0;Local_u8ColIterator<8;Local_u8ColIterator++)
	{
		MGPIO_voidSetPinValue(LedMatrixCol[Local_u8ColIterator].PORT,LedMatrixCol[Local_u8ColIterator].PIN,GPIO_u8PIN_HIGH);
	}
}

static void LEDMRX_voidSetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT = 0;
	u8 Local_u8RowIterator = 0 ;
	
	for(Local_u8RowIterator =0;Local_u8RowIterator<8;Local_u8RowIterator++)
	{
		Local_u8BIT = GET_BIT(Copy_u8Value,Local_u8RowIterator);
		MGPIO_voidSetPinValue(LedMatrixRow[Local_u8RowIterator].PORT,LedMatrixRow[Local_u8RowIterator].PIN,Local_u8BIT);
		
	}
}

void LEDMRX_voidDisplayLine(u8 *Copy_u8LineArray, u8 Copy_u8ColCount)
{
	u8 Local_u8LineIndex = 0;
	u8 Local_u8WaitIndex = 0;
	
	
	for(Local_u8LineIndex=0;Local_u8LineIndex<Copy_u8ColCount;)
	{
		if(DisplayState == LED_MATRIX_RESMUE_DISPLAY )
		{
			Local_u8LineIndex ++ ;
		}
		else
		{
			/* Do nothing*/
		}
		
		for(Local_u8WaitIndex=0;Local_u8WaitIndex<DisplaySpeed;Local_u8WaitIndex++)
		{
			LEDMRX_voidDisplay(Copy_u8LineArray + Local_u8LineIndex);
		}
	}
}
