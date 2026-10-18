/* SPDX-FileCopyrightText: Copyright (c) 2026 Chema Gonzalez */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "h264bsd_allocator.h"

LOG_MODULE_REGISTER(h264bsd_allocator, LOG_LEVEL_ERR);
K_HEAP_DEFINE(h264bsd_heap, H264BSD_ZEPHYR_HEAP_BYTES);

void *h264bsdAllocMemory(size_t size)
{
    void *memory = k_heap_alloc(&h264bsd_heap, size, K_NO_WAIT);

    if (memory == NULL) {
        LOG_ERR("allocation failed: %zu bytes", size);
    }
    return memory;
}

void h264bsdFreeMemory(void *memory)
{
    k_heap_free(&h264bsd_heap, memory);
}
