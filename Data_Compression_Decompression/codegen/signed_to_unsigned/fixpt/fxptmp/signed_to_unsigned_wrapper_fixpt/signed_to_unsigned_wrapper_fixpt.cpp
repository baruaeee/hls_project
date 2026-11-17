#include "signed_to_unsigned_wrapper_fixpt.h"
#include "rt_nonfinite.h"
#include "signed_to_unsigned_fixpt_logger.h"
#include "mwmathutil.h"

static emlrtRSInfo emlrtRSI{
    9, "signed_to_unsigned_wrapper_fixpt",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/Map_signed_to_unsingned/codegen/signed_to_unsigned/"
    "fixpt/signed_to_unsigned_wrapper_fixpt.m"};

static emlrtRSInfo b_emlrtRSI{5, "signed_to_unsigned_fixpt_input_output_logger",
                              "src/LogInputsAndOutputs.cpp:55"};

real_T signed_to_unsigned_wrapper_fixpt(const emlrtStack *sp, real_T e_in)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T u_out;
  int16_T b_e_in;
  uint16_T u_out_out;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  u_out = muDoubleScalarFloor(e_in);
  if (muDoubleScalarIsNaN(u_out) || muDoubleScalarIsInf(u_out)) {
    u_out = 0.0;
  } else {
    u_out = muDoubleScalarRem(u_out, 1024.0);
  }
  if (static_cast<uint16_T>(static_cast<uint16_T>(static_cast<int16_T>(u_out)) &
                            512) != 0) {
    b_e_in = static_cast<int16_T>(static_cast<int16_T>(u_out) | -512);
  } else {
    b_e_in = static_cast<int16_T>(
        static_cast<uint16_T>(static_cast<int16_T>(u_out)) & 511);
  }
  st.site = &emlrtRSI;
  if (b_e_in >= 0) {
    u_out_out =
        static_cast<uint16_T>(static_cast<uint16_T>(b_e_in << 1) & 1023);
  } else {
    u_out_out =
        static_cast<uint16_T>(static_cast<uint16_T>(-2 * b_e_in - 1) & 1023);
  }
  b_st.site = &b_emlrtRSI;
  coder::b_signed_to_unsigned_fixpt_logg(b_st, b_e_in, u_out_out);
  return u_out_out;
}
