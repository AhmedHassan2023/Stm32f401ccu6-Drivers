/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : GPIO           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/* PORT Selection */
#define GPIOA		0
#define GPIOB		1
#define GPIOC		2

/* PIN Selection */
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7	
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14	
#define PIN15		15

/* Output Value */
#define GPIO_u8PIN_LOW		0
#define GPIO_u8PIN_HIGH		1

/* PIN Direction Modes */
#define LOW_SPEED		0
#define MEDIUM_SPEED	1
#define FAST_SPEED		2
#define HIGH_SPEED		3

#define INPUT_FLOATING		1
#define INPUT_PULL_UP		2
#define INPUT_PULL_DOWN		3
#define INPUT_ANALOG		4


#define OUTPUT_PUSH_PULL				5
#define OUTPUT_PUSH_PULL_PULL_UP		6
#define OUTPUT_PUSH_PULL_PULL_DOWN		7

#define OUTPUT_OPEN_DRAIN				8
#define OUTPUT_OPEN_DRAIN_PULL_UP		9
#define OUTPUT_OPEN_DRAIN_PULL_DOWN		10

#define AF_PUSH_PULL					11
#define AF_PUSH_PULL_PULL_UP			12
#define AF_PUSH_PULL_PULL_DOWN			13

#define AF_OPEN_DRAIN					14
#define AF_OPEN_DRAIN_PULL_UP			15
#define AF_OPEN_DRAIN_PULL_DOWN			16

/* Alternative Function Mode Selection */
#define AF0			0
#define AF1			1
#define AF2			2
#define AF3			3
#define AF4			4
#define AF5			5
#define AF6			6
#define AF7			7
#define AF8			8
#define AF9			9
#define AF10		10
#define AF11		11
#define AF12		12
#define AF13		13
#define AF14		14
#define AF15		15


void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode, u8 Copy_u8Speed);

void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void MGPIO_voidSetAF(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8AFSelection);


#endif	/* GPIO_INTERFACE_H_ */
