#include ---





void main(void)
{
	/* Initialization :	1- RCC
						2- GPIO_ENABLE
						3- GPIO_INIT->Dirction
						 */
	
	OS_voidCreate(0,1000,LED1);
	OS_voidCreate(1,2000,LED2);

	OS_voidCreate(2,3000,LED3);

	OS_voidStart();
	
	while(1)
	{
		
	}
}

void LED1(void)
{
	static u8 Local_u8Pin0 = 0;
	TOGGLE_BIT(Local_u8Pin0,0);
	MGPIO_voidSetPinValue(GPIO_A,PIN0,Local_u8Pin0);
	
}

void LED2(void)
{
	static u8 Local_u8Pin1 = 0;
	TOGGLE_BIT(Local_u8Pin1,0);
	MGPIO_voidSetPinValue(GPIO_A,PIN1,Local_u8Pin1);
	
}

void LED3(void)
{
	static u8 Local_u8Pin2 = 0;
	TOGGLE_BIT(Local_u8Pin2,0);
	MGPIO_voidSetPinValue(GPIO_A,PIN2,Local_u8Pin2);
	
}