/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 03 DEC 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : USART           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART_voidInit(void)
{
	USART1 -> BRR = 0x0A2C;

	/* Enable RX
	 * Enable TX
	 * Enable USART */
	SET_BIT(USART1->CR1,2);
	SET_BIT(USART1->CR1,3);
	SET_BIT(USART1->CR1,13);

	/* Clear Status Register */
	USART1->SR = 0 ;

}
void MUSART_voidSendSynch(u8 Copy_u8Data)
{
	USART1->DR  = Copy_u8Data;

	/* wait till transmission complete*/

	while(GET_BIT(USART1->SR,6) == 0);
	
	/* Clear Transmission flag */
	CLR_BIT(USART1->SR,6);
}

u8 MUSART_u8ReceiveData(void)
{
	u8 Local_u8DataReceived = 0;

	/* Clear Receiver Flag */

	CLR_BIT(USART1->SR,5);

	/* wait till receive complete  */
	while(GET_BIT(USART1->SR,5) == 0);

	Local_u8DataReceived = USART1->DR ;

	return Local_u8DataReceived ;
	
}
