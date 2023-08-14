/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 OCT 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : LED MATRIX          		 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef LEDMATRIX_INTERFACE_H_
#define LEDMATRIX_INTERFACE_H_

void LEDMRX_voidInit(void);

void LEDMRX_voidDisplay(u8 *Copy_u8DataArray);


#endif	/* LEDMATRIX_INTERFACE_H_ */