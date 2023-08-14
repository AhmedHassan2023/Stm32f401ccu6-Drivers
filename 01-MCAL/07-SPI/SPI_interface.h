/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 30 NOV 2022				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SPI           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* SPI Modes */
#define SPI1_MASTER		1
#define SPI1_SLAVE		2	

/* SPI Baud Rate Control*/
#define SPI1_CLK_OVER_2		0
#define SPI1_CLK_OVER_4		1
#define SPI1_CLK_OVER_8		2
#define SPI1_CLK_OVER_16		3
#define SPI1_CLK_OVER_32		4
#define SPI1_CLK_OVER_64		5
#define SPI1_CLK_OVER_128	6
#define SPI1_CLK_OVER_256 	7

/* SPI Data Transmit Order */
#define SPI1_MSB		1
#define SPI1_LSB		2

/* SPI Clock Polarity*/
#define SPI1_FALLING_EDGE	1
#define SPI1_RISING_EDGE		2

/* SPI Clock Phase */
#define SPI1_SAMPLE			1
#define SPI1_SETUP			2

void SPI1_voidInit(void);

u8 SPI1_u8SendReciveSynch(u8 Copy_u8DataToTransmit,u8 *Copy_pu8ReceivedData);

u8 SPI1_u8SendReceiveAsynch(u8 Copy_u8DataToTransmit,u8 *Copy_pu8ReceivedData, void (*Copy_pvNotificationFunc)(void));


#endif	/* SPI_INTERFACE_H_ */
