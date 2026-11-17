#include "_coder_signed_to_unsigned_wrapper_fixpt_hdl_mex_mex.h"
#include "_coder_signed_to_unsigned_wrapper_fixpt_hdl_mex_api.h"
#include "rt_nonfinite.h"
#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_data.h"
#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_initialize.h"
#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_terminate.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const char_T *entryPointTemplateNames[2]{"signed_to_unsigned_wrapper_fixpt",
                                           "signed_to_unsigned_fixpt_logger"};
  mexAtExit(&signed_to_unsigned_wrapper_fixpt_hdl_mex_atexit);
  signed_to_unsigned_wrapper_fixpt_hdl_mex_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    switch (emlrtGetEntryPointIndexR2016a(
        &st, nrhs, &prhs[0], (const char_T **)&entryPointTemplateNames[0], 2)) {
    case 0:
      signed_to_unsigned_wrapper_fixpt_mexFunction(nlhs, plhs, nrhs - 1,
                                                   &prhs[1]);
      break;
    case 1:
      signed_to_unsigned_fixpt_logger_mexFunction(nlhs, plhs, nrhs - 1);
      break;
    }
    signed_to_unsigned_wrapper_fixpt_hdl_mex_terminate();
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

void signed_to_unsigned_fixpt_logger_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                                 int32_T nrhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        31, "signed_to_unsigned_fixpt_logger");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 31,
                        "signed_to_unsigned_fixpt_logger");
  }

  d_signed_to_unsigned_fixpt_logg(&outputs);

  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void signed_to_unsigned_wrapper_fixpt_mexFunction(int32_T nlhs,
                                                  mxArray *plhs[1],
                                                  int32_T nrhs,
                                                  const mxArray *prhs[1])
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        32, "signed_to_unsigned_wrapper_fixpt");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 32,
                        "signed_to_unsigned_wrapper_fixpt");
  }

  d_signed_to_unsigned_wrapper_fi(prhs, &outputs);

  emlrtReturnArrays(1, &plhs[0], &outputs);
}
