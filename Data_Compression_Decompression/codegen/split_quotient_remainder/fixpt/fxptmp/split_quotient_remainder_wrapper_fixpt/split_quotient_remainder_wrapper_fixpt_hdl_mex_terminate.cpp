#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_terminate.h"
#include "_coder_split_quotient_remainder_wrapper_fixpt_hdl_mex_mex.h"
#include "rt_nonfinite.h"
#include "split_quotient_remainder_fixpt_logger.h"
#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_data.h"

static void c_k_in_TB_logger_emx_free_dtor_(void *r);

static void c_q_out_TB_logger_emx_free_dtor(void *r);

static void c_r_out_TB_logger_emx_free_dtor(void *r);

static void c_u_in_TB_logger_emx_free_dtor_(void *r);

static void emlrtExitTimeCleanupDtorFcn(void *r);

static void c_k_in_TB_logger_emx_free_dtor_(void *r)
{
  k_in_TB_logger_emx_free();
}

static void c_q_out_TB_logger_emx_free_dtor(void *r)
{
  q_out_TB_logger_emx_free();
}

static void c_r_out_TB_logger_emx_free_dtor(void *r)
{
  r_out_TB_logger_emx_free();
}

static void c_u_in_TB_logger_emx_free_dtor_(void *r)
{
  u_in_TB_logger_emx_free();
}

static void emlrtExitTimeCleanupDtorFcn(void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void split_quotient_remainder_wrapper_fixpt_hdl_mex_atexit()
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
                                      (void *)&c_k_in_TB_logger_emx_free_dtor_,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_q_out_TB_logger_emx_free_dtor,
                                      nullptr, nullptr, nullptr);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&c_r_out_TB_logger_emx_free_dtor,
                                      nullptr, nullptr, nullptr);
    u_in_TB_logger_emx_free();
    k_in_TB_logger_emx_free();
    q_out_TB_logger_emx_free();
    r_out_TB_logger_emx_free();
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

void split_quotient_remainder_wrapper_fixpt_hdl_mex_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}
