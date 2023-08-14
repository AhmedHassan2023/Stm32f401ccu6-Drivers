/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 8 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : FBEC           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef FBEC_INTERFACE_H_
#define FBEC_INTERFACE_H_

/* FLASH Sector Organization */
#define SECTOR_0		0
#define SECTOR_1		1
#define SECTOR_2		2
#define SECTOR_3		3
#define SECTOR_4		4
#define SECTOR_5		5
#define SECTOR_6		6
#define SECTOR_7		7

void FBEC_voidEraseAppArea(void);

void FBEC_voidFlashSectorErase(u8 Copy_u8SectorNumber);

void FBEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_pu16Data, u8 Copy_u8Length);


#endif	/* FBEC_INTERFACE_H_ */
