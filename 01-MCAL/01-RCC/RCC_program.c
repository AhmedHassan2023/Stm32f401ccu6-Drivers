/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 12 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : RCC           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		/* Enable HSE with no Bypass */
		//RCC_CR   = 0x00010000;
		/* HSE Selected as System Clock */
		//RCC_CFGR = 0x00000081;
		
		/* 1- Turn ON HSE Clock  , No Bypass */
		SET_BIT(RCC_CR,CR_HSE_ON_BIT);
		
		/* 2- Check HSE is Ready */
		while(GET_BIT(RCC_CR,CR_HSE_RDY_BIT) == 0);
		
		/* 3- Switch to HSE Clock */
		SET_BIT(RCC_CFGR,CFGR_SW0);
		CLR_BIT(RCC_CFGR,CFGR_SW1);
		
		/* 4- Turn Off HSI */
		CLR_BIT(RCC_CR,CR_HSI_ON_BIT);
		
		/* 5- Turn Off PLL */
		CLR_BIT(RCC_CR,CR_PLL_ON_BIT);
	
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		/* Enable HSE with Bypass */
		//RCC_CR   = 0x00050000;
		/* HSE Selected as System Clock */
		//RCC_CFGR = 0x00000001;
		
		/* 1- Turn ON HSE Clock  , With Bypass */
		SET_BIT(RCC_CR,CR_HSE_ON_BIT);
		SET_BIT(RCC_CR,CR_HSE_BYPASS_BIT);
		
		/* 2- Check HSE is Ready */
		while(GET_BIT(RCC_CR,CR_HSE_RDY_BIT) == 0);
		
		/* 3- Switch to HSE Clock */
		SET_BIT(RCC_CFGR,CFGR_SW0);
		CLR_BIT(RCC_CFGR,CFGR_SW1);
		
		/* 4- Turn Off HSI */
		CLR_BIT(RCC_CR,CR_HSI_ON_BIT);
		
		/* 5- Turn Off PLL */
		CLR_BIT(RCC_CR,CR_PLL_ON_BIT);
	
	#elif RCC_CLOCK_TYPE == RCC_HSI
	
		/* Enable HSI + Triming = 0 */
		//RCC_CR   = 0x00000081;
		/* HSI Selected as System Clock */
		//RCC_CFGR = 0x00000000;
		
		/* 1- Turn ON HSI Clock */
		SET_BIT(RCC_CR,CR_HSI_ON_BIT);
		
		/* 2- Check HSI is Ready */
		while(GET_BIT(RCC_CR,CR_HSI_RDY_BIT) == 0);
		
		/* 3- Switch to HSI Clock */
		CLR_BIT(RCC_CFGR,CFGR_SW0);
		CLR_BIT(RCC_CFGR,CFGR_SW1);
		
		/* 4- Turn Off HSE */
		CLR_BIT(RCC_CR,CR_HSE_ON_BIT);
		
		/* 5- Turn Off PLL */
		CLR_BIT(RCC_CR,CR_PLL_ON_BIT);
	
	
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif
	
	#else
		#error("You Choosed Wrong Clock Type")
	#endif
	
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 		: SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralId);	break;
			case RCC_AHB2		: SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralId);	break;
			case RCC_APB1 		: SET_BIT(RCC_APB1ENR,Copy_u8PeripheralId);	break;
			case RCC_APB2		: SET_BIT(RCC_APB2ENR,Copy_u8PeripheralId);	break;
			case RCC_AHB1LP		: SET_BIT(RCC_AHB1LPENR,Copy_u8PeripheralId);	break;
			//default			:	/* Return Error */		break;
		}
	}
	else
	{
		/* Return Error*/
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 	: CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralId);	break;
			case RCC_AHB2	: CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralId);	break;
			case RCC_APB1 	: CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralId);	break;
			case RCC_APB2	: CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralId);	break;
			//default			:	/* Return Error */		break;
		}
	}
	else
	{
		/* Return Error*/
	}
}

void RCC_voidSetAHBBusPrescaler(u8 Copy_u8Prescaler)
{
	RCC_CFGR &=~ AHB_PRESCALER_MASK;
	RCC_CFGR |= Copy_u8Prescaler << 4 ;
	
}
