#include "_coder_split_quotient_remainder_wrapper_fixpt_hdl_mex_api.h"
#include "rt_nonfinite.h"
#include "split_quotient_remainder_fixpt_logger.h"
#include "split_quotient_remainder_wrapper_fixpt.h"
#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_data.h"
#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_types.h"
#include "coder_array.h"

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u);

static const mxArray *emlrt_marshallOut(const coder::array<uint8_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u)
{
  static const char_T *sv[3]{"inputs", "outputs", "iterCount"};
  static const char_T *sv1[2]{"u_in", "k_in"};
  static const char_T *sv2[2]{"q_out", "r_out"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *y;
  int32_T b_iv[2];
  int32_T i;
  uint16_T *pData;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv[0]));
  b_y = nullptr;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv1[0]));
  c_y = nullptr;
  d_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.inputs.u_in.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxUINT16_CLASS, mxREAL);
  pData = static_cast<uint16_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.inputs.u_in.size(1); b_i++) {
    pData[i] = u.inputs.u_in[b_i];
    i++;
  }
  emlrtAssign(&d_y, m);
  emlrtAssign(&c_y, emlrtCreateFIR2013b((emlrtCTX)&sp, eml_mx, b_eml_mx,
                                        "simulinkarray", d_y, true, false));
  emlrtSetFieldR2017b(b_y, 0, "u_in", c_y, 0);
  e_y = nullptr;
  emlrtAssign(&e_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, c_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.inputs.k_in), true, false));
  emlrtSetFieldR2017b(b_y, 0, "k_in", e_y, 1);
  emlrtSetFieldR2017b(y, 0, "inputs", b_y, 0);
  f_y = nullptr;
  emlrtAssign(&f_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv2[0]));
  g_y = nullptr;
  emlrtAssign(&g_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, d_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.outputs.q_out), true, false));
  emlrtSetFieldR2017b(f_y, 0, "q_out", g_y, 0);
  h_y = nullptr;
  emlrtAssign(&h_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, e_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.outputs.r_out), true, false));
  emlrtSetFieldR2017b(f_y, 0, "r_out", h_y, 1);
  emlrtSetFieldR2017b(y, 0, "outputs", f_y, 1);
  emlrtSetFieldR2017b(y, 0, "iterCount", emlrt_marshallOut(u.iterCount), 2);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<uint8_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T b_iv[2];
  int32_T i;
  uint8_T *pData;
  y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxUINT8_CLASS, mxREAL);
  pData = static_cast<uint8_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.size(1); b_i++) {
    pData[i] = u[b_i];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void d_split_quotient_remainder_fixp(const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  struct0_T loggedData;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  coder::split_quotient_remainder_fixpt_logger(&st, &loggedData);

  *plhs = emlrt_marshallOut(st, loggedData);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void d_split_quotient_remainder_wrap(const mxArray *const prhs[2], int32_T nlhs,
                                     const mxArray *plhs[2])
{
  emlrtStack st{nullptr, nullptr, nullptr};
  real_T k_in;
  real_T q_out;
  real_T r_out;
  real_T u_in;
  st.tls = emlrtRootTLSGlobal;

  u_in = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "u_in");
  k_in = emlrt_marshallIn(st, emlrtAliasP(prhs[1]), "k_in");

  split_quotient_remainder_wrapper_fixpt(&st, u_in, k_in, &q_out, &r_out);

  plhs[0] = emlrt_marshallOut(q_out);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(r_out);
  }
}
