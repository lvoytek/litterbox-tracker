/*
 * Copyright (c) 2025 Lena Voytek <lena@voytek.dev>.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>

#include "litterbox.h"

static const struct device *const litterbox_apds_sensor = DEVICE_DT_GET_ONE(avago_apds9960);

bool litterbox_sensor_setup()
{
	return device_is_ready(litterbox_apds_sensor);
}

litterbox_status_t litterbox_get_current_status()
{
	return LITTERBOX_ERROR;
}
