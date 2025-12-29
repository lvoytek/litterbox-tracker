/*
 * Copyright (c) 2025 Lena Voytek <lena@voytek.dev>.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "litterbox.h"

int main(void)
{
	if (!litterbox_sensor_setup()) {
		printk("sensor: device not ready.\n");
		return 0;
	}

	printk("Ready\n");

    while (1) {
        k_sleep(K_MSEC(1000));
        litterbox_get_current_status();
    }

	return 0;
}
