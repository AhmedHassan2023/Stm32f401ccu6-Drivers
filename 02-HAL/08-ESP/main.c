/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "USART_interface.h"

#include "ESP_interface.h"





void main(void)
{
	u8 Local_u8Data = 0 ;
	u8 data[10]={0};
	u8 i =0 ;

	/* Initialize System Clock */
	RCC_voidInitSysClock();

	/* Enable GPIO */
	RCC_voidEnableClock(RCC_AHB1,GPIOA_EN);

	/* Enable USART */
	RCC_voidEnableClock(RCC_APB2,USART1_EN);

	/* Set PA0 As Output PUSH PULL */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_PUSH_PULL,LOW_SPEED);

	/* Set PA1 As Output PUSH PULL */
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_PUSH_PULL,LOW_SPEED);

	/* Set PA9 As Alternative Function Push Pull -> Tx */
	MGPIO_voidSetPinDirection(GPIOA,PIN9,AF_PUSH_PULL,MEDIUM_SPEED);

	/* Select AF7 for PA9 */
	MGPIO_voidSetAF(GPIOA,PIN9,AF7);

	/* Set PA10 As Alternative Function Push Pull -> Rx */
	MGPIO_voidSetPinDirection(GPIOA,PIN10,AF_PUSH_PULL,MEDIUM_SPEED);

	/* Select AF7 for PA10 */
	MGPIO_voidSetAF(GPIOA,PIN10,AF7);

	/* Enable USART1 Interrupt */
	USART1_voidEnableIntrrupt();

	/* NVIC Initialization */
	MNVIC_voidInit();

	/* Enable USART1 Interrupt */
	MNVIC_voidEnableInterrupt(37);

	/* SYSTICK Initialization  */
	MSTK_voidInit();


	/* USART1 Initialization */
	USART1_voidInit();

	/* ESP Initialize */
	ESP_voidInit();

	/* ESP Connect To WIFI */
	ESP_voidConnectToWIFI("Ahmed Hassan","Medo0106");

	while(1)
	{
		/* ESP Connect To Server : ahmedhassan.freevar.com , IP : 172.107.162.12 , Port : 80 */
		ESP_voidConnectToServer("172.107.162.12","80");

		/* Receive Data from Server */
		Local_u8Data = ESP_voidReceiveData("ahmedahs.freevar.com","48");

		//MGPIO_voidSetPinValue(GPIOA,PIN0,Local_u8Data - 48);

		if(Local_u8Data == '1')
		{
			MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_u8PIN_HIGH);
		}
		else if(Local_u8Data== '0')
		{
			MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_u8PIN_LOW);
		}
		else if(Local_u8Data== '2')
		{
			MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_u8PIN_HIGH);
		}
		else if(Local_u8Data== '3')
		{
			MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_u8PIN_LOW);
		}

	}
}



