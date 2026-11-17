#include "_coder_calc_rice_k_wrapper_fixpt_hdl_mex_api.h"
#include "calc_rice_k_fixpt_logger.h"
#include "calc_rice_k_wrapper_fixpt.h"
#include "calc_rice_k_wrapper_fixpt_hdl_mex_data.h"
#include "calc_rice_k_wrapper_fixpt_hdl_mex_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

static boolean_T b_emlrt_marshallIn(const emlrtStack &sp,
                                    const mxArray *b_nullptr,
                                    const char_T *identifier);

static boolean_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static boolean_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u);

static const mxArray *emlrt_marshallOut(const real_T u);

static boolean_T b_emlrt_marshallIn(const emlrtStack &sp,
                                    const mxArray *b_nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static boolean_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
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

static boolean_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "logical", false, 0U,
                          (const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
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
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u)
{
  static const char_T *sv[3]{"inputs", "outputs", "iterCount"};
  static const char_T *sv1[2]{"u_in", "reset"};
  static const char_T *s{"k_out"};
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
  uint8_T *b_pData;
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
  b_iv[0] = 1;
  b_iv[1] = u.inputs.reset.size(1);
  m = emlrtCreateLogicalArray(2, &b_iv[0]);
  emlrtInitLogicalArray(u.inputs.reset.size(1), m, &u.inputs.reset[0]);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(b_y, 0, "reset", e_y, 1);
  emlrtSetFieldR2017b(y, 0, "inputs", b_y, 0);
  f_y = nullptr;
  emlrtAssign(&f_y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  g_y = nullptr;
  h_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.outputs.k_out.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxUINT8_CLASS, mxREAL);
  b_pData = static_cast<uint8_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.outputs.k_out.size(1); b_i++) {
    b_pData[i] = u.outputs.k_out[b_i];
    i++;
  }
  emlrtAssign(&h_y, m);
  emlrtAssign(&g_y, emlrtCreateFIR2013b((emlrtCTX)&sp, eml_mx, c_eml_mx,
                                        "simulinkarray", h_y, true, false));
  emlrtSetFieldR2017b(f_y, 0, "k_out", g_y, 0);
  emlrtSetFieldR2017b(y, 0, "outputs", f_y, 1);
  emlrtSetFieldR2017b(y, 0, "iterCount", emlrt_marshallOut(u.iterCount), 2);
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

void calc_rice_k_fixpt_logger_api(const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  struct0_T loggedData;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  coder::calc_rice_k_fixpt_logger(&st, &loggedData);

  *plhs = emlrt_marshallOut(st, loggedData);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void calc_rice_k_wrapper_fixpt_api(const mxArray *const prhs[2],
                                   const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  real_T u_in;
  boolean_T reset;
  st.tls = emlrtRootTLSGlobal;

  u_in = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "u_in");
  reset = b_emlrt_marshallIn(st, emlrtAliasP(prhs[1]), "reset");

  u_in = calc_rice_k_wrapper_fixpt(&st, u_in, reset);

  *plhs = emlrt_marshallOut(u_in);
}
