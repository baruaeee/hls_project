#include "calc_rice_k_wrapper_fixpt_hdl_mex_terminate.h"
#include "_coder_calc_rice_k_wrapper_fixpt_hdl_mex_mex.h"
#include "calc_rice_k_fixpt_logger.h"
#include "calc_rice_k_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

static void c_k_out_TB_logger_emx_free_dtor(void *r);

static void c_reset_TB_logger_emx_free_dtor(void *r);

static void c_u_in_TB_logger_emx_free_dtor_(void *r);

static void emlrtExitTimeCleanupDtorFcn(void *r);

static void c_k_out_TB_logger_emx_free_dtor(void *r)
{
  k_out_TB_logger_emx_free();
}

static void c_reset_TB_logger_emx_free_dtor(void *r)
{
  reset_TB_logger_emx_free();
}

static void c_u_in_TB_logger_emx_free_dtor_(void *r)
{
  u_in_TB_logger_emx_free();
}

static void emlrtExitTimeCleanupDtorFcn(void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void calc_rice_k_wrapper_fixpt_hdl_mex_atexit()
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
                                      (void *)&c_u_in_TB_logger_emx_free_dtor_,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_reset_TB_logger_emx_free_dtor,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_k_out_TB_logger_emx_free_dtor,
                                      nullptr, nullptr, nullptr);
    u_in_TB_logger_emx_free();
    reset_TB_logger_emx_free();
    k_out_TB_logger_emx_free();
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    emlrtDestroyArray(&eml_mx);
    emlrtDestroyArray(&b_eml_mx);
    emlrtDestroyArray(&c_eml_mx);
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

void calc_rice_k_wrapper_fixpt_hdl_mex_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}
