/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 OCT 2022				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : LED MATRIX          		 ***********************/
/* Version 	: 1.10             			 ***********************/
/***************************************************************/

#ifndef LEDMATRIX_CONFIG_H_
#define LEDMATRIX_CONFIG_H_

#define LED_MATRIX_ROW_N		8
#define LED_MATRIX_COL_N		8

/* Please Write Pin Pair PORT,PIN */
#define LEDMRX_ROW0_PIN		GPIOA,0
#define LEDMRX_ROW1_PIN     GPIOA,1
#define LEDMRX_ROW2_PIN     GPIOA,2
#define LEDMRX_ROW3_PIN     GPIOA,3
#define LEDMRX_ROW4_PIN     GPIOA,4
#define LEDMRX_ROW5_PIN     GPIOA,5
#define LEDMRX_ROW6_PIN     GPIOA,6
#define LEDMRX_ROW7_PIN     GPIOA,7

/* Please Write Pin Pair PORT,PIN */
#define LEDMRX_COL0_PIN		GPIOB,0
#define LEDMRX_COL1_PIN     GPIOB,1
#define LEDMRX_COL2_PIN     GPIOB,5
#define LEDMRX_COL3_PIN     GPIOB,6
#define LEDMRX_COL4_PIN     GPIOB,7
#define LEDMRX_COL5_PIN     GPIOB,8
#define LEDMRX_COL6_PIN     GPIOB,9
#define LEDMRX_COL7_PIN     GPIOB,10

/* Diplay Speed */
#define LED_MATRIX_INIT_SPEED		20
#define LED_MATRIX_SPEED_STEP		5
#define LED_MATRIX_SPEED_LEMIT_1	5
#define LED_MATRIX_SPEED_LIMIT_2	50

typedef struct
{
	u8 PORT;
	u8 PIN;
}LED_MTRX;

LED_MTRX LedMatrixRow[LED_MATRIX_ROW_N] = 
{
	{GPIOA,PIN0},
	{GPIOA,PIN1},
	{GPIOA,PIN2},
	{GPIOA,PIN3},
	{GPIOA,PIN4},
	{GPIOA,PIN5},
	{GPIOA,PIN6},
	{GPIOA,PIN7}
};

LED_MTRX LedMatrixCol[LED_MATRIX_COL_N] =
{
	{GPIOB,PIN0},
	{GPIOB,PIN1},
	{GPIOB,PIN5},
	{GPIOB,PIN6},
	{GPIOB,PIN7},
	{GPIOB,PIN8},
	{GPIOB,PIN9},
	{GPIOB,PIN10}
	
};

#endif	/* LEDMATRIX_CONFIG_H_ */
