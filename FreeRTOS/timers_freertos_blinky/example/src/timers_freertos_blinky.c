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
#include "semphr.h"
#include "queue.h"
#include "timers.h"



xTimerHandle xtimer;    // Timer Handler


static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
	/* Initial LED0 state is off */
	Board_LED_Set(0, true);
	Board_LED_Set(1, true);
	Board_LED_Set(2, true);
}

/* LED1 toggle thread */
uint32_t pre_count = 4;

void vLEDTask1(xTimerHandle xTimer) {
	const uint32_t max_count = 3;

	uint32_t ulCount;

	ulCount = ( uint32_t ) pvTimerGetTimerID( xTimer );

	if(ulCount <=max_count){

		if(ulCount == 0){
			Board_LED_Set(0, false);
			Board_LED_Set(1, true);
			Board_LED_Set(2, true);
		}
		else  if (ulCount == 1){
			Board_LED_Set(0, true);
			Board_LED_Set(1, false);
			Board_LED_Set(2, true);
		}
		else if(ulCount == 2){
			Board_LED_Set(0, true);
			Board_LED_Set(1, true);
			Board_LED_Set(2, false);
		}


		ulCount++;
		pvTimerSetTimerID(( void * ) ulCount , xTimer );
	}

	else{
		ulCount = 0;
		pvTimerSetTimerID(( void * ) ulCount , xTimer );
	}



}

int main(void)
{


	xtimer = xTimerCreate("timer",2000,pdTRUE,( void * ) 0,vLEDTask1);

	prvSetupHardware();
	/* LED1 toggle thread */
	if(xtimer != NULL)
	{
		xTimerStart(xtimer,0);
		vTaskStartScheduler();
	}
	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
