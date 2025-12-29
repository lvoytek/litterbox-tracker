/*
 * Copyright (c) 2025 Lena Voytek <lena@voytek.dev>.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/sys/printk.h>

#include "litterbox.h"

static const struct device *const litterbox_apds_sensor = DEVICE_DT_GET_ONE(avago_apds9960);

bool litterbox_sensor_setup()
{
	return device_is_ready(litterbox_apds_sensor);
}

litterbox_status_t litterbox_get_current_status()
{
    struct sensor_value red_value, blue_value;

    if (sensor_sample_fetch(litterbox_apds_sensor) != 0) {
		printk("Sensor data fetch failed\n");
        return LITTERBOX_ERROR;
	}

    sensor_channel_get(litterbox_apds_sensor, SENSOR_CHAN_RED, &red_value);
    sensor_channel_get(litterbox_apds_sensor, SENSOR_CHAN_BLUE, &blue_value);

    printk("Red: %d, Blue: %d\n", red_value.val1, blue_value.val1);

    return LITTERBOX_ERROR;
}
