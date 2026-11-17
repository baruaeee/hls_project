#include "_coder_neuron_predictor_wrapper_fixpt_hdl_mex_api.h"
#include "neuron_predictor_fixpt_logger.h"
#include "neuron_predictor_wrapper_fixpt.h"
#include "neuron_predictor_wrapper_fixpt_hdl_mex_data.h"
#include "neuron_predictor_wrapper_fixpt_hdl_mex_types.h"
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

static const mxArray *emlrt_marshallOut(const coder::array<int16_T, 2U> &u);

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
  static const char_T *sv1[2]{"x_in", "reset"};
  static const char_T *sv2[2]{"residual", "predicted"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  int32_T b_iv[2];
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv[0]));
  b_y = nullptr;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv1[0]));
  c_y = nullptr;
  emlrtAssign(&c_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, b_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.inputs.x_in), true, false));
  emlrtSetFieldR2017b(b_y, 0, "x_in", c_y, 0);
  d_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u.inputs.reset.size(1);
  m = emlrtCreateLogicalArray(2, &b_iv[0]);
  emlrtInitLogicalArray(u.inputs.reset.size(1), m, &u.inputs.reset[0]);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(b_y, 0, "reset", d_y, 1);
  emlrtSetFieldR2017b(y, 0, "inputs", b_y, 0);
  e_y = nullptr;
  emlrtAssign(&e_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv2[0]));
  f_y = nullptr;
  emlrtAssign(&f_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, c_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.outputs.residual), true, false));
  emlrtSetFieldR2017b(e_y, 0, "residual", f_y, 0);
  g_y = nullptr;
  emlrtAssign(&g_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, d_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.outputs.predicted), true, false));
  emlrtSetFieldR2017b(e_y, 0, "predicted", g_y, 1);
  emlrtSetFieldR2017b(y, 0, "outputs", e_y, 1);
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

void d_neuron_predictor_fixpt_logger(const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  struct0_T loggedData;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  coder::neuron_predictor_fixpt_logger(&st, &loggedData);

  *plhs = emlrt_marshallOut(st, loggedData);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void d_neuron_predictor_wrapper_fixp(const mxArray *const prhs[2], int32_T nlhs,
                                     const mxArray *plhs[2])
{
  emlrtStack st{nullptr, nullptr, nullptr};
  real_T predicted;
  real_T residual;
  real_T x_in;
  boolean_T reset;
  st.tls = emlrtRootTLSGlobal;

  x_in = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "x_in");
  reset = b_emlrt_marshallIn(st, emlrtAliasP(prhs[1]), "reset");

  neuron_predictor_wrapper_fixpt(&st, x_in, reset, &residual, &predicted);

  plhs[0] = emlrt_marshallOut(residual);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(predicted);
  }
}
