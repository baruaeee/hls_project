#include "_coder_neuron_wrapper_fixpt_hdl_mex_api.h"
#include "neuron_fixpt_logger.h"
#include "neuron_wrapper_fixpt.h"
#include "neuron_wrapper_fixpt_hdl_mex_data.h"
#include "neuron_wrapper_fixpt_hdl_mex_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier);

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

static real_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[4];

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[4];

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u);

static const mxArray *emlrt_marshallOut(const coder::array<int16_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims[2]{1, 4};
  real_T(*ret)[4];
  int32_T b_iv[2];
  boolean_T bv[2]{false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
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

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u)
{
  static const char_T *sv[3]{"inputs", "outputs", "iterCount"};
  static const char_T *sv1[3]{"x", "w", "b"};
  static const char_T *s{"y"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *m;
  const mxArray *y;
  int32_T b_iv[2];
  int32_T i;
  uint16_T *pData;
  uint8_T *b_pData;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv[0]));
  b_y = nullptr;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv1[0]));
  c_y = nullptr;
  emlrtAssign(&c_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, b_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.inputs.x), true, false));
  emlrtSetFieldR2017b(b_y, 0, "x", c_y, 0);
  d_y = nullptr;
  e_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.inputs.w.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxUINT16_CLASS, mxREAL);
  pData = static_cast<uint16_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.inputs.w.size(1); b_i++) {
    pData[i] = u.inputs.w[b_i];
    i++;
  }
  emlrtAssign(&e_y, m);
  emlrtAssign(&d_y, emlrtCreateFIR2013b((emlrtCTX)&sp, eml_mx, c_eml_mx,
                                        "simulinkarray", e_y, true, false));
  emlrtSetFieldR2017b(b_y, 0, "w", d_y, 1);
  f_y = nullptr;
  g_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.inputs.b.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxUINT8_CLASS, mxREAL);
  b_pData = static_cast<uint8_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.inputs.b.size(1); b_i++) {
    b_pData[i] = u.inputs.b[b_i];
    i++;
  }
  emlrtAssign(&g_y, m);
  emlrtAssign(&f_y, emlrtCreateFIR2013b((emlrtCTX)&sp, eml_mx, d_eml_mx,
                                        "simulinkarray", g_y, true, false));
  emlrtSetFieldR2017b(b_y, 0, "b", f_y, 2);
  emlrtSetFieldR2017b(y, 0, "inputs", b_y, 0);
  h_y = nullptr;
  emlrtAssign(&h_y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  i_y = nullptr;
  emlrtAssign(&i_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, e_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.outputs.y), true, false));
  emlrtSetFieldR2017b(h_y, 0, "y", i_y, 0);
  emlrtSetFieldR2017b(y, 0, "outputs", h_y, 1);
  emlrtSetFieldR2017b(y, 0, "iterCount", emlrt_marshallOut(u.iterCount), 2);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<int16_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T b_iv[2];
  int32_T i;
  int16_T *pData;
  y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxINT16_CLASS, mxREAL);
  pData = static_cast<int16_T *>(emlrtMxGetData(m));
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

void neuron_fixpt_logger_api(const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  struct0_T loggedData;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  coder::neuron_fixpt_logger(&st, &loggedData);

  *plhs = emlrt_marshallOut(st, loggedData);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void neuron_wrapper_fixpt_api(const mxArray *const prhs[3],
                              const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  real_T(*w)[4];
  real_T(*x)[4];
  real_T b;
  st.tls = emlrtRootTLSGlobal;

  x = emlrt_marshallIn(st, emlrtAlias(prhs[0]), "x");
  w = emlrt_marshallIn(st, emlrtAlias(prhs[1]), "w");
  b = b_emlrt_marshallIn(st, emlrtAliasP(prhs[2]), "b");

  b = neuron_wrapper_fixpt(&st, *x, *w, b);

  *plhs = emlrt_marshallOut(b);
}
