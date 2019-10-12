/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 *
 * @}
 */

/*#include "stdio.h"
#include "timex.h"
#include "xtimer.h"
#include "thread.h"*/

#include "stdio.h"
#include "timex.h"
#include "xtimer.h"
#include "periph/gpio.h"
#include "thread.h"

#define INTERVAL (1U * US_PER_SEC / 5)

xtimer_ticks32_t last_wakeup;

static void btn_handler(int arg)
{
	int x = arg;
	for(int i=0; i < x; i++)
	{
		xtimer_periodic_wakeup(&last_wakeup, INTERVAL/2);
		gpio_toggle(GPIO_PIN(PORT_C, 9));
		xtimer_periodic_wakeup(&last_wakeup, INTERVAL/2);
		gpio_toggle(GPIO_PIN(PORT_C, 9));
	}
	
}

int main(void)
{
	last_wakeup = xtimer_now();
	gpio_init(GPIO_PIN(PORT_C, 9), GPIO_OUT);
	gpio_init_int(GPIO_PIN(PORT_B, 0), GPIO_IN_PD, GPIO_BOTH, btn_handler, 1);
	gpio_init_int(GPIO_PIN(PORT_B, 1), GPIO_IN_PD, GPIO_BOTH, btn_handler, 2);
	gpio_init_int(GPIO_PIN(PORT_B, 2), GPIO_IN_PD, GPIO_BOTH, btn_handler, 3);
	gpio_init_int(GPIO_PIN(PORT_B, 10), GPIO_IN_PD, GPIO_BOTH, btn_handler, 4);

	while(1)
	{
		
	}
	return 0;
}

