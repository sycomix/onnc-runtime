#pragma once

#include "constant.h"

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_constant_float(
  void * restrict onnc_runtime_context
  
  ,float * restrict output_output
  ,int32_t output_output_ndim, const int32_t * restrict output_output_dims
  ,void * restrict value
) {
}