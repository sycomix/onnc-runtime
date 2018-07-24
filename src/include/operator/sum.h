#pragma once

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_sum_float(
  void * restrict onnc_runtime_context
  ,const float ** restrict input_data_0
  ,int32_t input_data_0_ntensor
  ,int32_t * input_data_0_ndim, const int32_t ** restrict input_data_0_dims
  ,float * restrict output_sum
  ,int32_t output_sum_ndim, const int32_t * restrict output_sum_dims
  
);
