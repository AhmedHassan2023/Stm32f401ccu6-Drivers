/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 8 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : FBEC           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FBEC_interface.h"
#include "FBEC_private.h"
#include "FBEC_config.h"

void FBEC_voidEraseAppArea(void)
{
	u8 Local_u8Iterator;

	for(Local_u8Iterator = 2 ;Local_u8Iterator<5 ;Local_u8Iterator++)
	{
		FBEC_voidFlashSectorErase(Local_u8Iterator);
	}


}

void FBEC_voidFlashSectorErase(u8 Copy_u8SectorNumber)
{
	/* Wait if FBEC is Busy */
	while( GET_BIT(FBEC->FLASH_SR,FLASH_SR_BSY) == 1);

	/* Check if FBEC is Locked Or Not */
	if( GET_BIT(FBEC->FLASH_CR,FLASH_CR_LOCK) == 1)
	{
		FBEC -> FLASH_KEYR = KEY1;
		FBEC -> FLASH_KEYR = KEY2;
	}

	/* Select Sector */
	FBEC -> FLASH_CR &=~( (u32) (0b1111 << 3) );
	FBEC -> FLASH_CR |= (Copy_u8SectorNumber << 3);

	/* Select Sector Erase Operation */
	SET_BIT( FBEC -> FLASH_CR,FLASH_CR_SER);

	/* Start Erase Operation */
	SET_BIT( FBEC -> FLASH_CR,FLASH_CR_STRT);

	/* Wait for Busy Flag */
	while( GET_BIT(FBEC -> FLASH_SR,FLASH_SR_BSY) == 1);

	/* Clear End of Operation Flag */
	SET_BIT(FBEC -> FLASH_SR,FLASH_SR_EOP);

	/* Disselect Sector Erase Operation */
	CLR_BIT( FBEC -> FLASH_CR,FLASH_CR_SER);

}

void FBEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_pu16Data, u16 Copy_u16Length)
{
	u16 Local_u16Iterator = 0;
	volatile u16 Local_u16Temp;

	/* Wait if FBEC is Busy */
	while( GET_BIT(FBEC->FLASH_SR,FLASH_SR_BSY) == 1);

	/* Check if FBEC is Locked Or Not */
	if( GET_BIT(FBEC->FLASH_CR,FLASH_CR_LOCK) == 1)
	{
		FBEC -> FLASH_KEYR = KEY1;
		FBEC -> FLASH_KEYR = KEY2;
	}

	/* Select The ELement Size */
	FBEC -> FLASH_CR &=~((u32) 0b11 << 8);
	FBEC -> FLASH_CR |=(0b01 << 8 );

	/* Activate Programming Mode */
	SET_BIT(FBEC -> FLASH_CR,FLASH_CR_PG);

	/* Write Data to Flash Address */
	for(Local_u16Iterator = 0 ;Local_u16Iterator<Copy_u16Length; Local_u16Iterator++)
	{
		Local_u16Temp = Copy_pu16Data[Local_u16Iterator];

		*((volatile u16 *)Copy_u32Address ) = Copy_pu16Data[i];

		Copy_u32Address += 2 ;

		/* Wait for Busy Flag */
		while( GET_BIT(FBEC->FLASH_SR,FLASH_SR_BSY) == 1);

		/* Clear End of Operation Flag */
		SET_BIT(FBEC -> FLASH_SR,FLASH_SR_EOP);
	}
	
	/* Deactivate Programming Mode */
	CLR_BIT(FBEC -> FLASH_CR,FLASH_CR_PG);

}
