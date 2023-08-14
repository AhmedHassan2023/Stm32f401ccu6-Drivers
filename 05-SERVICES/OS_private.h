/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 10 NOV 2022				 ***********************/
/* Layer   	: SERVICES           		 ***********************/
/* SWC      : OS          				 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

typedef struct
{
	u16 Priodicity;
	void (*TaskFunc)(void);
	
	
}Task_t;

static Task_t SystemTasks[TASK_NUM] = {{NULL}};



#endif	/* OS_PRIVATE_H_ */