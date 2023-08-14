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

void USART1_voidInit(void)
{
	/* 1- Baud Rate 9600 0xA2C ,	fclk = HSE = 25 MHZ   ,for  stm32f401ccu6	 	*/
	USART1 -> BRR  = USART1_BUAD_RATE_VALUE ;

	/* 1- Enable RX
	   2- Enable TX
	   3- Enable USART		*/
	SET_BIT(USART1 -> CR1,USART1_CR1_RE);
	SET_BIT(USART1 -> CR1,USART1_CR1_TE);
	SET_BIT(USART1 -> CR1,USART1_CR1_UE);

	/* Clear Status Register */
	USART1 -> SR = 0 ;

}

void USART1_voidSendDataSynch(u8 Copy_u8Data)
{
	/* Put data In Data Register */
	USART1 -> DR = Copy_u8Data;

	/* Wait till Transmission is complete */
	while(GET_BIT(USART1 -> SR ,USART1_SR_TC) == 0);

	/* Clear Transmission Flag */
	CLR_BIT(USART1 -> SR,USART1_SR_TC);

}

void USART1_voidSendStringSynch(const char *Copy_pcString)
{
	u8 Local_u8Iterator = 0;

	while(Copy_pcString[Local_u8Iterator] != '\0')
	{
		/* Send Data Byte by Byte , Array Of Characters*/
		USART1_voidSendDataSynch(Copy_pcString[Local_u8Iterator]);
		
		/* Increment The Iterator*/
		Local_u8Iterator++;
	}

}

u8 USART1_u8ReceiveDataSynch(void)
{
	u32 Loal_u32TimeOut = 0 ;
	u8 Local_u8Data = 0;

	/* Clear RXNE Flag */
	CLR_BIT(USART1 -> SR,USART1_SR_RXNE);

	/* Wait Until Receive complete  */
	while( (GET_BIT(USART1 -> SR,USART1_SR_RXNE) == 0) && (Loal_u32TimeOut <USART1_TIME_OUT ))
	{
		Loal_u32TimeOut++;
	}
	
	if(Loal_u32TimeOut == USART1_TIME_OUT)
	{
		Local_u8Data = 255;
	}
	else
	{
		Local_u8Data = USART1 -> DR;
	}

	return Local_u8Data ;
}
