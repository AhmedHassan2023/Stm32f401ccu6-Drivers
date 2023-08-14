/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 SEP 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : SSD           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_ARR_VAL			{0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111}

#define SSD_u8ComCathode	0
#define SSD_u8ComAnode		1


typedef struct
{
	u8 Port;
	u8 Com_Type;
}SSD_t;


void SSD_voidInit(SSD_t* Copy_u8SSD);

void SSD_voidSetNumber(SSD_t* Copy_u8SSD,u8 Copy_u8Number);





#endif	/* SSD_INTERFACE_H_ */
