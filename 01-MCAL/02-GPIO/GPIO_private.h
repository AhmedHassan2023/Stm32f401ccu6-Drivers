/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : GPIO           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/* GPIO Base Address */
#define GPIOA_BASE_ADDRESS		0x40020000 
#define GPIOB_BASE_ADDRESS		0x40020400	
#define GPIOC_BASE_ADDRESS		0x40020800

/* GPIOA Registers */
#define GPIOA_MODER				*((u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_OTYPER			*((u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_OSPEEDR			*((u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_PUPDR				*((u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_IDR				*((u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_ODR				*((u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_BSRR				*((u32*)(GPIOA_BASE_ADDRESS + 0x18))
#define GPIOA_LCKR				*((u32*)(GPIOA_BASE_ADDRESS + 0x1C))
#define GPIOA_AFRL				*((u32*)(GPIOA_BASE_ADDRESS + 0x20))
#define GPIOA_AFRH				*((u32*)(GPIOA_BASE_ADDRESS + 0x24))



/* GPIOB Registers */
#define GPIOB_MODER				*((u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_OTYPER			*((u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_OSPEEDR			*((u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_PUPDR				*((u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_IDR				*((u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_ODR				*((u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_BSRR				*((u32*)(GPIOA_BASE_ADDRESS + 0x18))
#define GPIOB_LCKR				*((u32*)(GPIOA_BASE_ADDRESS + 0x1C))
#define GPIOB_AFRL				*((u32*)(GPIOA_BASE_ADDRESS + 0x20))
#define GPIOB_AFRH				*((u32*)(GPIOA_BASE_ADDRESS + 0x24))


/* GPIOC Registers */
#define GPIOC_MODER				*((u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_OTYPER			*((u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_OSPEEDR			*((u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_PUPDR				*((u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_IDR				*((u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_ODR				*((u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_BSRR				*((u32*)(GPIOA_BASE_ADDRESS + 0x18))
#define GPIOC_LCKR				*((u32*)(GPIOA_BASE_ADDRESS + 0x1C))
#define GPIOC_AFRL				*((u32*)(GPIOA_BASE_ADDRESS + 0x20))
#define GPIOC_AFRH				*((u32*)(GPIOA_BASE_ADDRESS + 0x24))



#endif	/* GPIO_PRIVATE_H_ */
