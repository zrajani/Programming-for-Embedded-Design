#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>
#include "queue.h"    // Library to use the Queue API

xQueueHandle xQueue;  // Queue Handler

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

static void vSenderTask (void *pvParameters)
{
	uint8_t LED = *((uint8_t*) pvParameters); // LED Color Parameter
	//uint8_t xStatus;

	for (;;)
	{
		xQueueSendToBack (xQueue, &LED,0); // data sent back of the queue
	}
}

static void vRecieverTask (void *pvParameters)
{
	uint8_t LED; // Store the read value

	for (;;)
	{
		xQueueReceive(xQueue, &LED, 1000); // Rx Queue
		if (LED==1)
			{
				// If green LED offset of 6720 msecond
				vTaskDelay(0.6720*configTICK_RATE_HZ );
			}

			if (LED == 2)
			{
				// If Blue LED offset of 6720 mseconds
				vTaskDelay(0.6720*configTICK_RATE_HZ);
			}

		//while(1)
			//{
				Board_LED_Set(LED,ON); // 6720 msecond ON
				vTaskDelay(0.6720*configTICK_RATE_HZ);

				Board_LED_Set(LED,OFF); // 6720 mseconds OFF
				vTaskDelay(0.6720*configTICK_RATE_HZ);
			//}
	}
}

/**
 * @brief main routine for FreeRTOS blinky example
 * @return Nothing, function should not exit
 */
int main(void)
{
	xQueue = xQueueCreate(5,sizeof(uint8_t));
	prvSetupHardware();

	/* LED1 toggle thread (Sender)*/
		xTaskCreate(vSenderTask, (signed char* ) "Sender1",
				configMINIMAL_STACK_SIZE,(void *)&led_red, tskIDLE_PRIORITY+1UL,
				(xTaskHandle *) NULL);

	/* LED2 toggle thread (Sender) */
		xTaskCreate(vSenderTask, (signed char* ) "Sender2",
				configMINIMAL_STACK_SIZE,(void *)&led_green, tskIDLE_PRIORITY+2UL,
				(xTaskHandle *) NULL);

	/* LED3 toggle thread (Sender) */

		xTaskCreate(vSenderTask, (signed char* ) "Sender3",
				configMINIMAL_STACK_SIZE,(void *)&led_blue, tskIDLE_PRIORITY+3UL,
				(xTaskHandle *) NULL);

	/* Reciever */

		xTaskCreate(vRecieverTask,(signed char* ) "Receiver",
				configMINIMAL_STACK_SIZE,(void *)NULL, (tskIDLE_PRIORITY + 4UL),
				(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}
