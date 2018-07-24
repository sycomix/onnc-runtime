#include <operator/crop.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_crop_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int32_t input_input_ndim, const int32_t * restrict input_input_dims
  ,float * restrict output_output
  ,int32_t output_output_ndim, const int32_t * restrict output_output_dims
  ,int32_t * restrict border
  ,int32_t number_of_border
  ,int32_t * restrict scale
  ,int32_t number_of_scale
) {
}
