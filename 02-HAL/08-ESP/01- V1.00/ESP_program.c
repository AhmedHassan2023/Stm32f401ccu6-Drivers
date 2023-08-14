/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 22 JAN 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : ESP           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

volatile u8  Data[200] = {0} ;


void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		USART1_voidSendStringSynch("ATE0\r\n");

		Local_u8Result = voidESPValidateCmd();

	}

	Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Set Station Mode */
		USART1_voidSendStringSynch("AT+CWMODE=1\r\n");
		Local_u8Result = voidESPValidateCmd();

	}

	Local_u8Result = 0 ;
	voidCLRData();

	while(Local_u8Result == 0)
	{
		/* Set Transfer Mode */
		USART1_voidSendStringSynch("AT+CIPMDE=0\r\n");
		Local_u8Result = voidESPValidateCmd();
	}
	voidCLRData();
}

void ESP_voidConnectToWIFI(u8* Copy_pu8SSID, u8* Copy_pu8Password)
{
	u8 Local_u8Result = 0 ;

	while(Local_u8Result == 0)
	{
		USART1_voidSendStringSynch("AT+CWJAPA_CUR=\"");
		USART1_voidSendStringSynch(Copy_pu8SSID);
		USART1_voidSendStringSynch("\",\"");
		USART1_voidSendStringSynch(Copy_pu8Password);
		USART1_voidSendStringSynch("\"\r\n");

		Local_u8Result = voidESPValidateCmd();

	}
}

void ESP_voidConnectToServer(u8* Copy_pu8IP, u8* Copy_pu8Port)
{
	u8 Local_u8Result = 0 ;

	while(Local_u8Result == 0)
	{
		USART1_voidSendStringSynch("AT+CIPSTART=\"");
		USART1_voidSendStringSynch("TCP\",\"");
		USART1_voidSendStringSynch(Copy_pu8IP);
		USART1_voidSendStringSynch("\",");
		USART1_voidSendStringSynch(Copy_pu8Port);
		USART1_voidSendStringSynch("\r\n");

		Local_u8Result = voidESPValidateCmd();
	}
}

u8 ESP_voidReceiveData(u8* Copy_pu8Server,u8* Copy_pu8Length)
{
	u8 Local_u8Result = 0 ;
	u8 Local_u8Responce[100] = {0};
	u8 i=0;
	u8 Dummy=0;

	while(Local_u8Result == 0)
	{
		USART1_voidSendStringSynch("AT+CIPSEND=");
		USART1_voidSendStringSynch(Copy_pu8Length);
		USART1_voidSendStringSynch("\r\n");

		Local_u8Result = voidESPValidateCmd();
	}

	Local_u8Result = 0 ;

	while(Local_u8Result == 0)
	{
		USART1_voidSendStringSynch("GET http://");
		USART1_voidSendStringSynch(Copy_pu8Server);
		USART1_voidSendStringSynch("/status.txt\r\n");
	}

	while(Dummy != 255)
	{
		Dummy = USART1_u8ReceiveDataSynch();
		Local_u8Responce[i] = Dummy ;
		i++;
	}

	return Local_u8Responce[7];

}

u8 voidESPValidateCmd(void)
{
	u8 Local_u8Responce[100] = {0};
	u8 i=0;
	u8 Dummy=0;
	u8 Result = 0;

	while(Dummy != 255)
	{
		Dummy = USART1_u8ReceiveDataSynch();
		Local_u8Responce[i] = Dummy ;
		Data[i] = Dummy ;
		i++;
	}

	/* Check if OK */
	if(Local_u8Responce[0] == 'O' && Local_u8Responce[1] == 'K')
	{
		Result = 1 ;
	}

	/* Ckeck if SEND OK */
//	else if(Local_u8Responce[0] == 'S' && Local_u8Responce[6] == 'K')
//	{
//		Result = 2 ;
//	}

	return Result;

}

void voidCLRData(void)
{
	u8 Local_u8Iterator = 0;
	for(Local_u8Iterator=0;Local_u8Iterator<200;Local_u8Iterator++)
	{
		Data[Local_u8Iterator] = 0;
	}
}
