/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 28 JAN 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : TFT           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void TFT_voidInit(void)
{
	/* Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_u8PIN_HIGH);
	MSTK_voidSetBusyWait(100,MICRO_SEC);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_u8PIN_LOW);
	MSTK_voidSetBusyWait(10,MICRO_SEC);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_u8PIN_HIGH);
	MSTK_voidSetBusyWait(100,MICRO_SEC);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_u8PIN_LOW);
	MSTK_voidSetBusyWait(100,MICRO_SEC);

	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_u8PIN_HIGH);
	MSTK_voidSetBusyWait(120,MILLI_SEC);

	/* Sleep Out Command */
	voidWriteCommand(0x11);

	/* Wait 150 ms */
	MSTK_voidSetBusyWait(150,MILLI_SEC);

	/* Color Mode Command */
	voidWriteCommand(0x3A);
	voidWriteData	(0x05);

	/* Display On Command */
	voidWriteCommand(0x29);


}

void TFT_voidDisplayImage(const u16* Copy_pu16Image)
{
	u16 Local_u16Counter=0;
	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/* Set Y Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(Local_u16Counter=0;Local_u16Counter<20490;Local_u16Counter++)
	{
		/* Write The High Byte */
		voidWriteData((Copy_pu16Image[Local_u16Counter]>>8));

		/* Write The Low Byte */
		voidWriteData((Copy_pu16Image[Local_u16Counter] & 0x00ff));

	}

}
void TFT_voidFillColor(u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		voidWriteData(Data);
	}


}

void TFT_voidDrawRec(u8 x1, u8 x2, u8 y1, u8 y2,u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;
	u16 size = (x2-x1) * (y2-y1);

	/* Make sure data valid x2>x1 x2<127 an so .. */

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);

	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(counter = 0; counter< size;counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		voidWriteData(Data);
	}


}

void TFT_voidDrawCharacter(u8 Copy_u8Char,u8 Copy_u16X, u8 Copy_u16Y,u16 Copy_u16Size,u16 Copy_u16Color,u16 Copy_u16BackColor)
{
	u8 Local_u8IteratorX = 0 ;
	u8 Local_u8IteratorY = 0 ;


	if(Copy_u8Char == ' ')
	{
		return;
	}

	Copy_u8Char -= '0' ;

	TFT_voidDrawRec(Copy_u16X,((Copy_u16Size * 7) + 5),Copy_u16Y,((Copy_u16Size * 5) + 5),Copy_u16BackColor);

	for(Local_u8IteratorX=0 ;Local_u8IteratorX<(7*Copy_u16Size );Local_u8IteratorX++)
	{
		for(Local_u8IteratorY=0;Local_u8IteratorY<(5*Copy_u16Size);Local_u8IteratorY++)
		{
			if(Char_Array[Copy_u8Char][Local_u8IteratorX/Copy_u16Size] >>(Local_u8IteratorY/Copy_u16Size) & 1)
			{
				TFT_voidDrawRec(Copy_u16X+(Local_u8IteratorY),Copy_u16X+(Local_u8IteratorY)+1,Copy_u16Y+(Local_u8IteratorX),Copy_u16Y+(Local_u8IteratorX)+1,Copy_u16Color);
			}
		}
	}
}

void TFT_voidDrawLine(u8 Copy_u8XPos,u8 Copy_u8YPos,u8 Copy_u8Length,u16 Copy_u16Color)
{

}

void TFT_voidDrawText(u8* Copy_pu8String, u8 Copy_u8XPos, u8 Copy_u8YPos, u8 Copy_u8Size, u16 Copy_u16Color)
{

}



static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;

	/* Set A0 Pin to LOW */
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_u8PIN_LOW);

	/* Send Command Over SPI */
	SPI1_u8SendReciveSynch(Copy_u8Command,&Local_u8Temp);

}

static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;

	/* Set A0 Pin to HIGH */
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_u8PIN_HIGH);

	/* Send Command Over SPI */
	SPI1_u8SendReciveSynch(Copy_u8Data,&Local_u8Temp);

}
