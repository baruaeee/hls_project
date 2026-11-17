#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_terminate.h"
#include "_coder_signed_to_unsigned_wrapper_fixpt_hdl_mex_mex.h"
#include "rt_nonfinite.h"
#include "signed_to_unsigned_fixpt_logger.h"
#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_data.h"

static void c_e_in_TB_logger_emx_free_dtor_(void *r);

static void c_u_out_TB_logger_emx_free_dtor(void *r);

static void emlrtExitTimeCleanupDtorFcn(void *r);

static void c_e_in_TB_logger_emx_free_dtor_(void *r)
{
  e_in_TB_logger_emx_free();
}

static void c_u_out_TB_logger_emx_free_dtor(void *r)
{
  u_out_TB_logger_emx_free();
}

static void emlrtExitTimeCleanupDtorFcn(void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void signed_to_unsigned_wrapper_fixpt_hdl_mex_atexit()
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
                                      (void *)&c_e_in_TB_logger_emx_free_dtor_,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_u_out_TB_logger_emx_free_dtor,
                                      nullptr, nullptr, nullptr);
    e_in_TB_logger_emx_free();
    u_out_TB_logger_emx_free();
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

void signed_to_unsigned_wrapper_fixpt_hdl_mex_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}
