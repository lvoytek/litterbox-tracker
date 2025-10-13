/*
 * Copyright (c) 2025 Lena Voytek <lena@voytek.dev>.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <stdio.h>

static const struct device *const apds_sensor = DEVICE_DT_GET_ONE(avago_apds9960);

int main(void)
{
    if (!device_is_ready(apds_sensor)) {
		printf("sensor: device not ready.\n");
		return 0;
	}

    printf("Ready\n");

    return 0;
}
