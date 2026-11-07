#include "matrx_mul_wrapper_fixpt_hdl_mex_terminate.h"
#include "_coder_matrx_mul_wrapper_fixpt_hdl_mex_mex.h"
#include "matrx_mul_fixpt_logger.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

static void emlrtExitTimeCleanupDtorFcn(void *r);

static void w_TB_logger_emx_free_dtor_fcn(void *r);

static void x_TB_logger_emx_free_dtor_fcn(void *r);

static void y_TB_logger_emx_free_dtor_fcn(void *r);

static void emlrtExitTimeCleanupDtorFcn(void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

static void w_TB_logger_emx_free_dtor_fcn(void *r)
{
  w_TB_logger_emx_free();
}

static void x_TB_logger_emx_free_dtor_fcn(void *r)
{
  x_TB_logger_emx_free();
}

static void y_TB_logger_emx_free_dtor_fcn(void *r)
{
  y_TB_logger_emx_free();
}

void matrx_mul_wrapper_fixpt_hdl_mex_atexit()
{
  emlrtStack st{nullptr, nullptr, nullptr};
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  try {
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&emlrtExitTimeCleanupDtorFcn,
                                      nullptr, nullptr, nullptr);
    emlrtEnterRtStackR2012b(&st);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&x_TB_logger_emx_free_dtor_fcn,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&w_TB_logger_emx_free_dtor_fcn,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&y_TB_logger_emx_free_dtor_fcn,
                                      nullptr, nullptr, nullptr);
    x_TB_logger_emx_free();
    w_TB_logger_emx_free();
    y_TB_logger_emx_free();
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    emlrtDestroyArray(&eml_mx);
    emlrtDestroyArray(&b_eml_mx);
    emlrtDestroyArray(&c_eml_mx);
    emlrtDestroyArray(&d_eml_mx);
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

void matrx_mul_wrapper_fixpt_hdl_mex_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}
