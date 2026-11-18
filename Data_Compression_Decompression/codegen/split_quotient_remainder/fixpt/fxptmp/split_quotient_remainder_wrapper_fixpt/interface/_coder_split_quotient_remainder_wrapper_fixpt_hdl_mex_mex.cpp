#include "_coder_split_quotient_remainder_wrapper_fixpt_hdl_mex_mex.h"
#include "_coder_split_quotient_remainder_wrapper_fixpt_hdl_mex_api.h"
#include "rt_nonfinite.h"
#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_data.h"
#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_initialize.h"
#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_terminate.h"
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
  const char_T *entryPointTemplateNames[2]{
      "split_quotient_remainder_wrapper_fixpt",
      "split_quotient_remainder_fixpt_logger"};
  mexAtExit(&split_quotient_remainder_wrapper_fixpt_hdl_mex_atexit);
  split_quotient_remainder_wrapper_fixpt_hdl_mex_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    switch (emlrtGetEntryPointIndexR2016a(
        &st, nrhs, &prhs[0], (const char_T **)&entryPointTemplateNames[0], 2)) {
    case 0:
      split_quotient_remainder_wrapper_fixpt_mexFunction(nlhs, plhs, nrhs - 1,
                                                         &prhs[1]);
      break;
    case 1:
      split_quotient_remainder_fixpt_logger_mexFunction(nlhs, plhs, nrhs - 1);
      break;
    }
    split_quotient_remainder_wrapper_fixpt_hdl_mex_terminate();
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

void split_quotient_remainder_fixpt_logger_mexFunction(int32_T nlhs,
                                                       mxArray *plhs[1],
                                                       int32_T nrhs)
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        37, "split_quotient_remainder_fixpt_logger");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 37,
                        "split_quotient_remainder_fixpt_logger");
  }

  d_split_quotient_remainder_fixp(&outputs);

  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void split_quotient_remainder_wrapper_fixpt_mexFunction(int32_T nlhs,
                                                        mxArray *plhs[2],
                                                        int32_T nrhs,
                                                        const mxArray *prhs[2])
{
  emlrtStack st{nullptr, nullptr, nullptr};
  const mxArray *outputs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        38, "split_quotient_remainder_wrapper_fixpt");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 38,
                        "split_quotient_remainder_wrapper_fixpt");
  }

  d_split_quotient_remainder_wrap(prhs, nlhs, outputs);

  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}
