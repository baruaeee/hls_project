#include "neuron_predictor_wrapper_fixpt.h"
#include "neuron_predictor_fixpt_logger.h"
#include "neuron_predictor_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

static emlrtRSInfo emlrtRSI{10, "neuron_predictor_wrapper_fixpt",
                            "/MATLAB "
                            "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/"
                            "fixpt/neuron_predictor_wrapper_fixpt.m"};

static emlrtRSInfo b_emlrtRSI{5, "neuron_predictor_fixpt_input_output_logger",
                              "src/LogInputsAndOutputs.cpp:55"};

void neuron_predictor_wrapper_fixpt(const emlrtStack *sp, real_T x_in,
                                    boolean_T reset, real_T *residual,
                                    real_T *predicted)
{
  static int16_T w[4];
  static int16_T x_hist[4];
  static int16_T b;
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int16_T b_x_in;
  int16_T i5;
  int16_T predicted_out;
  int16_T residual_out;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  d = muDoubleScalarFloor(x_in);
  if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
    d = 0.0;
  } else {
    d = muDoubleScalarRem(d, 2048.0);
  }
  if (static_cast<uint16_T>(static_cast<uint16_T>(static_cast<int16_T>(d)) &
                            1024) != 0) {
    b_x_in = static_cast<int16_T>(static_cast<int16_T>(d) | -1024);
  } else {
    b_x_in = static_cast<int16_T>(
        static_cast<uint16_T>(static_cast<int16_T>(d)) & 1023);
  }
  st.site = &emlrtRSI;
  if (!x_hist_not_empty || reset) {
    x_hist_not_empty = true;
    x_hist[0] = 0;
    x_hist[1] = 0;
    w[1] = 0;
    x_hist[2] = 0;
    w[2] = 0;
    x_hist[3] = 0;
    w[3] = 0;
    w[0] = 4096;
    b = 0;
  }
  i = x_hist[0] * w[0];
  i1 = x_hist[1] * w[1];
  i2 = x_hist[2] * w[2];
  i3 = x_hist[3] * w[3];
  if ((static_cast<uint32_T>(i) & 8388608U) != 0U) {
    i |= -8388608;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 8388607U);
  }
  if ((static_cast<uint32_T>(i1) & 8388608U) != 0U) {
    i1 |= -8388608;
  } else {
    i1 = static_cast<int32_T>(static_cast<uint32_T>(i1) & 8388607U);
  }
  i4 = i + i1;
  if ((static_cast<uint32_T>(i2) & 8388608U) != 0U) {
    i1 = i2 | -8388608;
  } else {
    i1 = static_cast<int32_T>(static_cast<uint32_T>(i2) & 8388607U);
  }
  if ((static_cast<uint32_T>(i3) & 8388608U) != 0U) {
    i = i3 | -8388608;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i3) & 8388607U);
  }
  i += i1;
  if ((static_cast<uint32_T>(i4) & 8388608U) != 0U) {
    i1 = i4 | -8388608;
  } else {
    i1 = static_cast<int32_T>(static_cast<uint32_T>(i4) & 8388607U);
  }
  if ((static_cast<uint32_T>(i) & 2097152U) != 0U) {
    i |= -2097152;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 2097151U);
  }
  i += b + i1;
  if ((static_cast<uint32_T>(i) & 8388608U) != 0U) {
    i |= -8388608;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 8388607U);
  }
  predicted_out = static_cast<int16_T>((static_cast<int64_T>(i) << 13) >> 25);
  i5 = static_cast<int16_T>(b_x_in - predicted_out);
  if (static_cast<uint16_T>(static_cast<uint16_T>(i5) & 512) != 0) {
    residual_out = static_cast<int16_T>(i5 | -512);
  } else {
    residual_out = static_cast<int16_T>(static_cast<uint16_T>(i5) & 511);
  }
  i5 = static_cast<int16_T>(
      b + static_cast<int32_T>(
              (static_cast<int64_T>(residual_out << 12) << 13) >> 23));
  if (static_cast<uint16_T>(static_cast<uint16_T>(i5) & 4096) != 0) {
    b = static_cast<int16_T>(i5 | -4096);
  } else {
    b = static_cast<int16_T>(static_cast<uint16_T>(i5) & 4095);
  }
  i = residual_out * x_hist[0];
  if ((static_cast<uint32_T>(i) & 262144U) != 0U) {
    i |= -262144;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 262143U);
  }
  i5 = static_cast<int16_T>(
      w[0] + static_cast<int32_T>((static_cast<int64_T>(i) << 13) >> 23));
  if (static_cast<uint16_T>(static_cast<uint16_T>(i5) & 8192) != 0) {
    w[0] = static_cast<int16_T>(i5 | -8192);
  } else {
    w[0] = static_cast<int16_T>(static_cast<uint16_T>(i5) & 8191);
  }
  i = residual_out * x_hist[1];
  if ((static_cast<uint32_T>(i) & 262144U) != 0U) {
    i |= -262144;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 262143U);
  }
  i5 = static_cast<int16_T>(
      w[1] + static_cast<int32_T>((static_cast<int64_T>(i) << 13) >> 23));
  if (static_cast<uint16_T>(static_cast<uint16_T>(i5) & 8192) != 0) {
    w[1] = static_cast<int16_T>(i5 | -8192);
  } else {
    w[1] = static_cast<int16_T>(static_cast<uint16_T>(i5) & 8191);
  }
  i = residual_out * x_hist[2];
  if ((static_cast<uint32_T>(i) & 262144U) != 0U) {
    i |= -262144;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 262143U);
  }
  i5 = static_cast<int16_T>(
      w[2] + static_cast<int32_T>((static_cast<int64_T>(i) << 13) >> 23));
  if (static_cast<uint16_T>(static_cast<uint16_T>(i5) & 8192) != 0) {
    w[2] = static_cast<int16_T>(i5 | -8192);
  } else {
    w[2] = static_cast<int16_T>(static_cast<uint16_T>(i5) & 8191);
  }
  i = residual_out * x_hist[3];
  if ((static_cast<uint32_T>(i) & 262144U) != 0U) {
    i |= -262144;
  } else {
    i = static_cast<int32_T>(static_cast<uint32_T>(i) & 262143U);
  }
  i5 = static_cast<int16_T>(
      w[3] + static_cast<int32_T>((static_cast<int64_T>(i) << 13) >> 23));
  if (static_cast<uint16_T>(static_cast<uint16_T>(i5) & 8192) != 0) {
    w[3] = static_cast<int16_T>(i5 | -8192);
  } else {
    w[3] = static_cast<int16_T>(static_cast<uint16_T>(i5) & 8191);
  }
  x_hist[3] = x_hist[2];
  x_hist[2] = x_hist[1];
  x_hist[1] = x_hist[0];
  x_hist[0] = b_x_in;
  b_st.site = &b_emlrtRSI;
  coder::b_neuron_predictor_fixpt_logger(b_st, b_x_in, reset, residual_out,
                                         predicted_out);
  *residual = residual_out;
  *predicted = predicted_out;
}
