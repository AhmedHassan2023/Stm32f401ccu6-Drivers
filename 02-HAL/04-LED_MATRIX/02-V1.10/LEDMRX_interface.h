/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 OCT 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : LED MATRIX          		 ***********************/
/* Version 	: 1.10             			 ***********************/
/***************************************************************/

#ifndef LEDMATRIX_INTERFACE_H_
#define LEDMATRIX_INTERFACE_H_

#define LED_MATRIX_INC_SPEED		0
#define LED_MATRIX_DEC_SPEED		1
#define LED_MATRIX_STOP_DISPLAY		2
#define LED_MATRIX_RESMUE_DISPLAY	3

void LEDMRX_voidInit(void);

void LEDMRX_voidDisplay(u8 *Copy_u8DataArray);

void LEDMRX_voidDisplayLine(u8 *Copy_u8LineArray, u8 Copy_u8ColCount);


#endif	/* LEDMATRIX_INTERFACE_H_ */
