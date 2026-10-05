#include "neuron_wrapper_fixpt_hdl_mex_terminate.h"
#include "_coder_neuron_wrapper_fixpt_hdl_mex_mex.h"
#include "neuron_fixpt_logger.h"
#include "neuron_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

static void b_TB_logger_emx_free_dtor_fcn(const void *r);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

static void w_TB_logger_emx_free_dtor_fcn(const void *r);

static void x_TB_logger_emx_free_dtor_fcn(const void *r);

static void y_TB_logger_emx_free_dtor_fcn(const void *r);

static void b_TB_logger_emx_free_dtor_fcn(const void *r)
{
  b_TB_logger_emx_free();
}

static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

static void w_TB_logger_emx_free_dtor_fcn(const void *r)
{
  w_TB_logger_emx_free();
}

static void x_TB_logger_emx_free_dtor_fcn(const void *r)
{
  x_TB_logger_emx_free();
}

static void y_TB_logger_emx_free_dtor_fcn(const void *r)
{
  y_TB_logger_emx_free();
}

void neuron_wrapper_fixpt_hdl_mex_atexit()
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
                                      (void *)&b_TB_logger_emx_free_dtor_fcn,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&y_TB_logger_emx_free_dtor_fcn,
                                      nullptr, nullptr, nullptr);
    x_TB_logger_emx_free();
    w_TB_logger_emx_free();
    b_TB_logger_emx_free();
    y_TB_logger_emx_free();
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    emlrtDestroyArray(&eml_mx);
    emlrtDestroyArray(&b_eml_mx);
    emlrtDestroyArray(&c_eml_mx);
    emlrtDestroyArray(&d_eml_mx);
    emlrtDestroyArray(&e_eml_mx);
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

void neuron_wrapper_fixpt_hdl_mex_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}
