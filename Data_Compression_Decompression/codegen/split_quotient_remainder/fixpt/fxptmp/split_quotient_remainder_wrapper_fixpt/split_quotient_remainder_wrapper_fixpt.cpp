#include "split_quotient_remainder_wrapper_fixpt.h"
#include "rt_nonfinite.h"
#include "split_quotient_remainder_fixpt_logger.h"
#include "mwmathutil.h"

static emlrtRSInfo emlrtRSI{
    10, "split_quotient_remainder_wrapper_fixpt",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/Split_Quotient_Remainder/codegen/"
    "split_quotient_remainder/fixpt/split_quotient_remainder_wrapper_f"
    "ixpt.m"};

static emlrtRSInfo b_emlrtRSI{
    5, "split_quotient_remainder_fixpt_input_output_logger",
    "src/LogInputsAndOutputs.cpp:55"};

void split_quotient_remainder_wrapper_fixpt(const emlrtStack *sp, real_T u_in,
                                            real_T k_in, real_T *q_out,
                                            real_T *r_out)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  uint16_T b_u_in;
  uint16_T pow2_k;
  uint8_T b_k_in;
  uint8_T q_out_out;
  uint8_T r_out_out;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  d = muDoubleScalarFloor(u_in);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 1024.0);
  }
  b_u_in = static_cast<uint16_T>(
      static_cast<uint16_T>(static_cast<int16_T>(d)) & 1023);
  d = muDoubleScalarFloor(k_in);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 16.0);
  }
  b_k_in =
      static_cast<uint8_T>(static_cast<uint8_T>(static_cast<int8_T>(d)) & 15);
  st.site = &emlrtRSI;
  switch (b_k_in) {
  case 0:
    pow2_k = 1U;
    break;
  case 1:
    pow2_k = 2U;
    break;
  case 2:
    pow2_k = 4U;
    break;
  case 3:
    pow2_k = 8U;
    break;
  case 4:
    pow2_k = 16U;
    break;
  case 5:
    pow2_k = 32U;
    break;
  case 6:
    pow2_k = 64U;
    break;
  case 7:
    pow2_k = 128U;
    break;
  default:
    pow2_k = 256U;
    break;
  }
  q_out_out = static_cast<uint8_T>(
      static_cast<uint8_T>(((static_cast<uint64_T>(b_u_in) << 24) / pow2_k) >>
                           24) &
      127);
  r_out_out = static_cast<uint8_T>(
      (b_u_in - static_cast<uint32_T>(q_out_out) * pow2_k) & 131071U);
  b_st.site = &b_emlrtRSI;
  coder::e_split_quotient_remainder_fixp(b_st, b_u_in, b_k_in, q_out_out,
                                         r_out_out);
  *q_out = q_out_out;
  *r_out = r_out_out;
}
