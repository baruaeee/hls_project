#include "_coder_signed_to_unsigned_wrapper_fixpt_hdl_mex_api.h"
#include "rt_nonfinite.h"
#include "signed_to_unsigned_fixpt_logger.h"
#include "signed_to_unsigned_wrapper_fixpt.h"
#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_data.h"
#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_types.h"
#include "coder_array.h"

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u);

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
  static const char_T *s{"e_in"};
  static const char_T *s1{"u_out"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  int32_T b_iv[2];
  int32_T i;
  int16_T *pData;
  uint16_T *b_pData;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv[0]));
  b_y = nullptr;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  c_y = nullptr;
  d_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.inputs.e_in.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxINT16_CLASS, mxREAL);
  pData = static_cast<int16_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.inputs.e_in.size(1); b_i++) {
    pData[i] = u.inputs.e_in[b_i];
    i++;
  }
  emlrtAssign(&d_y, m);
  emlrtAssign(&c_y, emlrtCreateFIR2013b((emlrtCTX)&sp, eml_mx, b_eml_mx,
                                        "simulinkarray", d_y, true, false));
  emlrtSetFieldR2017b(b_y, 0, "e_in", c_y, 0);
  emlrtSetFieldR2017b(y, 0, "inputs", b_y, 0);
  e_y = nullptr;
  emlrtAssign(&e_y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s1));
  f_y = nullptr;
  g_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.outputs.u_out.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxUINT16_CLASS, mxREAL);
  b_pData = static_cast<uint16_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.outputs.u_out.size(1); b_i++) {
    b_pData[i] = u.outputs.u_out[b_i];
    i++;
  }
  emlrtAssign(&g_y, m);
  emlrtAssign(&f_y, emlrtCreateFIR2013b((emlrtCTX)&sp, eml_mx, c_eml_mx,
                                        "simulinkarray", g_y, true, false));
  emlrtSetFieldR2017b(e_y, 0, "u_out", f_y, 0);
  emlrtSetFieldR2017b(y, 0, "outputs", e_y, 1);
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

void d_signed_to_unsigned_fixpt_logg(const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  struct0_T loggedData;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  coder::signed_to_unsigned_fixpt_logger(&st, &loggedData);

  *plhs = emlrt_marshallOut(st, loggedData);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void d_signed_to_unsigned_wrapper_fi(const mxArray *const prhs[1],
                                     const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  real_T e_in;
  st.tls = emlrtRootTLSGlobal;

  e_in = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "e_in");

  e_in = signed_to_unsigned_wrapper_fixpt(&st, e_in);

  *plhs = emlrt_marshallOut(e_in);
}
