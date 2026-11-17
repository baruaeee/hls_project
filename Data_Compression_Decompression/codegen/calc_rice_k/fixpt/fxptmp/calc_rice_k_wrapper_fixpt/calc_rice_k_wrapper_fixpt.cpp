#include "calc_rice_k_wrapper_fixpt.h"
#include "calc_rice_k_fixpt_logger.h"
#include "calc_rice_k_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

static emlrtRSInfo emlrtRSI{10, "calc_rice_k_wrapper_fixpt",
                            "/MATLAB "
                            "Drive/Dat_Comp_Decomp/Rice_Param_k/codegen/"
                            "calc_rice_k/fixpt/calc_rice_k_wrapper_fixpt.m"};

static emlrtRSInfo b_emlrtRSI{5, "calc_rice_k_fixpt_input_output_logger",
                              "src/LogInputsAndOutputs.cpp:55"};

real_T calc_rice_k_wrapper_fixpt(const emlrtStack *sp, real_T u_in,
                                 boolean_T reset)
{
  static uint16_T u_hist[8];
  static uint16_T win_sum;
  emlrtStack b_st;
  emlrtStack st;
  real_T k_out;
  uint16_T avg_u;
  uint16_T b_u_in;
  uint8_T k_out_out;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  k_out = muDoubleScalarFloor(u_in);
  if (muDoubleScalarIsNaN(k_out) || muDoubleScalarIsInf(k_out)) {
    k_out = 0.0;
  } else {
    k_out = muDoubleScalarRem(k_out, 1024.0);
  }
  b_u_in = static_cast<uint16_T>(
      static_cast<uint16_T>(static_cast<int16_T>(k_out)) & 1023);
  st.site = &emlrtRSI;
  if (!u_hist_not_empty || reset) {
    for (int32_T i{0}; i < 8; i++) {
      u_hist[i] = 4U;
    }
    u_hist_not_empty = true;
    win_sum = 32U;
  }
  avg_u = static_cast<uint16_T>((static_cast<uint32_T>(win_sum) << 13) >> 16);
  if (avg_u >= 256) {
    k_out_out = 8U;
  } else if (avg_u >= 128) {
    k_out_out = 7U;
  } else if (avg_u >= 64) {
    k_out_out = 6U;
  } else if (avg_u >= 32) {
    k_out_out = 5U;
  } else if (avg_u >= 16) {
    k_out_out = 4U;
  } else if (avg_u >= 8) {
    k_out_out = 3U;
  } else if (avg_u >= 4) {
    k_out_out = 2U;
  } else {
    k_out_out = (avg_u >= 2);
  }
  win_sum = static_cast<uint16_T>(
      static_cast<uint16_T>(static_cast<uint16_T>(win_sum + b_u_in) -
                            u_hist[7]) &
      4095);
  for (int32_T i{6}; i >= 0; i--) {
    u_hist[i + 1] = u_hist[i];
  }
  u_hist[0] = b_u_in;
  b_st.site = &b_emlrtRSI;
  coder::b_calc_rice_k_fixpt_logger(b_st, b_u_in, reset, k_out_out);
  return k_out_out;
}
