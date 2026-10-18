# SPDX-FileCopyrightText: Copyright (c) 2026 Chema Gonzalez
# SPDX-License-Identifier: Apache-2.0

set(H264BSD_ZEPHYR_HEAP_BYTES 3145728 CACHE STRING
    "Bytes reserved for the H264BSD Zephyr heap")

file(GLOB h264bsd_sources CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_LIST_DIR}/../../src/*.c"
)
add_library(h264bsd OBJECT
  ${h264bsd_sources}
  h264bsd_zephyr_allocator.c
)
target_include_directories(h264bsd PUBLIC
  "${CMAKE_CURRENT_LIST_DIR}/../../src"
)
target_compile_definitions(h264bsd PRIVATE
  H264BSD_CUSTOM_ALLOCATOR=1
  H264BSD_ZEPHYR_HEAP_BYTES=${H264BSD_ZEPHYR_HEAP_BYTES}
)
target_compile_options(h264bsd PRIVATE
  -Wno-maybe-uninitialized
  -Wno-unused-but-set-variable
  -Wno-unused-parameter
  -Wno-unused-variable
)
target_link_libraries(h264bsd PRIVATE zephyr_interface)
