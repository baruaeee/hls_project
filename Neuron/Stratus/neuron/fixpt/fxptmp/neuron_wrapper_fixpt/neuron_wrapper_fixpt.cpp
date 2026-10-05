#include "neuron_wrapper_fixpt.h"
#include "neuron_fixpt_logger.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

static emlrtRSInfo emlrtRSI{11, "neuron_wrapper_fixpt",
                            "/mnt/windows_share/GitRepo/HLS_Thesis/Neuron/"
                            "Stratus/neuron/fixpt/neuron_wrapper_fixpt.m"};

static emlrtRSInfo b_emlrtRSI{5, "neuron_fixpt_input_output_logger",
                              "src/LogInputsAndOutputs.cpp:56"};

real_T neuron_wrapper_fixpt(const emlrtStack *sp, const real_T x[4],
                            const real_T w[4], real_T b)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T y;
  int32_T i;
  int16_T x_in[4];
  int16_T y_out;
  uint16_T w_in[4];
  uint8_T b_b;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y = muDoubleScalarFloor(x[0] * 4096.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  if (static_cast<uint16_T>(static_cast<uint16_T>(static_cast<int16_T>(y)) &
                            8192) != 0) {
    x_in[0] = static_cast<int16_T>(static_cast<int16_T>(y) | -8192);
  } else {
    x_in[0] = static_cast<int16_T>(
        static_cast<uint16_T>(static_cast<int16_T>(y)) & 8191);
  }
  y = muDoubleScalarFloor(w[0] * 16384.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  w_in[0] = static_cast<uint16_T>(
      static_cast<uint16_T>(static_cast<int16_T>(y)) & 16383);
  y = muDoubleScalarFloor(x[1] * 4096.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  if (static_cast<uint16_T>(static_cast<uint16_T>(static_cast<int16_T>(y)) &
                            8192) != 0) {
    x_in[1] = static_cast<int16_T>(static_cast<int16_T>(y) | -8192);
  } else {
    x_in[1] = static_cast<int16_T>(
        static_cast<uint16_T>(static_cast<int16_T>(y)) & 8191);
  }
  y = muDoubleScalarFloor(w[1] * 16384.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  w_in[1] = static_cast<uint16_T>(
      static_cast<uint16_T>(static_cast<int16_T>(y)) & 16383);
  y = muDoubleScalarFloor(x[2] * 4096.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  if (static_cast<uint16_T>(static_cast<uint16_T>(static_cast<int16_T>(y)) &
                            8192) != 0) {
    x_in[2] = static_cast<int16_T>(static_cast<int16_T>(y) | -8192);
  } else {
    x_in[2] = static_cast<int16_T>(
        static_cast<uint16_T>(static_cast<int16_T>(y)) & 8191);
  }
  y = muDoubleScalarFloor(w[2] * 16384.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  w_in[2] = static_cast<uint16_T>(
      static_cast<uint16_T>(static_cast<int16_T>(y)) & 16383);
  y = muDoubleScalarFloor(x[3] * 4096.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  if (static_cast<uint16_T>(static_cast<uint16_T>(static_cast<int16_T>(y)) &
                            8192) != 0) {
    x_in[3] = static_cast<int16_T>(static_cast<int16_T>(y) | -8192);
  } else {
    x_in[3] = static_cast<int16_T>(
        static_cast<uint16_T>(static_cast<int16_T>(y)) & 8191);
  }
  y = muDoubleScalarFloor(w[3] * 16384.0);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 16384.0);
  }
  w_in[3] = static_cast<uint16_T>(
      static_cast<uint16_T>(static_cast<int16_T>(y)) & 16383);
  y = muDoubleScalarFloor(b);
  if (muDoubleScalarIsNaN(y) || muDoubleScalarIsInf(y)) {
    y = 0.0;
  } else {
    y = muDoubleScalarRem(y, 2.0);
  }
  b_b = static_cast<uint8_T>(static_cast<uint8_T>(static_cast<int8_T>(y)) & 1);
  st.site = &emlrtRSI;
  i = x_in[0] * w_in[0] + x_in[1] * w_in[1];
  if ((static_cast<uint32_T>(i) & 536870912U) != 0U) {
    i |= -536870912;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 536870911U);
  }
  i += x_in[2] * w_in[2];
  if ((static_cast<uint32_T>(i) & 536870912U) != 0U) {
    i |= -536870912;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 536870911U);
  }
  i += x_in[3] * w_in[3];
  if ((static_cast<uint32_T>(i) & 536870912U) != 0U) {
    i |= -536870912;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 536870911U);
  }
  y_out = static_cast<int16_T>((i + (b_b << 26)) >> 11);
  if (static_cast<uint16_T>(static_cast<uint16_T>(y_out) & 8192) != 0) {
    y_out = static_cast<int16_T>(y_out | -8192);
  } else {
    y_out = static_cast<int16_T>(static_cast<uint16_T>(y_out) & 8191);
  }
  b_st.site = &b_emlrtRSI;
  coder::b_neuron_fixpt_logger(b_st, x_in, w_in, b_b, y_out);
  return static_cast<real_T>(y_out) * 3.0517578125E-5;
}
