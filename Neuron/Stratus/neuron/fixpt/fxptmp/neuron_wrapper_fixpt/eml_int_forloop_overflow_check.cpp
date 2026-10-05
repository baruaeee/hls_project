#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

static emlrtRTEInfo h_emlrtRTEI{
    87, 33, "check_forloop_overflow_error",
    "/run/media/exotic/Cadence/Installed/MATLAB/R2025b/toolbox/eml/lib/matlab/"
    "eml/eml_int_forloop_overflow_check.m"};

namespace coder {
void check_forloop_overflow_error(const emlrtStack &sp)
{
  emlrtErrorWithMessageIdR2018a(
      &sp, &h_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
}

} // namespace coder
