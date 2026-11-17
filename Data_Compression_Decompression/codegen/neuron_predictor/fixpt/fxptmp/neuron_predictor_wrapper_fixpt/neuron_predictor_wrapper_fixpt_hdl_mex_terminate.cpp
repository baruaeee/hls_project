#include "neuron_predictor_wrapper_fixpt_hdl_mex_terminate.h"
#include "_coder_neuron_predictor_wrapper_fixpt_hdl_mex_mex.h"
#include "neuron_predictor_fixpt_logger.h"
#include "neuron_predictor_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

static void c_predicted_TB_logger_emx_free_(void *r);

static void c_reset_TB_logger_emx_free_dtor(void *r);

static void c_residual_TB_logger_emx_free_d(void *r);

static void c_x_in_TB_logger_emx_free_dtor_(void *r);

static void emlrtExitTimeCleanupDtorFcn(void *r);

static void c_predicted_TB_logger_emx_free_(void *r)
{
  predicted_TB_logger_emx_free();
}

static void c_reset_TB_logger_emx_free_dtor(void *r)
{
  reset_TB_logger_emx_free();
}

static void c_residual_TB_logger_emx_free_d(void *r)
{
  residual_TB_logger_emx_free();
}

static void c_x_in_TB_logger_emx_free_dtor_(void *r)
{
  x_in_TB_logger_emx_free();
}

static void emlrtExitTimeCleanupDtorFcn(void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void neuron_predictor_wrapper_fixpt_hdl_mex_atexit()
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
                                      (void *)&c_x_in_TB_logger_emx_free_dtor_,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_reset_TB_logger_emx_free_dtor,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_residual_TB_logger_emx_free_d,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_predicted_TB_logger_emx_free_,
                                      nullptr, nullptr, nullptr);
    x_in_TB_logger_emx_free();
    reset_TB_logger_emx_free();
    residual_TB_logger_emx_free();
    predicted_TB_logger_emx_free();
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

void neuron_predictor_wrapper_fixpt_hdl_mex_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}
