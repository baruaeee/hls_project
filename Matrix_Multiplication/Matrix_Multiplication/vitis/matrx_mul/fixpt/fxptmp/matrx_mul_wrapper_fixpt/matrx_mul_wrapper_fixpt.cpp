#include "matrx_mul_wrapper_fixpt.h"
#include "matrx_mul_fixpt_logger.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

static emlrtRSInfo emlrtRSI{10, "matrx_mul_wrapper_fixpt",
                            "/MATLAB "
                            "Drive/Matrix_Multiplication/vitis/matrx_mul/fixpt/"
                            "matrx_mul_wrapper_fixpt.m"};

static emlrtRSInfo b_emlrtRSI{5, "matrx_mul_fixpt_input_output_logger",
                              "src/LogInputsAndOutputs.cpp:55"};

void matrx_mul_wrapper_fixpt(const emlrtStack *sp, const real_T x[16],
                             const real_T w[16], real_T y[16])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T dv[2];
  int16_T x_in[16];
  int16_T y_out[16];
  uint16_T w_in[16];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (int32_T i{0}; i < 16; i++) {
    real_T d;
    d = muDoubleScalarFloor(x[i] * 8192.0);
    if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
      d = 0.0;
    } else {
      d = muDoubleScalarRem(d, 16384.0);
    }
    if (static_cast<uint16_T>(static_cast<uint16_T>(static_cast<int16_T>(d)) &
                              8192) != 0) {
      x_in[i] = static_cast<int16_T>(static_cast<int16_T>(d) | -8192);
    } else {
      x_in[i] = static_cast<int16_T>(
          static_cast<uint16_T>(static_cast<int16_T>(d)) & 8191);
    }
    d = muDoubleScalarFloor(w[i] * 131072.0);
    if (muDoubleScalarIsNaN(d) || muDoubleScalarIsInf(d)) {
      d = 0.0;
    } else {
      d = muDoubleScalarRem(d, 16384.0);
    }
    w_in[i] = static_cast<uint16_T>(
        static_cast<uint16_T>(static_cast<int16_T>(d)) & 16383);
  }
  st.site = &emlrtRSI;
  for (int32_T i{0}; i < 16; i++) {
    y_out[i] = 0;
  }
  for (int32_T i{0}; i < 4; i++) {
    int32_T i4;
    int16_T b_i;
    int16_T i1;
    int16_T i2;
    int16_T i3;
    b_i = x_in[i];
    i1 = x_in[i + 4];
    i2 = x_in[i + 8];
    i3 = x_in[i + 12];
    i4 = i << 2;
    for (int32_T j{0}; j < 4; j++) {
      int32_T i5;
      int32_T i7;
      int16_T i6;
      i5 = i + (j << 2);
      i6 = static_cast<int16_T>(((y_out[i5] << 15) + b_i * w_in[i4]) >> 15);
      if (static_cast<uint16_T>(static_cast<uint16_T>(i6) & 8192) != 0) {
        i7 = i6 | -8192;
      } else {
        i7 = static_cast<uint16_T>(static_cast<uint16_T>(i6) & 8191);
      }
      i6 = static_cast<int16_T>(
          ((static_cast<int16_T>(i7) << 15) + i1 * w_in[i4 + 1]) >> 15);
      if (static_cast<uint16_T>(static_cast<uint16_T>(i6) & 8192) != 0) {
        i7 = i6 | -8192;
      } else {
        i7 = static_cast<uint16_T>(static_cast<uint16_T>(i6) & 8191);
      }
      i6 = static_cast<int16_T>(
          ((static_cast<int16_T>(i7) << 15) + i2 * w_in[i4 + 2]) >> 15);
      if (static_cast<uint16_T>(static_cast<uint16_T>(i6) & 8192) != 0) {
        i7 = i6 | -8192;
      } else {
        i7 = static_cast<uint16_T>(static_cast<uint16_T>(i6) & 8191);
      }
      i6 = static_cast<int16_T>(
          ((static_cast<int16_T>(i7) << 15) + i3 * w_in[i4 + 3]) >> 15);
      if (static_cast<uint16_T>(static_cast<uint16_T>(i6) & 8192) != 0) {
        y_out[i5] = static_cast<int16_T>(i6 | -8192);
      } else {
        y_out[i5] = static_cast<int16_T>(static_cast<uint16_T>(i6) & 8191);
      }
    }
  }
  b_st.site = &b_emlrtRSI;
  coder::b_matrx_mul_fixpt_logger(b_st, x_in, w_in, y_out);
  for (int32_T i{0}; i <= 14; i += 2) {
    __m128d r;
    dv[0] = y_out[i];
    dv[1] = y_out[i + 1];
    r = _mm_loadu_pd(&dv[0]);
    r = _mm_mul_pd(r, _mm_set1_pd(3.0517578125E-5));
    _mm_storeu_pd(&y[i], r);
  }
}
