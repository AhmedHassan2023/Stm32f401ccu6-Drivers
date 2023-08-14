/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 12 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : RCC           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* RCC Base Address ---> 0x40023800 */
/* Register Definetions */
#define RCC_CR					*((u32*)0x40023800)
#define RCC_PLLCFGR				*((u32*)0x40023804)
#define RCC_CFGR				*((u32*)0x40023808)
#define RCC_CIR					*((u32*)0x4002380C)
#define RCC_AHB1RSTR			*((u32*)0x40023810)
#define RCC_AHB2RSTR			*((u32*)0x40023814)
#define RCC_APB1RSTR			*((u32*)0x40023820)
#define RCC_APB2RSTR			*((u32*)0x40023824)
#define RCC_AHB1ENR				*((u32*)0x40023830)
#define RCC_AHB2ENR				*((u32*)0x40023834)
#define RCC_APB1ENR				*((u32*)0x40023840)
#define RCC_APB2ENR				*((u32*)0x40023844)
#define RCC_AHB1LPENR			*((u32*)0x40023850)
#define RCC_AHB2LPENR			*((u32*)0x40023854)
#define RCC_APB1LPENR			*((u32*)0x40023860)
#define RCC_APB2LPENR			*((u32*)0x40023864)
#define RCC_BDCR				*((u32*)0x40023870)
#define RCC_CSR					*((u32*)0x40023874)
#define RCC_SSCGR				*((u32*)0x40023880)
#define RCC_PLLI2SCFGR			*((u32*)0x40023884)
#define RCC_DCKCFGR				*((u32*)0x4002388C)

/* CR Register Bits */
#define CR_HSI_ON_BIT		0
#define CR_HSI_RDY_BIT		1

#define CR_HSE_ON_BIT		16
#define CR_HSE_RDY_BIT		17
#define CR_HSE_BYPASS_BIT	18

#define CR_PLL_ON_BIT		24
#define CR_PLL_RDY_BIT		25

/* CFGR Register Bits , System Clock Switch */
#define CFGR_SW0		0
#define CFGR_SW1		1



/* Clock Types */
#define RCC_HSE_CRYSTAL		0
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_PLL				3	

/* PLL Options */
#define  RCC_PLL_IN_HSI_DIV_2	0
#define  RCC_PLL_IN_HSE_DIV_2	1
#define  RCC_PLL_IN_HSE			2

#define AHB_PRESCALER_MASK (15 << 4)
	
#endif
