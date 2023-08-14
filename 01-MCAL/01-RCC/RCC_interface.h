/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 12 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : RCC           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* System Buses*/
#define RCC_AHB1	0
#define RCC_AHB2	1
#define RCC_APB1	2
#define RCC_APB2	3
#define RCC_AHB1LP	4

/* AHB1 Peripherals */
#define GPIOA_EN		0				/* GPIO Port A Clock Enable 						*/
#define GPIOB_EN		1				/* GPIO Port B Clock Enable 						*/
#define GPIOC_EN		2				/* GPIO Port C Clock Enable 						*/
#define GPIOD_EN		3				/* GPIO Port D Clock Enable 						*/
#define GPIOE_EN		4				/* GPIO Port E Clock Enable 						*/
#define GPIOH_EN		7				/* GPIO Port H Clock Enable				 			*/
#define CRC_EN			12				/* CRC Clock Enable  								*/
#define DMA1_EN			21				/* DMA1 Clock Enable 								*/
#define DMA2_EN			22				/* DMA2 CLock Enable								*/

/* APB1 Peripherals */
#define TIM2_EN		0					/* TIM2 Clock Enable 								*/
#define TIM3_EN		1					/* TIM3 CLock Enable 								*/
#define TIM4_EN		2					/* TIM4 Clock Enable 								*/
#define TIM5_EN		3					/* TIM5 Clock Enable 								*/
#define WWDG_EN		11					/* Window Watchdog Clock Enable 					*/
#define SPI2_EN		14					/* SPI2 Clock Enable 								*/
#define SPI3_EN		15					/* SPI3 CLock Enable 								*/
#define USART2_EN	17					/* USART2 Clock Enable 								*/
#define I2C1_EN		21					/* I2C1 Clock Enable 								*/
#define I2C2_EN		22					/* I2C2 Clock Enable 								*/
#define I2C3_EN		23					/* I2C3 Clock Enable 								*/
#define PWR_EN		28					/* Power Interface Clock Enable 					*/

/* APB2 Peripherals */
#define TIM1_EN			0				/* TIM1 Clock Enable								*/
#define USART1_EN		4				/* USART1 Clock Enable 								*/
#define USART6_EN		5				/* USART6 Clock Enable 								*/
#define ADC1_EN			8				/* ADC1 Clock Enable 								*/
#define SDIO_EN			11				/* SDIO CLock Enable 								*/
#define SPI1_EN			12				/* SPI1 Clock Enable 								*/
#define SPI4_EN			13				/* SPI4 Clock Enable 								*/
#define SYSCFG_EN		14				/*  System Configuration Controller Clock Enable 	*/
#define TIM9_EN			16				/* TIM9 Clock Enable 								*/
#define TIM10_EN		17				/* TIM10 Clock Enable								*/
#define TIM11_EN		18				/* TIM11 Clock Enable 								*/

/* AHB1LP Peripherals */
#define FLITFLB_EN		15				/* Flash interface clock enable during Sleep mode	*/

void RCC_voidInitSysClock(void);

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

void RCC_voidSetAHBBusPrescaler(u8 Copy_u8Prescaler);


#endif		/*RCC_INTERFACE_H_*/
