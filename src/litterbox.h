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
	LITTERBOX_RUNNING,
	LITTERBOX_ERROR
} litterbox_status_t;

bool litterbox_sensor_setup();
litterbox_status_t litterbox_get_current_status();

#endif
