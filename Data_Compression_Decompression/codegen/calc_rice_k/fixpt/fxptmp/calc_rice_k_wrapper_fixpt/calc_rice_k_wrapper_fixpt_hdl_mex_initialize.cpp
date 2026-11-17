#include "calc_rice_k_wrapper_fixpt_hdl_mex_initialize.h"
#include "_coder_calc_rice_k_wrapper_fixpt_hdl_mex_mex.h"
#include "calc_rice_k_fixpt.h"
#include "calc_rice_k_fixpt_logger.h"
#include "calc_rice_k_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

static emlrtMCInfo emlrtMCI{-1, -1, "", ""};

static void c_calc_rice_k_wrapper_fixpt_hdl(const emlrtStack &sp);

static const mxArray *fimath(const emlrtStack &sp, emlrtMCInfo &location);

static const mxArray *numerictype(const emlrtStack &sp, real_T d,
                                  emlrtMCInfo &location);

static void c_calc_rice_k_wrapper_fixpt_hdl(const emlrtStack &sp)
{
  mex_InitInfAndNan();
  emlrtAssignP(&c_eml_mx, numerictype(sp, 4.0, emlrtMCI));
  emlrtAssignP(&b_eml_mx, numerictype(sp, 10.0, emlrtMCI));
  emlrtAssignP(&eml_mx, fimath(sp, emlrtMCI));
  u_in_TB_logger_emx_init();
  reset_TB_logger_emx_init();
  k_out_TB_logger_emx_init();
  calc_rice_k_fixpt_init();
  calc_rice_k_fixpt_logger_init();
  u_in_TB_logger_init();
  reset_TB_logger_init();
  k_out_TB_logger_init();
}

static const mxArray *fimath(const emlrtStack &sp, emlrtMCInfo &location)
{
  const mxArray *pArrays[42];
  const mxArray *m;
  pArrays[0] = emlrtCreateStringR2022a((emlrtCTX)&sp, "RoundMode");
  pArrays[1] = emlrtCreateStringR2022a((emlrtCTX)&sp, "floor");
  pArrays[2] = emlrtCreateStringR2022a((emlrtCTX)&sp, "RoundingMethod");
  pArrays[3] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Floor");
  pArrays[4] = emlrtCreateStringR2022a((emlrtCTX)&sp, "OverflowMode");
  pArrays[5] = emlrtCreateStringR2022a((emlrtCTX)&sp, "wrap");
  pArrays[6] = emlrtCreateStringR2022a((emlrtCTX)&sp, "OverflowAction");
  pArrays[7] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Wrap");
  pArrays[8] = emlrtCreateStringR2022a((emlrtCTX)&sp, "ProductMode");
  pArrays[9] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FullPrecision");
  pArrays[10] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SumMode");
  pArrays[11] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FullPrecision");
  pArrays[12] = emlrtCreateStringR2022a((emlrtCTX)&sp, "ProductWordLength");
  pArrays[13] = emlrtCreateDoubleScalar(32.0);
  pArrays[14] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SumWordLength");
  pArrays[15] = emlrtCreateDoubleScalar(32.0);
  pArrays[16] = emlrtCreateStringR2022a((emlrtCTX)&sp, "MaxProductWordLength");
  pArrays[17] = emlrtCreateDoubleScalar(65535.0);
  pArrays[18] = emlrtCreateStringR2022a((emlrtCTX)&sp, "MaxSumWordLength");
  pArrays[19] = emlrtCreateDoubleScalar(65535.0);
  pArrays[20] = emlrtCreateStringR2022a((emlrtCTX)&sp, "ProductFractionLength");
  pArrays[21] = emlrtCreateDoubleScalar(30.0);
  pArrays[22] = emlrtCreateStringR2022a((emlrtCTX)&sp, "ProductFixedExponent");
  pArrays[23] = emlrtCreateDoubleScalar(-30.0);
  pArrays[24] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SumFractionLength");
  pArrays[25] = emlrtCreateDoubleScalar(30.0);
  pArrays[26] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SumFixedExponent");
  pArrays[27] = emlrtCreateDoubleScalar(-30.0);
  pArrays[28] =
      emlrtCreateStringR2022a((emlrtCTX)&sp, "SumSlopeAdjustmentFactor");
  pArrays[29] = emlrtCreateDoubleScalar(1.0);
  pArrays[30] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SumBias");
  pArrays[31] = emlrtCreateDoubleScalar(0.0);
  pArrays[32] =
      emlrtCreateStringR2022a((emlrtCTX)&sp, "ProductSlopeAdjustmentFactor");
  pArrays[33] = emlrtCreateDoubleScalar(1.0);
  pArrays[34] = emlrtCreateStringR2022a((emlrtCTX)&sp, "ProductBias");
  pArrays[35] = emlrtCreateDoubleScalar(0.0);
  pArrays[36] = emlrtCreateStringR2022a((emlrtCTX)&sp, "CastBeforeSum");
  pArrays[37] = emlrtCreateLogicalScalar(true);
  pArrays[38] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SumSlope");
  pArrays[39] = emlrtCreateDoubleScalar(9.313225746154785E-10);
  pArrays[40] = emlrtCreateStringR2022a((emlrtCTX)&sp, "ProductSlope");
  pArrays[41] = emlrtCreateDoubleScalar(9.313225746154785E-10);
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 42, &pArrays[0],
                               "fimath", true, &location);
}

static const mxArray *numerictype(const emlrtStack &sp, real_T d,
                                  emlrtMCInfo &location)
{
  const mxArray *pArrays[14];
  const mxArray *m;
  pArrays[0] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SignednessBool");
  pArrays[1] = emlrtCreateLogicalScalar(false);
  pArrays[2] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Signedness");
  pArrays[3] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Unsigned");
  pArrays[4] = emlrtCreateStringR2022a((emlrtCTX)&sp, "WordLength");
  pArrays[5] = emlrtCreateDoubleScalar(d);
  pArrays[6] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FractionLength");
  pArrays[7] = emlrtCreateDoubleScalar(0.0);
  pArrays[8] = emlrtCreateStringR2022a((emlrtCTX)&sp, "BinaryPoint");
  pArrays[9] = emlrtCreateDoubleScalar(0.0);
  pArrays[10] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Slope");
  pArrays[11] = emlrtCreateDoubleScalar(1.0);
  pArrays[12] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FixedExponent");
  pArrays[13] = emlrtCreateDoubleScalar(0.0);
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 14, &pArrays[0],
                               "numerictype", true, &location);
}

void calc_rice_k_wrapper_fixpt_hdl_mex_initialize()
{
  emlrtStack st{nullptr, nullptr, nullptr};
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 3U, "ForceOff");
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "fixed_point_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    c_calc_rice_k_wrapper_fixpt_hdl(st);
  }
}
