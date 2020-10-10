/*
 * @brief Blinky example using sysTick
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
#include <stdio.h>

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

#define TICKRATE_HZ1 (10)	/* 10 ticks per second */

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */

void delay (int seconds)
{
	unsigned long int count =3333333, i,j;
	for (i=0;i<=seconds;i++)
	{
		for (j=0;j<count;j++)
		{

		}
	}
}

unsigned short int which_led=0;
unsigned short int on_or_off;

void SysTick_Handler(void)
{
	switch (which_led)
	{
	case 0:
	{
		if (on_or_off==1)
		{
			Board_LED_Set(which_led,false);
			on_or_off=0;
			delay(10);
		}
		else
		{
			Board_LED_Set(which_led,true);
			on_or_off=1;
			which_led=1;
			delay(10);
		}
		break;
	}
	case 1:
	{
		if (on_or_off==1)
		{
			Board_LED_Set(which_led,false);
			on_or_off=0;
			delay(10);
		}
		else
		{
			Board_LED_Set(which_led,true);
			on_or_off=1;
			which_led=2;
			delay(10);
		}
		break;
	}
	case 2:
	{
		if (on_or_off==1)
		{
			Board_LED_Set(which_led,false);
			on_or_off=0;
			delay(10);
		}
		else
		{
			Board_LED_Set(which_led,true);
			on_or_off=1;
			which_led=0;
			delay(10);
		}
		break;
	}
	}
	//Board_LED_Toggle(0);
}

/**
 * @brief	main routine for systick example
 * @return	Function should not exit.
 */
int main(void)
{
	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_LED_Set(0,false);
	Board_LED_Set(1,false);
	Board_LED_Set(2,false);
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* LEDs toggle in interrupt handlers */
	while (1) {
		__WFI();
	}

	return 0;
}


