/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : GPIO           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode, u8 Copy_u8Speed)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
			if((Copy_u8Mode >= OUTPUT_PUSH_PULL) && (Copy_u8Mode <= OUTPUT_OPEN_DRAIN_PULL_DOWN))
			{
				SET_BIT(GPIOA_MODER,Copy_u8Pin * 2);
				CLR_BIT(GPIOA_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if((Copy_u8Mode >= AF_PUSH_PULL) && (Copy_u8Mode <= AF_OPEN_DRAIN_PULL_DOWN))
			{
				CLR_BIT(GPIOA_MODER,Copy_u8Pin * 2);
				SET_BIT(GPIOA_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if((Copy_u8Mode >= INPUT_FLOATING) && (Copy_u8Mode <= INPUT_PULL_DOWN))
			{
				CLR_BIT(GPIOA_MODER,Copy_u8Pin * 2);
				CLR_BIT(GPIOA_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if(Copy_u8Mode == INPUT_ANALOG)
			{
				SET_BIT(GPIOA_MODER,Copy_u8Pin * 2);
				SET_BIT(GPIOA_MODER,((Copy_u8Pin * 2) + 1));
			}
			switch (Copy_u8Mode)
			{
				case OUTPUT_PUSH_PULL 	:
				case AF_PUSH_PULL		:
				case INPUT_FLOATING   	:
					CLR_BIT(GPIOA_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOA_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOA_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_PUSH_PULL_PULL_UP 	:
				case AF_PUSH_PULL_PULL_UP		:
				case INPUT_PULL_UP 				:
					CLR_BIT(GPIOA_OTYPER,Copy_u8Pin);
					SET_BIT(GPIOA_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOA_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_PUSH_PULL_PULL_DOWN	:
				case AF_PUSH_PULL_PULL_DOWN		:
				case INPUT_PULL_DOWN			:
					CLR_BIT(GPIOA_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOA_PUPDR,Copy_u8Pin * 2);
					SET_BIT(GPIOA_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_OPEN_DRAIN 	:
				case AF_OPEN_DRAIN		:
					SET_BIT(GPIOA_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOA_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOA_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
				
				case OUTPUT_OPEN_DRAIN_PULL_UP	:
				case AF_OPEN_DRAIN_PULL_UP		:
					SET_BIT(GPIOA_OTYPER,Copy_u8Pin);
					SET_BIT(GPIOA_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOA_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_OPEN_DRAIN_PULL_DOWN	:
				case AF_OPEN_DRAIN_PULL_DOWN		:
					SET_BIT(GPIOA_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOA_PUPDR,Copy_u8Pin * 2);
					SET_BIT(GPIOA_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
			}
			GPIOA_OSPEEDR &=~(3 << (Copy_u8Pin * 2));
			GPIOA_OSPEEDR |= (Copy_u8Speed <<(Copy_u8Pin * 2));
			break;
			
		case GPIOB :
			if((Copy_u8Mode >= OUTPUT_PUSH_PULL) && (Copy_u8Mode <= OUTPUT_OPEN_DRAIN_PULL_DOWN))
			{
				SET_BIT(GPIOB_MODER,Copy_u8Pin * 2);
				CLR_BIT(GPIOB_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if((Copy_u8Mode >= AF_PUSH_PULL) && (Copy_u8Mode <= AF_OPEN_DRAIN_PULL_DOWN))
			{
				CLR_BIT(GPIOB_MODER,Copy_u8Pin * 2);
				SET_BIT(GPIOB_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if((Copy_u8Mode >= INPUT_FLOATING) && (Copy_u8Mode <= INPUT_PULL_DOWN))
			{
				CLR_BIT(GPIOB_MODER,Copy_u8Pin * 2);
				CLR_BIT(GPIOB_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if(Copy_u8Mode == INPUT_ANALOG)
			{
				SET_BIT(GPIOB_MODER,Copy_u8Pin * 2);
				SET_BIT(GPIOB_MODER,((Copy_u8Pin * 2) + 1));
			}
			switch (Copy_u8Mode)
			{
				case OUTPUT_PUSH_PULL 	:
				case AF_PUSH_PULL		:
				case INPUT_FLOATING   	:
					CLR_BIT(GPIOB_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOB_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOB_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_PUSH_PULL_PULL_UP 	:
				case AF_PUSH_PULL_PULL_UP		:
				case INPUT_PULL_UP 				:
					CLR_BIT(GPIOB_OTYPER,Copy_u8Pin);
					SET_BIT(GPIOB_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOB_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_PUSH_PULL_PULL_DOWN	:
				case AF_PUSH_PULL_PULL_DOWN		:
				case INPUT_PULL_DOWN			:
					CLR_BIT(GPIOB_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOB_PUPDR,Copy_u8Pin * 2);
					SET_BIT(GPIOB_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
				
				case OUTPUT_OPEN_DRAIN 	:
				case AF_OPEN_DRAIN		:
					SET_BIT(GPIOB_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOB_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOB_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
				
				case OUTPUT_OPEN_DRAIN_PULL_UP	:
				case AF_OPEN_DRAIN_PULL_UP		:
					SET_BIT(GPIOB_OTYPER,Copy_u8Pin);
					SET_BIT(GPIOB_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOB_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_OPEN_DRAIN_PULL_DOWN	:
				case AF_OPEN_DRAIN_PULL_DOWN		:
					SET_BIT(GPIOB_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOB_PUPDR,Copy_u8Pin * 2);
					SET_BIT(GPIOB_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
			}
			GPIOB_OSPEEDR &=~(3 << (Copy_u8Pin * 2));
			GPIOB_OSPEEDR |= (Copy_u8Speed <<(Copy_u8Pin * 2));
			break;
		case GPIOC :
			if((Copy_u8Mode >= OUTPUT_PUSH_PULL) && (Copy_u8Mode <= OUTPUT_OPEN_DRAIN_PULL_DOWN))
			{
				SET_BIT(GPIOC_MODER,Copy_u8Pin * 2);
				CLR_BIT(GPIOC_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if((Copy_u8Mode >= AF_PUSH_PULL) && (Copy_u8Mode <= AF_OPEN_DRAIN_PULL_DOWN))
			{
				CLR_BIT(GPIOC_MODER,Copy_u8Pin * 2);
				SET_BIT(GPIOC_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if((Copy_u8Mode >= INPUT_FLOATING) && (Copy_u8Mode <= INPUT_PULL_DOWN))
			{
				CLR_BIT(GPIOC_MODER,Copy_u8Pin * 2);
				CLR_BIT(GPIOC_MODER,((Copy_u8Pin * 2) + 1));
			}
			else if(Copy_u8Mode == INPUT_ANALOG)
			{
				SET_BIT(GPIOC_MODER,Copy_u8Pin * 2);
				SET_BIT(GPIOC_MODER,((Copy_u8Pin * 2) + 1));
			}
			switch (Copy_u8Mode)
			{
				case OUTPUT_PUSH_PULL 	:
				case AF_PUSH_PULL	  	:
				case INPUT_FLOATING   	:
					CLR_BIT(GPIOC_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOC_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOC_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_PUSH_PULL_PULL_UP 	:
				case AF_PUSH_PULL_PULL_UP		:
				case INPUT_PULL_UP 				:
					CLR_BIT(GPIOC_OTYPER,Copy_u8Pin);
					SET_BIT(GPIOC_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOC_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_PUSH_PULL_PULL_DOWN	:
				case AF_PUSH_PULL_PULL_DOWN		:
				case INPUT_PULL_DOWN			:
					CLR_BIT(GPIOC_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOC_PUPDR,Copy_u8Pin * 2);
					SET_BIT(GPIOC_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_OPEN_DRAIN 	:
				case AF_OPEN_DRAIN		:
					SET_BIT(GPIOC_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOC_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOC_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
				
				case OUTPUT_OPEN_DRAIN_PULL_UP	:
				case AF_OPEN_DRAIN_PULL_UP		:
					SET_BIT(GPIOC_OTYPER,Copy_u8Pin);
					SET_BIT(GPIOC_PUPDR,Copy_u8Pin * 2);
					CLR_BIT(GPIOC_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
					
				case OUTPUT_OPEN_DRAIN_PULL_DOWN	:
				case AF_OPEN_DRAIN_PULL_DOWN		:
					SET_BIT(GPIOC_OTYPER,Copy_u8Pin);
					CLR_BIT(GPIOC_PUPDR,Copy_u8Pin * 2);
					SET_BIT(GPIOC_PUPDR,((Copy_u8Pin * 2) + 1));
					break;
			}
			GPIOC_OSPEEDR &=~(3 << (Copy_u8Pin * 2));
			GPIOC_OSPEEDR |= (Copy_u8Speed <<(Copy_u8Pin * 2));
			break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{	
	switch(Copy_u8Port)
	{
		case GPIOA	:
			switch(Copy_u8Value)
			{
				case GPIO_u8PIN_LOW	 :	CLR_BIT(GPIOA_ODR,Copy_u8Pin);	break;
				case GPIO_u8PIN_HIGH :	SET_BIT(GPIOA_ODR,Copy_u8Pin);	break;
				default     		 : 	break;

			}
			break;
			
		case GPIOB	:
			switch(Copy_u8Value)
			{
				case GPIO_u8PIN_LOW	 :	CLR_BIT(GPIOB_ODR,Copy_u8Pin);	break;
				case GPIO_u8PIN_HIGH :	SET_BIT(GPIOB_ODR,Copy_u8Pin);	break;
				default     		 : 	break;

			}
			break;
			
		case GPIOC	:
			switch(Copy_u8Value)
			{
				case GPIO_u8PIN_LOW	 :	CLR_BIT(GPIOC_ODR,Copy_u8Pin);	break;
				case GPIO_u8PIN_HIGH :	SET_BIT(GPIOC_ODR,Copy_u8Pin);	break;
				default     		 : 	break;

			}
			break;
			
		default	: break;
		
	}
}

void MGPIO_voidSetPinValueAtomic(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
			switch(Copy_u8Value)
			{
				case GPIO_u8PIN_HIGH:	GPIOA_BSRR = (1 << Copy_u8Pin);			break;
				case GPIO_u8PIN_LOW	:	GPIOA_BSRR = (1 << (Copy_u8Pin + 16));	break;
			}
			break;
		
		case GPIOB :
			switch(Copy_u8Value)
			{
				case GPIO_u8PIN_HIGH:	GPIOB_BSRR = (1 << Copy_u8Pin);			break;
				case GPIO_u8PIN_LOW	:	GPIOB_BSRR = (1 << (Copy_u8Pin + 16));	break;
			}
			break;
		
		case GPIOC :
			switch(Copy_u8Value)
			{
				case GPIO_u8PIN_HIGH:	GPIOC_BSRR = (1 << Copy_u8Pin);			break;
				case GPIO_u8PIN_LOW	:	GPIOC_BSRR = (1 << (Copy_u8Pin + 16));	break;
			}
			break;
	}
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8PinValue=0;
	
	switch(Copy_u8Port)
	{
		case GPIOA	:	Local_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8Pin);	break;
		case GPIOB	:	Local_u8PinValue = GET_BIT(GPIOB_IDR,Copy_u8Pin);	break;
		case GPIOC	: 	Local_u8PinValue = GET_BIT(GPIOC_IDR,Copy_u8Pin);	break;
		default     : 	break;
	}
	return Local_u8PinValue;

}

void MGPIO_voidSetAF(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8AFSelection)
{
	switch(Copy_u8PORT)
	{
	case GPIOA:
		if(Copy_u8PIN <=7)
		{
			/* LOW */
			GPIOA_AFRL &= ~ ( ( 0b1111 )    << ( Copy_u8PIN * 4 ));
			GPIOA_AFRL |= ( Copy_u8AFSelection ) << ( Copy_u8PIN * 4 );

		}
		else if(Copy_u8PIN <=15)
		{
			/* HIGH */
			Copy_u8PIN = Copy_u8PIN - 8;
			GPIOA_AFRH &= ~ ( ( 0b1111 )    << ( Copy_u8PIN * 4 ));
			GPIOA_AFRH |= ( Copy_u8AFSelection ) << ( Copy_u8PIN * 4 );
		}
		break;

	case GPIOB :
		if(Copy_u8PIN <=7)
		{
			/* LOW */
			GPIOB_AFRL &= ~ ( ( 0b1111 )    << ( Copy_u8PIN * 4 ));
			GPIOB_AFRL |= ( Copy_u8AFSelection ) << ( Copy_u8PIN * 4 );

		}
		else if(Copy_u8PIN <=15)
		{
			/* HIGH */
			Copy_u8PIN = Copy_u8PIN - 8;
			GPIOB_AFRH &= ~ ( ( 0b1111 )    << ( Copy_u8PIN * 4 ));
			GPIOB_AFRH |= ( Copy_u8AFSelection ) << ( Copy_u8PIN * 4 );
		}
		break;

	case GPIOC :
		if(Copy_u8PIN <=7)
		{
			/* LOW */
			GPIOC_AFRL &= ~ ( ( 0b1111 )    << ( Copy_u8PIN * 4 ));
			GPIOC_AFRL |= ( Copy_u8AFSelection ) << ( Copy_u8PIN * 4 );

		}
		else if(Copy_u8PIN <=15)
		{
			/* HIGH */
			Copy_u8PIN = Copy_u8PIN - 8;
			GPIOC_AFRH &= ~ ( ( 0b1111 )    << ( Copy_u8PIN * 4 ));
			GPIOC_AFRH |= ( Copy_u8AFSelection ) << ( Copy_u8PIN * 4 );
		}
		break;

	default: break;

	}
}
