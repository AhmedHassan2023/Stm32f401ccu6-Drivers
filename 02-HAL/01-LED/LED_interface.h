/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 SEP 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : LED           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define SRC		1
#define SINK	0

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Connection_Type;
}LED_t;

void LED_voidTurnON(LED_t* Copy_u8LED);
void LED_voidTurnOFF(LED_t* Copy_u8LED);


#endif
