#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>


#define ON 0
#define OFF 1

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


void vLEDTask(void *pvParameters)
{
	uint8_t LED = *((uint8_t*) pvParameters); // LED Color Parameter
	if (LED==1)
	{
		// If green LED offset of 1.5 second
		vTaskDelay(configTICK_RATE_HZ + configTICK_RATE_HZ/2);
	}

	if (LED == 2)
	{
		// If Blue LED offset of 3 seconds
		vTaskDelay(3*configTICK_RATE_HZ);
	}

	while (1)
	{
		Board_LED_Set(LED,ON); // 1 second
		vTaskDelay(configTICK_RATE_HZ);

		Board_LED_Set(LED,OFF); // 3.5 seconds
		vTaskDelay(3*configTICK_RATE_HZ + configTICK_RATE_HZ/2);
	}
}

/**
 * @brief main routine for FreeRTOS blinky example
 * @return Nothing, function should not exit
 */
int main(void)
{
	prvSetupHardware();

	/* LED1 toggle thread */
		xTaskCreate(vLEDTask, (signed char* ) "R_LED Task",
				configMINIMAL_STACK_SIZE,(void *)&led_red, (tskIDLE_PRIORITY + 3UL),
				(xTaskHandle *) NULL);

	/* LED2 toggle thread */
		xTaskCreate(vLEDTask, (signed char* ) "G_LED Task",
				configMINIMAL_STACK_SIZE,(void *)&led_green, (tskIDLE_PRIORITY + 2UL ),
				(xTaskHandle *) NULL);

	/* LED3 toggle thread */

		xTaskCreate(vLEDTask, (signed char* ) "B_LED Task",
				configMINIMAL_STACK_SIZE,(void *)&led_blue, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}
