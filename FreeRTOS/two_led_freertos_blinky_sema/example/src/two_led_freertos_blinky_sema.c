/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>
#include "semphr.h"


#define ON 0
#define OFF 1

xSemaphoreHandle xMutex;  // Mutex Handler

// GLOBAL PARAMETER
uint8_t led_red = 0;
uint8_t led_green = 1;
uint8_t led_blue = 2;

/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED state is off */
	Board_LED_Set(0, OFF);
	Board_LED_Set(1, OFF);
	Board_LED_Set(2, OFF);

}

/* Thread/ Task Function Description */
void task1(void *pvParameters)
{
	uint8_t LED = *((uint8_t*) pvParameters); // LED Color Parameter
	while (1)
	{
		xSemaphoreTake(xMutex,portMAX_DELAY);
		Board_LED_Set(LED,ON);
		vTaskDelay(1000);
		Board_LED_Set(LED,OFF);
		vTaskDelay(500);
		xSemaphoreGive(xMutex);
		vTaskDelay(3500);
	}
}

static void task2 (void *pvParameters)
{
	while(1)
	{
		xSemaphoreTake(xMutex,portMAX_DELAY);
		taskENTER_CRITICAL();
		Board_LED_Set(2,ON);
		vTaskDelay(1000);
		Board_LED_Set(2,OFF);
		xSemaphoreGive(xMutex);
		taskEXIT_CRITICAL();
		vTaskDelay(3500);
	}
}

/**
 * @brief main routine for FreeRTOS blinky example
 * @return Nothing, function should not exit
 */
int main(void)
{
	/* Hardware Setup */
	prvSetupHardware();

	/* Mutex Creation */
	xMutex = xSemaphoreCreateMutex();

	/* LED1 toggle thread */
		xTaskCreate(task1, (signed char* ) "R_LED Task",
				configMINIMAL_STACK_SIZE,(void *)&led_red, (tskIDLE_PRIORITY + 3UL),
				(xTaskHandle *) NULL);

	/* LED2 toggle thread */
		xTaskCreate(task1, (signed char* ) "G_LED Task",
				configMINIMAL_STACK_SIZE,(void *)&led_green, (tskIDLE_PRIORITY + 2UL ),
				(xTaskHandle *) NULL);

	/* LED3 toggle thread */

		xTaskCreate(task2, (signed char* ) "B_LED Task",
				configMINIMAL_STACK_SIZE,NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}
