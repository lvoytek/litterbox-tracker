/*
 * Copyright (c) 2025 Lena Voytek <lena@voytek.dev>.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LITTERBOX_H
#define LITTERBOX_H

#include <stdbool.h>

typedef enum {
	LITTERBOX_IDLE,
	LITTERBOX_WAITING,
	LITTERBOX_ERROR,
	LITTERBOX_OFF,
	LITTERBOX_UNKNOWN
} litterbox_status_t;

/**
 * @brief Initialize and confirm the APDS9960 sensor is ready.
 *
 * @return true if the device is ready, false otherwise.
 */
bool litterbox_sensor_setup();

/**
 * @brief Check light color and pulse to determine litterbox status.
 *
 * @param red_threshold The minimum red value to consider red light active.
 * @param blue_threshold The minimum blue value to consider blue light active.
 * @param flash_pulse_ms The pulse on/off duration in milliseconds of waiting status.
 * @return litterbox_status_t The current status of the litterbox.
 */
litterbox_status_t litterbox_get_current_status(int red_threshold, int blue_threshold,
						int flash_pulse_ms);

#endif
