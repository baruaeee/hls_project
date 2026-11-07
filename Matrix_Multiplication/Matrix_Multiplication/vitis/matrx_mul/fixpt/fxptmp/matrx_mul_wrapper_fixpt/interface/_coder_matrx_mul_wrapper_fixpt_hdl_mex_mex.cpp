#include "_coder_matrx_mul_wrapper_fixpt_hdl_mex_mex.h"
#include "_coder_matrx_mul_wrapper_fixpt_hdl_mex_api.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_data.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_initialize.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_terminate.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
void matrx_mul_fixpt_logger_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                        int32_T nrhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        22, "matrx_mul_fixpt_logger");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "matrx_mul_fixpt_logger");
  }

  matrx_mul_fixpt_logger_api(&outputs);

  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void matrx_mul_wrapper_fixpt_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                         int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        23, "matrx_mul_wrapper_fixpt");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "matrx_mul_wrapper_fixpt");
  }

  matrx_mul_wrapper_fixpt_api(prhs, &outputs);

  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const char_T *entryPointTemplateNames[2]{"matrx_mul_wrapper_fixpt",
                                           "matrx_mul_fixpt_logger"};
  mexAtExit(&matrx_mul_wrapper_fixpt_hdl_mex_atexit);
  matrx_mul_wrapper_fixpt_hdl_mex_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    switch (emlrtGetEntryPointIndexR2016a(
        &st, nrhs, &prhs[0], (const char_T **)&entryPointTemplateNames[0], 2)) {
    case 0:
      matrx_mul_wrapper_fixpt_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    case 1:
      matrx_mul_fixpt_logger_mexFunction(nlhs, plhs, nrhs - 1);
      break;
    }
    matrx_mul_wrapper_fixpt_hdl_mex_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "UTF-8", true);
  return emlrtRootTLSGlobal;
}
