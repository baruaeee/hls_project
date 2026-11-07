#include "_coder_matrx_mul_wrapper_fixpt_hdl_mex_api.h"
#include "matrx_mul_fixpt_logger.h"
#include "matrx_mul_wrapper_fixpt.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_data.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

static real_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16];

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[16];

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[16];

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u);

static const mxArray *emlrt_marshallOut(const coder::array<int16_T, 3U> &u);

static const mxArray *emlrt_marshallOut(real_T u[16]);

static real_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16]
{
  static const int32_T dims[2]{4, 4};
  real_T(*ret)[16];
  int32_T b_iv[2];
  boolean_T bv[2]{false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[16])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[16]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[16];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[16]
{
  real_T(*y)[16];
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const struct0_T &u)
{
  static const char_T *sv[3]{"inputs", "outputs", "iterCount"};
  static const char_T *sv1[2]{"x", "w"};
  static const char_T *s{"y"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  uint16_T *pData;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv[0]));
  b_y = nullptr;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv1[0]));
  c_y = nullptr;
  emlrtAssign(&c_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, b_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.inputs.x), true, false));
  emlrtSetFieldR2017b(b_y, 0, "x", c_y, 0);
  d_y = nullptr;
  e_y = nullptr;
  m = emlrtCreateNumericArray(
      3, (const_cast<coder::array<uint16_T, 3U> *>(&u.inputs.w))->size(),
      mxUINT16_CLASS, mxREAL);
  pData = static_cast<uint16_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.inputs.w.size(2); b_i++) {
    for (int32_T c_i{0}; c_i < u.inputs.w.size(1); c_i++) {
      for (int32_T d_i{0}; d_i < u.inputs.w.size(0); d_i++) {
        pData[i] = u.inputs.w[(d_i + u.inputs.w.size(0) * c_i) +
                              u.inputs.w.size(0) * u.inputs.w.size(1) * b_i];
        i++;
      }
    }
  }
  emlrtAssign(&e_y, m);
  emlrtAssign(&d_y, emlrtCreateFIR2013b((emlrtCTX)&sp, eml_mx, c_eml_mx,
                                        "simulinkarray", e_y, true, false));
  emlrtSetFieldR2017b(b_y, 0, "w", d_y, 1);
  emlrtSetFieldR2017b(y, 0, "inputs", b_y, 0);
  f_y = nullptr;
  emlrtAssign(&f_y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  g_y = nullptr;
  emlrtAssign(&g_y, emlrtCreateFIR2013b(
                        (emlrtCTX)&sp, eml_mx, d_eml_mx, "simulinkarray",
                        emlrt_marshallOut(u.outputs.y), true, false));
  emlrtSetFieldR2017b(f_y, 0, "y", g_y, 0);
  emlrtSetFieldR2017b(y, 0, "outputs", f_y, 1);
  h_y = nullptr;
  m = emlrtCreateDoubleScalar(u.iterCount);
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "iterCount", h_y, 2);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<int16_T, 3U> &u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  int16_T *pData;
  y = nullptr;
  m = emlrtCreateNumericArray(
      3, (const_cast<coder::array<int16_T, 3U> *>(&u))->size(), mxINT16_CLASS,
      mxREAL);
  pData = static_cast<int16_T *>(emlrtMxGetData(m));
  i = 0;
  for (int32_T b_i{0}; b_i < u.size(2); b_i++) {
    for (int32_T c_i{0}; c_i < u.size(1); c_i++) {
      for (int32_T d_i{0}; d_i < u.size(0); d_i++) {
        pData[i] = u[(d_i + u.size(0) * c_i) + u.size(0) * u.size(1) * b_i];
        i++;
      }
    }
  }
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(real_T u[16])
{
  static const int32_T b_iv[2]{0, 0};
  static const int32_T iv1[2]{4, 4};
  const mxArray *m;
  const mxArray *y;
  void *existingData;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  existingData = emlrtMxGetData((mxArray *)m);
  if (existingData != (void *)&u[0]) {
    emlrtFreeMex(existingData);
  }
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void matrx_mul_fixpt_logger_api(const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  struct0_T loggedData;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  coder::matrx_mul_fixpt_logger(&st, &loggedData);

  *plhs = emlrt_marshallOut(st, loggedData);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void matrx_mul_wrapper_fixpt_api(const mxArray *const prhs[2],
                                 const mxArray **plhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  real_T(*w)[16];
  real_T(*x)[16];
  real_T(*y)[16];
  st.tls = emlrtRootTLSGlobal;
  y = (real_T(*)[16])mxMalloc(sizeof(real_T[16]));

  x = emlrt_marshallIn(st, emlrtAlias(prhs[0]), "x");
  w = emlrt_marshallIn(st, emlrtAlias(prhs[1]), "w");

  matrx_mul_wrapper_fixpt(&st, *x, *w, *y);

  *plhs = emlrt_marshallOut(*y);
}
