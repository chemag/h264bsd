/*
 * Copyright (C) 2026 Chema Gonzalez
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "h264bsd_allocator.h"

#ifndef H264BSD_CUSTOM_ALLOCATOR
#include <stdlib.h>

void *h264bsdAllocMemory(size_t size)
{
    return malloc(size);
}

void h264bsdFreeMemory(void *memory)
{
    free(memory);
}
#endif
