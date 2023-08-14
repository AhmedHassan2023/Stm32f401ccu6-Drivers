/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 25 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : AFIO          		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIConfiguartion(u8 Copy_u8EXTILine, u8 Copy_u8PortMap)
{
	u8 Local_u8RegisterIndex = 0;
	
	if (Copy_u8EXTILine <= 3)
	{
		Local_u8RegisterIndex = 0;
	}
	
	else if(Copy_u8EXTILine <= 7)
	{
		Local_u8RegisterIndex = 1;
		Copy_u8EXTILine -= 4;
	}
	
	else if(Copy_u8EXTILine <= 11)
	{
		Local_u8RegisterIndex = 2;
		Copy_u8EXTILine -= 8;
	}
	else if(Copy_u8EXTILine <= 15)
	{
		Local_u8RegisterIndex = 3;
		Copy_u8EXTILine -= 12;
	}
		
	AFIO->EXTICR[Local_u8RegisterIndex] &=~ ((0b1111)<<(Copy_u8EXTILine * 4));
	AFIO->EXTICR[Local_u8RegisterIndex] |= ((Copy_u8PortMap) << (Copy_u8EXTILine * 4));

}