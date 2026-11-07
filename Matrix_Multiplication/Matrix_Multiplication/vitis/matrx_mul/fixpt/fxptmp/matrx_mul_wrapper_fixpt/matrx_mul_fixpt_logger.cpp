#include "matrx_mul_fixpt_logger.h"
#include "indexShapeCheck.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

static real_T iterCount;

static boolean_T iterCount_not_empty;

static coder::array<int16_T, 3U> p;

static boolean_T p_not_empty;

static coder::array<uint16_T, 3U> b_p;

static boolean_T b_p_not_empty;

static coder::array<int16_T, 3U> c_p;

static boolean_T c_p_not_empty;

static emlrtRSInfo c_emlrtRSI{13, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo d_emlrtRSI{14, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo e_emlrtRSI{15, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo f_emlrtRSI{64, "x_TB_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo g_emlrtRSI{155, "cat",
                              "/MATLAB/toolbox/eml/lib/matlab/elmat/cat.m"};

static emlrtRSInfo h_emlrtRSI{
    21, "eml_int_forloop_overflow_check",
    "/MATLAB/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"};

static emlrtRSInfo i_emlrtRSI{111, "w_TB_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo j_emlrtRSI{158, "y_TB_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo k_emlrtRSI{26, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo l_emlrtRSI{27, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo m_emlrtRSI{28, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo n_emlrtRSI{75, "x_TB_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo o_emlrtRSI{
    13, "nullAssignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo p_emlrtRSI{
    17, "nullAssignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo q_emlrtRSI{
    168, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo r_emlrtRSI{
    170, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo s_emlrtRSI{
    173, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo t_emlrtRSI{
    193, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo u_emlrtRSI{
    266, "make_bitarray",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo v_emlrtRSI{
    133, "num_true",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo x_emlrtRSI{122, "w_TB_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRSInfo y_emlrtRSI{169, "y_TB_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtMCInfo b_emlrtMCI{19, 20, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtMCInfo c_emlrtMCI{19, 13, "matrx_mul_fixpt_logger",
                              "/MATLAB "
                              "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                              "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRTEInfo emlrtRTEI{93, 27, "cat",
                              "/MATLAB/toolbox/eml/lib/matlab/elmat/cat.m"};

static emlrtRTEInfo b_emlrtRTEI{
    11, 1, "eml_int_forloop_overflow_error",
    "/MATLAB/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_error.m"};

static emlrtRTEInfo c_emlrtRTEI{25, 9, "matrx_mul_fixpt_logger",
                                "/MATLAB "
                                "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                                "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRTEInfo d_emlrtRTEI{70, 9, "x_TB_logger",
                                "/MATLAB "
                                "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                                "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRTEInfo e_emlrtRTEI{
    86, 27, "validate_inputs",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRTEInfo f_emlrtRTEI{
    182, 9, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRTEInfo g_emlrtRTEI{
    189, 9, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRTEInfo h_emlrtRTEI{
    192, 9, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRTEInfo j_emlrtRTEI{117, 9, "w_TB_logger",
                                "/MATLAB "
                                "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                                "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRTEInfo k_emlrtRTEI{164, 9, "y_TB_logger",
                                "/MATLAB "
                                "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                                "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static const int32_T iv[4]{0, 1, 2, 3};

static emlrtRSInfo ab_emlrtRSI{19, "matrx_mul_fixpt_logger",
                               "/MATLAB "
                               "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                               "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRTEInfo l_emlrtRTEI{32, 16, "matrx_mul_fixpt_logger",
                                "/MATLAB "
                                "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                                "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRTEInfo m_emlrtRTEI{79, 16, "matrx_mul_fixpt_logger",
                                "/MATLAB "
                                "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                                "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static emlrtRTEInfo n_emlrtRTEI{126, 16, "matrx_mul_fixpt_logger",
                                "/MATLAB "
                                "Drive/Matrix_Multiplication/vitis/matrx_mul/"
                                "fixpt/fxptmp/matrx_mul_fixpt_logger.m"};

static const mxArray *MException(const emlrtStack &sp, const mxArray *m,
                                 const mxArray *m1, emlrtMCInfo &location);

static void b_throw(const emlrtStack &sp, const mxArray *m,
                    emlrtMCInfo &location);

namespace coder {
static void w_TB_logger(const emlrtStack &sp, array<uint16_T, 3U> &out);

static void w_TB_logger(const emlrtStack &sp, const uint16_T v[16]);

static void x_TB_logger(const emlrtStack &sp, array<int16_T, 3U> &out);

static void x_TB_logger(const emlrtStack &sp, const int16_T v[16]);

static void y_TB_logger(const emlrtStack &sp, array<int16_T, 3U> &out);

static void y_TB_logger(const emlrtStack &sp, const int16_T v[16]);

} // namespace coder

static const mxArray *MException(const emlrtStack &sp, const mxArray *m,
                                 const mxArray *m1, emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  const mxArray *m2;
  pArrays[0] = m;
  pArrays[1] = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m2, 2, &pArrays[0],
                               "MException", true, &location);
}

static void b_throw(const emlrtStack &sp, const mxArray *m,
                    emlrtMCInfo &location)
{
  emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 0, nullptr, 1, &m, "throw", true,
                        &location);
}

namespace coder {
static void w_TB_logger(const emlrtStack &sp, const uint16_T v[16])
{
  array<uint16_T, 3U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ysize[3];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (!b_p_not_empty) {
    b_p.set_size(&m_emlrtRTEI, &sp, 4, 4, 1);
    for (int32_T j{0}; j < 16; j++) {
      b_p[j] = v[j];
    }
    b_p_not_empty = true;
  } else {
    int32_T b_tmp;
    int32_T iy;
    boolean_T exitg1;
    st.site = &i_emlrtRSI;
    ysize[2] = b_p.size(2) + 1;
    ysize[0] = b_p.size(0);
    ysize[1] = b_p.size(1);
    iy = 0;
    exitg1 = false;
    while (!exitg1 && (iy < 3)) {
      if ((iy + 1 != 3) && (ysize[iy] != b_p.size(iy))) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    iy = 0;
    exitg1 = false;
    while (!exitg1 && (iy < 2)) {
      if (ysize[iy] != 4) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    y.set_size(&m_emlrtRTEI, &st, b_p.size(0), b_p.size(1), b_p.size(2) + 1);
    b_tmp = b_p.size(0) * b_p.size(1);
    iy = b_tmp * b_p.size(2);
    b_st.site = &g_emlrtRSI;
    if (iy > 2147483646) {
      c_st.site = &h_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &c_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
          "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
    }
    if (iy - 1 >= 0) {
      std::copy(&b_p[0], &b_p[iy], &y[0]);
    }
    if (iy - 1 < 0) {
      iy = -1;
    } else {
      iy--;
    }
    for (int32_T j{0}; j < 16; j++) {
      y[(iy + j) + 1] = v[j];
    }
    b_p.set_size(&m_emlrtRTEI, &sp, b_p.size(0), b_p.size(1), b_p.size(2) + 1);
    iy = b_tmp * y.size(2);
    if (iy - 1 >= 0) {
      std::copy(&y[0], &y[iy], &b_p[0]);
    }
    b_p_not_empty = ((b_p.size(0) != 0) && (b_p.size(1) != 0));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void w_TB_logger(const emlrtStack &sp, array<uint16_T, 3U> &out)
{
  array<int32_T, 1U> idx;
  array<uint16_T, 2U> d_p;
  array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxout;
  uint16_T tmp_data[4];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (!b_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&sp, &j_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  out.set_size(&m_emlrtRTEI, &sp, b_p.size(0), b_p.size(1), b_p.size(2));
  loop_ub = b_p.size(0) * b_p.size(1) * b_p.size(2);
  for (int32_T k{0}; k < loop_ub; k++) {
    out[k] = b_p[k];
  }
  st.site = &x_emlrtRSI;
  idx.set_size(&m_emlrtRTEI, &st, loop_ub);
  k0 = (loop_ub / 4) << 2;
  nxout = k0 - 4;
  for (int32_T k{0}; k <= nxout; k += 4) {
    _mm_storeu_si128(
        (__m128i *)&idx[k],
        _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                    _mm_loadu_si128((const __m128i *)&iv[0])),
                      _mm_set1_epi32(1)));
  }
  for (int32_T k{k0}; k < loop_ub; k++) {
    idx[k] = k + 1;
  }
  b_st.site = &o_emlrtRSI;
  b_p_not_empty = true;
  k0 = 0;
  while (k0 <= idx.size(0) - 1) {
    if (idx[k0] > loop_ub) {
      b_p_not_empty = false;
      break;
    } else {
      k0++;
    }
  }
  if (!b_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  b.set_size(&m_emlrtRTEI, &c_st, 1, loop_ub);
  if (loop_ub - 1 >= 0) {
    std::memset(&b[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(boolean_T));
  }
  k0 = idx.size(0);
  d_st.site = &u_emlrtRSI;
  if (idx.size(0) > 2147483646) {
    e_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < k0; k++) {
    b[idx[k] - 1] = true;
  }
  c_st.site = &r_emlrtRSI;
  k0 = 0;
  d_st.site = &v_emlrtRSI;
  if (b.size(1) > 2147483646) {
    e_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    k0 += b[k];
  }
  nxout = loop_ub - k0;
  k0 = -1;
  c_st.site = &s_emlrtRSI;
  if (loop_ub > 2147483646) {
    d_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &d_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    if ((k + 1 > b.size(1)) || !b[k]) {
      k0++;
      b_p[k0] = b_p[k];
    }
  }
  if ((b_p.size(0) != 1) && (b_p.size(1) == 1) && (b_p.size(2) == 1)) {
    if (nxout > b_p.size(0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    if (nxout - 1 >= 0) {
      std::copy(&b_p[0], &b_p[nxout], &tmp_data[0]);
    }
    d_p.set_size(&m_emlrtRTEI, &b_st, nxout, 1);
    if (nxout - 1 >= 0) {
      std::copy(&tmp_data[0], &tmp_data[nxout], &d_p[0]);
    }
  } else if (b_p.size(0) == 1) {
    int32_T b_iv[2];
    if (nxout > loop_ub) {
      emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    b_iv[0] = b_p.size(0);
    d_p.set_size(&m_emlrtRTEI, &b_st, 1, nxout);
    for (int32_T k{0}; k < nxout; k++) {
      d_p[d_p.size(0) * k] = b_p[b_iv[0] * k];
    }
  } else {
    int32_T b_iv[2];
    if (nxout > loop_ub) {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    b_iv[1] = nxout;
    c_st.site = &t_emlrtRSI;
    internal::indexShapeCheck(c_st, b_p.size(), b_iv);
    d_p.set_size(&m_emlrtRTEI, &b_st, 1, nxout);
    for (int32_T k{0}; k < nxout; k++) {
      d_p[d_p.size(0) * k] = b_p[k];
    }
  }
  b_p.set_size(&m_emlrtRTEI, &sp, d_p.size(0), d_p.size(1), 1);
  k0 = d_p.size(0) * d_p.size(1);
  if (k0 - 1 >= 0) {
    std::copy(&d_p[0], &d_p[k0], &b_p[0]);
  }
  b_p_not_empty = ((b_p.size(0) != 0) && (b_p.size(1) != 0));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void x_TB_logger(const emlrtStack &sp, const int16_T v[16])
{
  array<int16_T, 3U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ysize[3];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (!p_not_empty) {
    p.set_size(&l_emlrtRTEI, &sp, 4, 4, 1);
    for (int32_T j{0}; j < 16; j++) {
      p[j] = v[j];
    }
    p_not_empty = true;
  } else {
    int32_T b_tmp;
    int32_T iy;
    boolean_T exitg1;
    st.site = &f_emlrtRSI;
    ysize[2] = p.size(2) + 1;
    ysize[0] = p.size(0);
    ysize[1] = p.size(1);
    iy = 0;
    exitg1 = false;
    while (!exitg1 && (iy < 3)) {
      if ((iy + 1 != 3) && (ysize[iy] != p.size(iy))) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    iy = 0;
    exitg1 = false;
    while (!exitg1 && (iy < 2)) {
      if (ysize[iy] != 4) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    y.set_size(&l_emlrtRTEI, &st, p.size(0), p.size(1), p.size(2) + 1);
    b_tmp = p.size(0) * p.size(1);
    iy = b_tmp * p.size(2);
    b_st.site = &g_emlrtRSI;
    if (iy > 2147483646) {
      c_st.site = &h_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &c_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
          "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
    }
    if (iy - 1 >= 0) {
      std::copy(&p[0], &p[iy], &y[0]);
    }
    if (iy - 1 < 0) {
      iy = -1;
    } else {
      iy--;
    }
    for (int32_T j{0}; j < 16; j++) {
      y[(iy + j) + 1] = v[j];
    }
    p.set_size(&l_emlrtRTEI, &sp, p.size(0), p.size(1), p.size(2) + 1);
    iy = b_tmp * y.size(2);
    if (iy - 1 >= 0) {
      std::copy(&y[0], &y[iy], &p[0]);
    }
    p_not_empty = ((p.size(0) != 0) && (p.size(1) != 0));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void x_TB_logger(const emlrtStack &sp, array<int16_T, 3U> &out)
{
  array<int32_T, 1U> idx;
  array<int16_T, 2U> d_p;
  array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxout;
  int16_T tmp_data[4];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (!p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&sp, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  out.set_size(&l_emlrtRTEI, &sp, p.size(0), p.size(1), p.size(2));
  loop_ub = p.size(0) * p.size(1) * p.size(2);
  for (int32_T k{0}; k < loop_ub; k++) {
    out[k] = p[k];
  }
  st.site = &n_emlrtRSI;
  idx.set_size(&l_emlrtRTEI, &st, loop_ub);
  k0 = (loop_ub / 4) << 2;
  nxout = k0 - 4;
  for (int32_T k{0}; k <= nxout; k += 4) {
    _mm_storeu_si128(
        (__m128i *)&idx[k],
        _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                    _mm_loadu_si128((const __m128i *)&iv[0])),
                      _mm_set1_epi32(1)));
  }
  for (int32_T k{k0}; k < loop_ub; k++) {
    idx[k] = k + 1;
  }
  b_st.site = &o_emlrtRSI;
  p_not_empty = true;
  k0 = 0;
  while (k0 <= idx.size(0) - 1) {
    if (idx[k0] > loop_ub) {
      p_not_empty = false;
      break;
    } else {
      k0++;
    }
  }
  if (!p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  b.set_size(&l_emlrtRTEI, &c_st, 1, loop_ub);
  if (loop_ub - 1 >= 0) {
    std::memset(&b[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(boolean_T));
  }
  k0 = idx.size(0);
  d_st.site = &u_emlrtRSI;
  if (idx.size(0) > 2147483646) {
    e_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < k0; k++) {
    b[idx[k] - 1] = true;
  }
  c_st.site = &r_emlrtRSI;
  k0 = 0;
  d_st.site = &v_emlrtRSI;
  if (b.size(1) > 2147483646) {
    e_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    k0 += b[k];
  }
  nxout = loop_ub - k0;
  k0 = -1;
  c_st.site = &s_emlrtRSI;
  if (loop_ub > 2147483646) {
    d_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &d_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    if ((k + 1 > b.size(1)) || !b[k]) {
      k0++;
      p[k0] = p[k];
    }
  }
  if ((p.size(0) != 1) && (p.size(1) == 1) && (p.size(2) == 1)) {
    if (nxout > p.size(0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    if (nxout - 1 >= 0) {
      std::copy(&p[0], &p[nxout], &tmp_data[0]);
    }
    d_p.set_size(&l_emlrtRTEI, &b_st, nxout, 1);
    if (nxout - 1 >= 0) {
      std::copy(&tmp_data[0], &tmp_data[nxout], &d_p[0]);
    }
  } else if (p.size(0) == 1) {
    int32_T b_iv[2];
    if (nxout > loop_ub) {
      emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    b_iv[0] = p.size(0);
    d_p.set_size(&l_emlrtRTEI, &b_st, 1, nxout);
    for (int32_T k{0}; k < nxout; k++) {
      d_p[d_p.size(0) * k] = p[b_iv[0] * k];
    }
  } else {
    int32_T b_iv[2];
    if (nxout > loop_ub) {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    b_iv[1] = nxout;
    c_st.site = &t_emlrtRSI;
    internal::indexShapeCheck(c_st, p.size(), b_iv);
    d_p.set_size(&l_emlrtRTEI, &b_st, 1, nxout);
    for (int32_T k{0}; k < nxout; k++) {
      d_p[d_p.size(0) * k] = p[k];
    }
  }
  p.set_size(&l_emlrtRTEI, &sp, d_p.size(0), d_p.size(1), 1);
  k0 = d_p.size(0) * d_p.size(1);
  if (k0 - 1 >= 0) {
    std::copy(&d_p[0], &d_p[k0], &p[0]);
  }
  p_not_empty = ((p.size(0) != 0) && (p.size(1) != 0));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void y_TB_logger(const emlrtStack &sp, const int16_T v[16])
{
  array<int16_T, 3U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ysize[3];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (!c_p_not_empty) {
    c_p.set_size(&n_emlrtRTEI, &sp, 4, 4, 1);
    for (int32_T j{0}; j < 16; j++) {
      c_p[j] = v[j];
    }
    c_p_not_empty = true;
  } else {
    int32_T b_tmp;
    int32_T iy;
    boolean_T exitg1;
    st.site = &j_emlrtRSI;
    ysize[2] = c_p.size(2) + 1;
    ysize[0] = c_p.size(0);
    ysize[1] = c_p.size(1);
    iy = 0;
    exitg1 = false;
    while (!exitg1 && (iy < 3)) {
      if ((iy + 1 != 3) && (ysize[iy] != c_p.size(iy))) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    iy = 0;
    exitg1 = false;
    while (!exitg1 && (iy < 2)) {
      if (ysize[iy] != 4) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    y.set_size(&n_emlrtRTEI, &st, c_p.size(0), c_p.size(1), c_p.size(2) + 1);
    b_tmp = c_p.size(0) * c_p.size(1);
    iy = b_tmp * c_p.size(2);
    b_st.site = &g_emlrtRSI;
    if (iy > 2147483646) {
      c_st.site = &h_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &c_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
          "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
    }
    if (iy - 1 >= 0) {
      std::copy(&c_p[0], &c_p[iy], &y[0]);
    }
    if (iy - 1 < 0) {
      iy = -1;
    } else {
      iy--;
    }
    for (int32_T j{0}; j < 16; j++) {
      y[(iy + j) + 1] = v[j];
    }
    c_p.set_size(&n_emlrtRTEI, &sp, c_p.size(0), c_p.size(1), c_p.size(2) + 1);
    iy = b_tmp * y.size(2);
    if (iy - 1 >= 0) {
      std::copy(&y[0], &y[iy], &c_p[0]);
    }
    c_p_not_empty = ((c_p.size(0) != 0) && (c_p.size(1) != 0));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void y_TB_logger(const emlrtStack &sp, array<int16_T, 3U> &out)
{
  array<int32_T, 1U> idx;
  array<int16_T, 2U> d_p;
  array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxout;
  int16_T tmp_data[4];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (!c_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&sp, &k_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  out.set_size(&n_emlrtRTEI, &sp, c_p.size(0), c_p.size(1), c_p.size(2));
  loop_ub = c_p.size(0) * c_p.size(1) * c_p.size(2);
  for (int32_T k{0}; k < loop_ub; k++) {
    out[k] = c_p[k];
  }
  st.site = &y_emlrtRSI;
  idx.set_size(&n_emlrtRTEI, &st, loop_ub);
  k0 = (loop_ub / 4) << 2;
  nxout = k0 - 4;
  for (int32_T k{0}; k <= nxout; k += 4) {
    _mm_storeu_si128(
        (__m128i *)&idx[k],
        _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                    _mm_loadu_si128((const __m128i *)&iv[0])),
                      _mm_set1_epi32(1)));
  }
  for (int32_T k{k0}; k < loop_ub; k++) {
    idx[k] = k + 1;
  }
  b_st.site = &o_emlrtRSI;
  c_p_not_empty = true;
  k0 = 0;
  while (k0 <= idx.size(0) - 1) {
    if (idx[k0] > loop_ub) {
      c_p_not_empty = false;
      break;
    } else {
      k0++;
    }
  }
  if (!c_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  b_st.site = &p_emlrtRSI;
  c_st.site = &q_emlrtRSI;
  b.set_size(&n_emlrtRTEI, &c_st, 1, loop_ub);
  if (loop_ub - 1 >= 0) {
    std::memset(&b[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(boolean_T));
  }
  k0 = idx.size(0);
  d_st.site = &u_emlrtRSI;
  if (idx.size(0) > 2147483646) {
    e_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < k0; k++) {
    b[idx[k] - 1] = true;
  }
  c_st.site = &r_emlrtRSI;
  k0 = 0;
  d_st.site = &v_emlrtRSI;
  if (b.size(1) > 2147483646) {
    e_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    k0 += b[k];
  }
  nxout = loop_ub - k0;
  k0 = -1;
  c_st.site = &s_emlrtRSI;
  if (loop_ub > 2147483646) {
    d_st.site = &h_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &d_st, &b_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    if ((k + 1 > b.size(1)) || !b[k]) {
      k0++;
      c_p[k0] = c_p[k];
    }
  }
  if ((c_p.size(0) != 1) && (c_p.size(1) == 1) && (c_p.size(2) == 1)) {
    if (nxout > c_p.size(0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    if (nxout - 1 >= 0) {
      std::copy(&c_p[0], &c_p[nxout], &tmp_data[0]);
    }
    d_p.set_size(&n_emlrtRTEI, &b_st, nxout, 1);
    if (nxout - 1 >= 0) {
      std::copy(&tmp_data[0], &tmp_data[nxout], &d_p[0]);
    }
  } else if (c_p.size(0) == 1) {
    int32_T b_iv[2];
    if (nxout > loop_ub) {
      emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    b_iv[0] = c_p.size(0);
    d_p.set_size(&n_emlrtRTEI, &b_st, 1, nxout);
    for (int32_T k{0}; k < nxout; k++) {
      d_p[d_p.size(0) * k] = c_p[b_iv[0] * k];
    }
  } else {
    int32_T b_iv[2];
    if (nxout > loop_ub) {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nxout < 1) {
      nxout = 0;
    }
    b_iv[1] = nxout;
    c_st.site = &t_emlrtRSI;
    internal::indexShapeCheck(c_st, c_p.size(), b_iv);
    d_p.set_size(&n_emlrtRTEI, &b_st, 1, nxout);
    for (int32_T k{0}; k < nxout; k++) {
      d_p[d_p.size(0) * k] = c_p[k];
    }
  }
  c_p.set_size(&n_emlrtRTEI, &sp, d_p.size(0), d_p.size(1), 1);
  k0 = d_p.size(0) * d_p.size(1);
  if (k0 - 1 >= 0) {
    std::copy(&d_p[0], &d_p[k0], &c_p[0]);
  }
  c_p_not_empty = ((c_p.size(0) != 0) && (c_p.size(1) != 0));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void b_matrx_mul_fixpt_logger(const emlrtStack &sp,
                              const int16_T varargin_1[16],
                              const uint16_T varargin_2[16],
                              const int16_T varargin_3[16])
{
  static const int32_T b_iv[2]{1, 30};
  static const int32_T iv1[2]{1, 34};
  static const char_T b_u[34]{'R', 'e', 't', 'u', 'r', 'n', ' ', 'e', 'a',
                              'r', 'l', 'y', ' ', 'f', 'o', 'r', ' ', 'i',
                              'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p',
                              'u', 't', 'a', 't', 'i', 'o', 'n'};
  static const char_T u[30]{'C', 'o', 'd', 'e', 'r', ':', 'F', 'X', 'P', 'C',
                            'O', 'N', 'V', ':', 'M', 'A', 'T', 'L', 'A', 'B',
                            'S', 'i', 'm', 'B', 'a', 'i', 'l', 'O', 'u', 't'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &c_emlrtRSI;
  x_TB_logger(st, varargin_1);
  st.site = &d_emlrtRSI;
  w_TB_logger(st, varargin_2);
  st.site = &e_emlrtRSI;
  y_TB_logger(st, varargin_3);
  iterCount++;
  if (iterCount >= rtInf) {
    y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 30, m, &u[0]);
    emlrtAssign(&y, m);
    b_y = nullptr;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 34, m, &b_u[0]);
    emlrtAssign(&b_y, m);
    st.site = &ab_emlrtRSI;
    b_throw(st, MException(st, y, b_y, b_emlrtMCI), c_emlrtMCI);
  }
}

void matrx_mul_fixpt_logger(const emlrtStack *sp, struct0_T *loggedData)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!iterCount_not_empty) {
    emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  st.site = &k_emlrtRSI;
  x_TB_logger(st, loggedData->inputs.x);
  st.site = &l_emlrtRSI;
  w_TB_logger(st, loggedData->inputs.w);
  st.site = &m_emlrtRSI;
  y_TB_logger(st, loggedData->outputs.y);
  loggedData->iterCount = iterCount;
}

} // namespace coder
void matrx_mul_fixpt_logger_init()
{
  iterCount = 0.0;
  iterCount_not_empty = true;
}

void w_TB_logger_emx_free()
{
}

void w_TB_logger_emx_init()
{
}

void w_TB_logger_init()
{
  b_p_not_empty = false;
}

void x_TB_logger_emx_free()
{
}

void x_TB_logger_emx_init()
{
}

void x_TB_logger_init()
{
  p_not_empty = false;
}

void y_TB_logger_emx_free()
{
}

void y_TB_logger_emx_init()
{
}

void y_TB_logger_init()
{
  c_p_not_empty = false;
}
