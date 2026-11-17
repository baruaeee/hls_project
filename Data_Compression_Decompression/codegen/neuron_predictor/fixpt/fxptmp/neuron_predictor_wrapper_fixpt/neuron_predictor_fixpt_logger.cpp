#include "neuron_predictor_fixpt_logger.h"
#include "neuron_predictor_wrapper_fixpt_hdl_mex_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>
#include <emmintrin.h>

static real_T iterCount;

static boolean_T iterCount_not_empty;

static coder::array<int16_T, 2U> p;

static boolean_T p_not_empty;

static coder::array<boolean_T, 2U> b_p;

static boolean_T b_p_not_empty;

static coder::array<int16_T, 2U> c_p;

static boolean_T c_p_not_empty;

static coder::array<int16_T, 2U> d_p;

static boolean_T d_p_not_empty;

static emlrtRSInfo c_emlrtRSI{
    13, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo d_emlrtRSI{
    14, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo e_emlrtRSI{
    15, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo f_emlrtRSI{
    16, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo g_emlrtRSI{
    27, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo h_emlrtRSI{
    28, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo i_emlrtRSI{
    29, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo j_emlrtRSI{
    30, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo k_emlrtRSI{
    77, "x_in_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo l_emlrtRSI{
    13, "nullAssignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo m_emlrtRSI{
    17, "nullAssignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo n_emlrtRSI{
    168, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo o_emlrtRSI{
    170, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo p_emlrtRSI{
    173, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo q_emlrtRSI{
    266, "make_bitarray",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo r_emlrtRSI{
    21, "eml_int_forloop_overflow_check",
    "/MATLAB/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"};

static emlrtRSInfo s_emlrtRSI{
    133, "num_true",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRSInfo t_emlrtRSI{
    124, "reset_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo u_emlrtRSI{
    171, "residual_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRSInfo v_emlrtRSI{
    218, "predicted_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtMCInfo b_emlrtMCI{
    20, 20, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtMCInfo c_emlrtMCI{
    20, 13, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo emlrtRTEI{
    26, 9, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo b_emlrtRTEI{
    72, 9, "x_in_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo c_emlrtRTEI{
    86, 27, "validate_inputs",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRTEInfo d_emlrtRTEI{
    189, 9, "onearg_null_assignment",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/nullAssignment.m"};

static emlrtRTEInfo e_emlrtRTEI{
    11, 1, "eml_int_forloop_overflow_error",
    "/MATLAB/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_error.m"};

static emlrtRTEInfo f_emlrtRTEI{
    119, 9, "reset_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo g_emlrtRTEI{
    166, 9, "residual_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo h_emlrtRTEI{
    213, 9, "predicted_TB_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static const int32_T iv[4]{0, 1, 2, 3};

static emlrtRSInfo w_emlrtRSI{
    20, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo i_emlrtRTEI{
    34, 16, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo j_emlrtRTEI{
    81, 16, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo k_emlrtRTEI{
    128, 16, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static emlrtRTEInfo l_emlrtRTEI{
    175, 16, "neuron_predictor_fixpt_logger",
    "/MATLAB "
    "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/fixpt/fxptmp/"
    "neuron_predictor_fixpt_logger.m"};

static const mxArray *MException(const emlrtStack &sp, const mxArray *m,
                                 const mxArray *m1, emlrtMCInfo &location);

static void b_throw(const emlrtStack &sp, const mxArray *m,
                    emlrtMCInfo &location);

namespace coder {
static void b_reset_TB_logger(const emlrtStack &sp, array<boolean_T, 2U> &out);

static void predicted_TB_logger(const emlrtStack &sp, array<int16_T, 2U> &out);

static void predicted_TB_logger(const emlrtStack &sp, int16_T v);

static void reset_TB_logger(const emlrtStack &sp, boolean_T v);

static void residual_TB_logger(const emlrtStack &sp, array<int16_T, 2U> &out);

static void residual_TB_logger(const emlrtStack &sp, int16_T v);

static void x_in_TB_logger(const emlrtStack &sp, array<int16_T, 2U> &out);

static void x_in_TB_logger(const emlrtStack &sp, int16_T v);

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
static void b_reset_TB_logger(const emlrtStack &sp, array<boolean_T, 2U> &out)
{
  array<int32_T, 1U> idx;
  array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxout;
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
    emlrtErrorWithMessageIdR2018a(&sp, &f_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  loop_ub = b_p.size(1);
  out.set_size(&j_emlrtRTEI, &sp, 1, b_p.size(1));
  for (int32_T k{0}; k < loop_ub; k++) {
    out[k] = b_p[k];
  }
  st.site = &t_emlrtRSI;
  idx.set_size(&j_emlrtRTEI, &st, b_p.size(1));
  nxout = (b_p.size(1) / 4) << 2;
  k0 = nxout - 4;
  for (int32_T k{0}; k <= k0; k += 4) {
    _mm_storeu_si128(
        (__m128i *)&idx[k],
        _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                    _mm_loadu_si128((const __m128i *)&iv[0])),
                      _mm_set1_epi32(1)));
  }
  for (int32_T k{nxout}; k < loop_ub; k++) {
    idx[k] = k + 1;
  }
  b_st.site = &l_emlrtRSI;
  b_p_not_empty = true;
  nxout = 0;
  while (nxout <= b_p.size(1) - 1) {
    if (idx[nxout] > b_p.size(1)) {
      b_p_not_empty = false;
      break;
    } else {
      nxout++;
    }
  }
  if (!b_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b.set_size(&j_emlrtRTEI, &c_st, 1, b_p.size(1));
  if (loop_ub - 1 >= 0) {
    std::memset(&b[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(boolean_T));
  }
  d_st.site = &q_emlrtRSI;
  if (b_p.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    b[idx[k] - 1] = true;
  }
  c_st.site = &o_emlrtRSI;
  nxout = 0;
  d_st.site = &s_emlrtRSI;
  if (b.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    nxout += b[k];
  }
  nxout = b_p.size(1) - nxout;
  k0 = -1;
  c_st.site = &p_emlrtRSI;
  if (b_p.size(1) > 2147483646) {
    d_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    if ((k + 1 > b.size(1)) || !b[k]) {
      k0++;
      b_p[k0] = b_p[k];
    }
  }
  if (nxout > b_p.size(1)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nxout < 1) {
    nxout = 0;
  }
  b_p.set_size(&j_emlrtRTEI, &b_st, b_p.size(0), nxout);
  b_p_not_empty = (b_p.size(1) != 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void predicted_TB_logger(const emlrtStack &sp, int16_T v)
{
  if (!d_p_not_empty) {
    d_p.set_size(&l_emlrtRTEI, &sp, 1, 1);
    d_p[0] = v;
    d_p_not_empty = true;
  } else {
    int32_T i;
    i = d_p.size(1);
    d_p.set_size(&l_emlrtRTEI, &sp, d_p.size(0), d_p.size(1) + 1);
    d_p[i] = v;
  }
}

static void predicted_TB_logger(const emlrtStack &sp, array<int16_T, 2U> &out)
{
  array<int32_T, 1U> idx;
  array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxout;
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
  if (!d_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&sp, &h_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  loop_ub = d_p.size(1);
  out.set_size(&l_emlrtRTEI, &sp, 1, d_p.size(1));
  for (int32_T k{0}; k < loop_ub; k++) {
    out[k] = d_p[k];
  }
  st.site = &v_emlrtRSI;
  idx.set_size(&l_emlrtRTEI, &st, d_p.size(1));
  nxout = (d_p.size(1) / 4) << 2;
  k0 = nxout - 4;
  for (int32_T k{0}; k <= k0; k += 4) {
    _mm_storeu_si128(
        (__m128i *)&idx[k],
        _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                    _mm_loadu_si128((const __m128i *)&iv[0])),
                      _mm_set1_epi32(1)));
  }
  for (int32_T k{nxout}; k < loop_ub; k++) {
    idx[k] = k + 1;
  }
  b_st.site = &l_emlrtRSI;
  d_p_not_empty = true;
  nxout = 0;
  while (nxout <= d_p.size(1) - 1) {
    if (idx[nxout] > d_p.size(1)) {
      d_p_not_empty = false;
      break;
    } else {
      nxout++;
    }
  }
  if (!d_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b.set_size(&l_emlrtRTEI, &c_st, 1, d_p.size(1));
  if (loop_ub - 1 >= 0) {
    std::memset(&b[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(boolean_T));
  }
  d_st.site = &q_emlrtRSI;
  if (d_p.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    b[idx[k] - 1] = true;
  }
  c_st.site = &o_emlrtRSI;
  nxout = 0;
  d_st.site = &s_emlrtRSI;
  if (b.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    nxout += b[k];
  }
  nxout = d_p.size(1) - nxout;
  k0 = -1;
  c_st.site = &p_emlrtRSI;
  if (d_p.size(1) > 2147483646) {
    d_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    if ((k + 1 > b.size(1)) || !b[k]) {
      k0++;
      d_p[k0] = d_p[k];
    }
  }
  if (nxout > d_p.size(1)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nxout < 1) {
    nxout = 0;
  }
  d_p.set_size(&l_emlrtRTEI, &b_st, d_p.size(0), nxout);
  d_p_not_empty = (d_p.size(1) != 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void reset_TB_logger(const emlrtStack &sp, boolean_T v)
{
  if (!b_p_not_empty) {
    b_p.set_size(&j_emlrtRTEI, &sp, 1, 1);
    b_p[0] = v;
    b_p_not_empty = true;
  } else {
    int32_T i;
    i = b_p.size(1);
    b_p.set_size(&j_emlrtRTEI, &sp, b_p.size(0), b_p.size(1) + 1);
    b_p[i] = v;
  }
}

static void residual_TB_logger(const emlrtStack &sp, int16_T v)
{
  if (!c_p_not_empty) {
    c_p.set_size(&k_emlrtRTEI, &sp, 1, 1);
    c_p[0] = v;
    c_p_not_empty = true;
  } else {
    int32_T i;
    i = c_p.size(1);
    c_p.set_size(&k_emlrtRTEI, &sp, c_p.size(0), c_p.size(1) + 1);
    c_p[i] = v;
  }
}

static void residual_TB_logger(const emlrtStack &sp, array<int16_T, 2U> &out)
{
  array<int32_T, 1U> idx;
  array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxout;
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
    emlrtErrorWithMessageIdR2018a(&sp, &g_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  loop_ub = c_p.size(1);
  out.set_size(&k_emlrtRTEI, &sp, 1, c_p.size(1));
  for (int32_T k{0}; k < loop_ub; k++) {
    out[k] = c_p[k];
  }
  st.site = &u_emlrtRSI;
  idx.set_size(&k_emlrtRTEI, &st, c_p.size(1));
  nxout = (c_p.size(1) / 4) << 2;
  k0 = nxout - 4;
  for (int32_T k{0}; k <= k0; k += 4) {
    _mm_storeu_si128(
        (__m128i *)&idx[k],
        _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                    _mm_loadu_si128((const __m128i *)&iv[0])),
                      _mm_set1_epi32(1)));
  }
  for (int32_T k{nxout}; k < loop_ub; k++) {
    idx[k] = k + 1;
  }
  b_st.site = &l_emlrtRSI;
  c_p_not_empty = true;
  nxout = 0;
  while (nxout <= c_p.size(1) - 1) {
    if (idx[nxout] > c_p.size(1)) {
      c_p_not_empty = false;
      break;
    } else {
      nxout++;
    }
  }
  if (!c_p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b.set_size(&k_emlrtRTEI, &c_st, 1, c_p.size(1));
  if (loop_ub - 1 >= 0) {
    std::memset(&b[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(boolean_T));
  }
  d_st.site = &q_emlrtRSI;
  if (c_p.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    b[idx[k] - 1] = true;
  }
  c_st.site = &o_emlrtRSI;
  nxout = 0;
  d_st.site = &s_emlrtRSI;
  if (b.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    nxout += b[k];
  }
  nxout = c_p.size(1) - nxout;
  k0 = -1;
  c_st.site = &p_emlrtRSI;
  if (c_p.size(1) > 2147483646) {
    d_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    if ((k + 1 > b.size(1)) || !b[k]) {
      k0++;
      c_p[k0] = c_p[k];
    }
  }
  if (nxout > c_p.size(1)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nxout < 1) {
    nxout = 0;
  }
  c_p.set_size(&k_emlrtRTEI, &b_st, c_p.size(0), nxout);
  c_p_not_empty = (c_p.size(1) != 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void x_in_TB_logger(const emlrtStack &sp, int16_T v)
{
  if (!p_not_empty) {
    p.set_size(&i_emlrtRTEI, &sp, 1, 1);
    p[0] = v;
    p_not_empty = true;
  } else {
    int32_T i;
    i = p.size(1);
    p.set_size(&i_emlrtRTEI, &sp, p.size(0), p.size(1) + 1);
    p[i] = v;
  }
}

static void x_in_TB_logger(const emlrtStack &sp, array<int16_T, 2U> &out)
{
  array<int32_T, 1U> idx;
  array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxout;
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
    emlrtErrorWithMessageIdR2018a(&sp, &b_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  loop_ub = p.size(1);
  out.set_size(&i_emlrtRTEI, &sp, 1, p.size(1));
  for (int32_T k{0}; k < loop_ub; k++) {
    out[k] = p[k];
  }
  st.site = &k_emlrtRSI;
  idx.set_size(&i_emlrtRTEI, &st, p.size(1));
  nxout = (p.size(1) / 4) << 2;
  k0 = nxout - 4;
  for (int32_T k{0}; k <= k0; k += 4) {
    _mm_storeu_si128(
        (__m128i *)&idx[k],
        _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                    _mm_loadu_si128((const __m128i *)&iv[0])),
                      _mm_set1_epi32(1)));
  }
  for (int32_T k{nxout}; k < loop_ub; k++) {
    idx[k] = k + 1;
  }
  b_st.site = &l_emlrtRSI;
  p_not_empty = true;
  nxout = 0;
  while (nxout <= p.size(1) - 1) {
    if (idx[nxout] > p.size(1)) {
      p_not_empty = false;
      break;
    } else {
      nxout++;
    }
  }
  if (!p_not_empty) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b.set_size(&i_emlrtRTEI, &c_st, 1, p.size(1));
  if (loop_ub - 1 >= 0) {
    std::memset(&b[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(boolean_T));
  }
  d_st.site = &q_emlrtRSI;
  if (p.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    b[idx[k] - 1] = true;
  }
  c_st.site = &o_emlrtRSI;
  nxout = 0;
  d_st.site = &s_emlrtRSI;
  if (b.size(1) > 2147483646) {
    e_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    nxout += b[k];
  }
  nxout = p.size(1) - nxout;
  k0 = -1;
  c_st.site = &p_emlrtRSI;
  if (p.size(1) > 2147483646) {
    d_st.site = &r_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
        "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
  for (int32_T k{0}; k < loop_ub; k++) {
    if ((k + 1 > b.size(1)) || !b[k]) {
      k0++;
      p[k0] = p[k];
    }
  }
  if (nxout > p.size(1)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nxout < 1) {
    nxout = 0;
  }
  p.set_size(&i_emlrtRTEI, &b_st, p.size(0), nxout);
  p_not_empty = (p.size(1) != 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder
void c_neuron_predictor_fixpt_logger()
{
  iterCount = 0.0;
  iterCount_not_empty = true;
}

namespace coder {
void b_neuron_predictor_fixpt_logger(const emlrtStack &sp, int16_T varargin_1,
                                     boolean_T varargin_2, int16_T varargin_3,
                                     int16_T varargin_4)
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
  x_in_TB_logger(st, varargin_1);
  st.site = &d_emlrtRSI;
  reset_TB_logger(st, varargin_2);
  st.site = &e_emlrtRSI;
  residual_TB_logger(st, varargin_3);
  st.site = &f_emlrtRSI;
  predicted_TB_logger(st, varargin_4);
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
    st.site = &w_emlrtRSI;
    b_throw(st, MException(st, y, b_y, b_emlrtMCI), c_emlrtMCI);
  }
}

void neuron_predictor_fixpt_logger(const emlrtStack *sp, struct0_T *loggedData)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!iterCount_not_empty) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  st.site = &g_emlrtRSI;
  x_in_TB_logger(st, loggedData->inputs.x_in);
  st.site = &h_emlrtRSI;
  b_reset_TB_logger(st, loggedData->inputs.reset);
  st.site = &i_emlrtRSI;
  residual_TB_logger(st, loggedData->outputs.residual);
  st.site = &j_emlrtRSI;
  predicted_TB_logger(st, loggedData->outputs.predicted);
  loggedData->iterCount = iterCount;
}

} // namespace coder
void predicted_TB_logger_emx_free()
{
}

void predicted_TB_logger_emx_init()
{
}

void predicted_TB_logger_init()
{
  d_p_not_empty = false;
}

void reset_TB_logger_emx_free()
{
}

void reset_TB_logger_emx_init()
{
}

void reset_TB_logger_init()
{
  b_p_not_empty = false;
}

void residual_TB_logger_emx_free()
{
}

void residual_TB_logger_emx_init()
{
}

void residual_TB_logger_init()
{
  c_p_not_empty = false;
}

void x_in_TB_logger_emx_free()
{
}

void x_in_TB_logger_emx_init()
{
}

void x_in_TB_logger_init()
{
  p_not_empty = false;
}
