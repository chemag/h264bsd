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

#include <stdio.h>

#include "h264bsd_deblocking_internal.h"

struct filter_delta_case {
  i32 p0;
  i32 q0;
  i32 p1;
  i32 q1;
  i32 expected;
};

int main(void) {
  static const struct filter_delta_case cases[] = {
      {100, 88, 90, 80, -5}, {88, 100, 80, 90, 5},    {255, 0, 255, 0, -96},
      {0, 255, 0, 255, 96},  {128, 128, 128, 128, 0},
  };

  for (size_t index = 0; index < sizeof(cases) / sizeof(cases[0]); ++index) {
    const struct filter_delta_case* test = &cases[index];
    i32 actual = h264bsdFilterDelta(test->p0, test->q0, test->p1, test->q1);

    if (actual != test->expected) {
      fprintf(stderr, "case %zu: expected %d, got %d\n", index, test->expected,
              actual);
      return 1;
    }
  }
  return 0;
}
