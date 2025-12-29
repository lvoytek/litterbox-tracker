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

litterbox_status_t litterbox_get_current_status(int red_threshold, int blue_threshold,
						int flash_pulse_ms)
{
	const int num_readings = 6;
	struct sensor_value red_value, blue_value;

	int average_red_value = 0;
	int average_blue_value = 0;
	int blue_on_count = 0;

	for (int i = 0; i < num_readings; i++) {
		if (sensor_sample_fetch(litterbox_apds_sensor) != 0) {
			printk("Sensor data fetch failed\n");
			return LITTERBOX_UNKNOWN;
		}

		sensor_channel_get(litterbox_apds_sensor, SENSOR_CHAN_RED, &red_value);
		sensor_channel_get(litterbox_apds_sensor, SENSOR_CHAN_BLUE, &blue_value);

		average_red_value += red_value.val1;
		average_blue_value += blue_value.val1;

		if (blue_value.val1 >= blue_threshold) {
			blue_on_count++;
		}

		k_msleep(flash_pulse_ms);
	}

	average_red_value /= num_readings;
	average_blue_value /= num_readings;

	printk("Avg Red: %d, Avg Blue: %d, Blue On Count: %d\n", average_red_value,
	       average_blue_value, blue_on_count);

	if (average_red_value >= red_threshold) {
		return LITTERBOX_ERROR;
	} else if (blue_on_count > num_readings / 3 && blue_on_count < (num_readings * 2) / 3) {
		return LITTERBOX_WAITING;
	} else if (average_blue_value >= blue_threshold) {
		return LITTERBOX_IDLE;
	}

	return LITTERBOX_OFF;
}
