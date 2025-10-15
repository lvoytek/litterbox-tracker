/*
 * Copyright (c) 2025 Lena Voytek <lena@voytek.dev>.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include "litterbox.h"

int main(void)
{
	if (!litterbox_sensor_setup()) {
		printf("sensor: device not ready.\n");
		return 0;
	}

    if (litterbox_get_current_status() == LITTERBOX_ERROR) {
        printf("Error\n");
    }

	printf("Ready\n");

	return 0;
}
