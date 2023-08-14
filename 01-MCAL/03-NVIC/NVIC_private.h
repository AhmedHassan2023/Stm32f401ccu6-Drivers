/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 23 SEP 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : NVIC           		   	 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/* Base Address 0xE000E100 */
#define NVIC_ISER0		*((u32*)0xE000E100)				/* Enable External Interrupts from 0 to 31 	*/
#define NVIC_ISER1		*((u32*)0xE000E104)				/* Enable External Interrupts from 32 to 63 */

#define NVIC_ICER0		*((u32*)0xE000E180)				/* Disable External Interrupts from 0 to 31  */
#define NVIC_ICER1		*((u32*)0xE000E184)				/* Disable External Interrupts from 32 to 63 */

#define NVIC_ISPR0		*((u32*)0xE000E200)				/* Set Pending Flag Interrupts from 32 to 63 */
#define NVIC_ISPR1		*((u32*)0xE000E204)				/* Set Pending Flag Interrupts from 32 to 63 */

#define NVIC_ICPR0		*((u32*)0xE000E280)				/* Clear Pending Flag Interrupts from 32 to 63 */
#define NVIC_ICPR1		*((u32*)0xE000E284)				/* Clear Pending Flag Interrupts from 32 to 63 */

#define NVIC_ICPR0		*((u32*)0xE000E280)				/* Clear Pending Flag Interrupts from 32 to 63 */
#define NVIC_ICPR1		*((u32*)0xE000E284)	  			/* Clear Pending Flag Interrupts from 32 to 63 */

#define NVIC_IABR0		*((volatile u32*)0xE000E300)	/* Interrupt Active Bit Register form bit 0 to 31 */
#define NVIC_IABR1		*((volatile u32*)0xE000E304)	/* Interrupt Active Bit Register form bit 31 to 63 */

#define NVIC_IPR		((volatile u8*)0xE000E400)		/* Interrupt Priority Register */
  
#define SCB_AIRCR		*((volatile u32*)0xE000ED0C)	/* Application interrupt and reset control Register*/

#define NVIC_GROUP_4_SUB_0		0x05FA0300
#define NVIC_GROUP_3_SUB_1		0x05FA0400
#define NVIC_GROUP_2_SUB_2		0x05FA0500
#define NVIC_GROUP_1_SUB_3		0x05FA0600
#define NVIC_GROUP_0_SUB_4		0x05FA0700



#endif	/* NVIC_PRIVATE_H_ */
