/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 8 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : FBEC           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef FBEC_PRIVATE_H_
#define FBEC_PRIVATE_H_

typedef struct 
{
	u32 FLASH_ACR;
	u32 FLASH_KEYR;
	u32 FLASH_OPTKEYR;
	u32 FLASH_SR;
	u32 FLASH_CR;
	u32 FLASH_OPTCR;
}FBEC_t;

#define FBEC	((volatile FBEC_t*)0x40023C00)

/* FLASH Access Control Register Bits : FLASH_ACR */
#define FLASH_ACR_LATENCY_BIT0			0			/* Latency BIT 0 				*/
#define FLASH_ACR_LATENCY_BIT1			1			/* Latency BIT 1 				*/
#define FLASH_ACR_LATENCT_BIT2			2			/* Latency BIT 2 				*/
#define FLASH_ACR_LATENCY_BIT3			3			/* Latency BIT 3 				*/
#define FLASH_ACR_PRFTEN				8			/* Prefetch Enable 				*/
#define FLASH_ACR_ICEN					9			/* Instruction Cache Enable 	*/
#define FLASH_ACR_DCEN					10			/* Data Cache Enable 			*/
#define FLASH_ACR_ICRST					11			/* Instruction Cache Reset 		*/
#define FLASH_ACR_DCRST					12			/* Data Cache Reset 			*/

/* Flash Status Register Bits : FLASH_SR */
#define FLASH_SR_EOP					0			/* End Of Operation 			*/
#define FLASH_SR_OPERR					1			/* Operation Error 				*/
#define FLASH_SR_WRPERR					4			/* Write Protection Error 		*/
#define FLASH_SR_PGAERR					5			/* Programmming Allingment Error*/
#define FLASH_SR_PGPERR					6			/* programming Parallelism Error*/
#define FLASH_SR_PGSERR					7			/* Programming Sequence Error 	*/
#define FLASH_SR_RDERR					8			/* Read Protection Error 		*/
#define FLASH_SR_BSY					16			/* Busy							*/

/* Flash Contrl Register Bits : FLASH_CR */
#define FLASH_CR_PG						0			/* Programming : Flash Programming Activated 	*/
#define FLASH_CR_SER					1			/* Sector Erase 								*/
#define FLASH_CR_MER					2			/* Mass Erase 									*/
#define FLASH_CR_SNB_BIT0				3			/* Sector Number BIT 0 							*/
#define FLASH_CR_SNB_BIT1				4			/* Sector Number BIT 1 							*/
#define FLASH_CR_SNB_BIT2				5			/* Sector Number BIT 2 							*/
#define FLASH_CR_SNB_BIT4				6			/* Sector Number BIT 3 							*/
#define FLASH_CR_PSIZE_BIT0				8			/* Program Size BIT 0 							*/
#define FLASH_CR_PSIZE_BIT1				9			/* Program Size BIT 1 							*/
#define FLASH_CR_STRT					16			/* Start 										*/
#define FLASH_CR_EOPIE					24			/* End Of Operation Interrupt Enable 			*/
#define FLASH_CR_ERRIE					25			/* Error Interrupt Enable						*/
#define FLASH_CR_LOCK					31			/* LOCK 										*/

/* Flash Option Control Register Bits : FLASH_OPTCR */
#define FLASH_OPTCR_OPTLOCK				0			/* Option Lock 									*/
#define FLASH_OPTCR_OPTSTRT				1			/* Option Start 								*/	
#define FLASH_OPTCR_BOR_LEV_BIT0		2			/* BOR Reset Level BIT 0 						*/
#define FLASH_OPTCR_BOR_LEV_BIT1		3			/* BOR Reset Level BIT 1 						*/
#define FLASH_OPTCR_WDG_SW				5			/* User Option Bytes 							*/
#define FLASH_OPTCR_nRST_STOP			6			/* User Option Bytes 							*/
#define FLASH_OPTCR_nRST_STDBY			7			/* User Option Bytes 							*/
#define FLASH_OPTCR_nWRP_BIT0			22			/* No Write Protect BIT 0 						*/
#define FLASH_OPTCR_nWRP_BIT1			23 			/* No Write Protect BIT 1	 					*/
#define FLASH_OPTCR_SPRMOD				31			/* Selection Of Protection Mode Of nWPRi BITS	*/

/* FBEC Key : FLASH_FKEYR */
#define KEY1	0x45670123
#define KEY2	0xCDEF89AB

/* Option Byte Key : FLASH_OPTKEYR */
#define OPTKEY1		0x08192A3B
#define OPTKEY2 	0x4C5D6E7F


#endif	/* FBEC_PRIVATE_H_ */