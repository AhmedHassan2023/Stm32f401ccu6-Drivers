/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 28 JAN 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : TFT           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

void TFT_voidInit(void);

void TFT_voidDisplayImage(const u16* Copy_pu16Image);

void TFT_voidFillColor(u16 Copy_u16Color);

void TFT_voidDrawRec(u8 x1, u8 x2, u8 y1, u8 y2,u16 Copy_u16Color);

void TFT_voidDrawCharacter(u8 Copy_u8Char,u8 Copy_u16X, u8 Copy_u16Y,u16 Copy_u16Size,u16 Copy_u16Color,u16 Copy_u16BackColor);

void TFT_voidDrawLine(u8 Copy_u8XPos,u8 Copy_u8YPos,u8 Copy_u8Length,u16 Copy_u16Color);

void TFT_voidDrawText(u8* Copy_pu8String, u8 Copy_u8XPos, u8 Copy_u8YPos, u8 Copy_u8Size, u16 Copy_u16Color);


#endif	/* TFT_INTERFACE_H_ */
