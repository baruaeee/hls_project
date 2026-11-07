#include "matrx_mul_wrapper_fixpt_hdl_mex_initialize.h"
#include "_coder_matrx_mul_wrapper_fixpt_hdl_mex_mex.h"
#include "matrx_mul_fixpt_logger.h"
#include "matrx_mul_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

static emlrtMCInfo emlrtMCI{-1, -1, "", ""};

static const mxArray *b_numerictype(const emlrtStack &sp,
                                    emlrtMCInfo &location);

static void c_matrx_mul_wrapper_fixpt_hdl_m(const emlrtStack &sp);

static const mxArray *c_numerictype(const emlrtStack &sp,
                                    emlrtMCInfo &location);

static const mxArray *fimath(const emlrtStack &sp, emlrtMCInfo &location);

static const mxArray *numerictype(const emlrtStack &sp, emlrtMCInfo &location);

static const mxArray *b_numerictype(const emlrtStack &sp, emlrtMCInfo &location)
{
  const mxArray *pArrays[14];
  const mxArray *m;
  pArrays[0] = emlrtCreateStringR2022a((emlrtCTX)&sp, "SignednessBool");
  pArrays[1] = emlrtCreateLogicalScalar(false);
  pArrays[2] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Signedness");
  pArrays[3] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Unsigned");
  pArrays[4] = emlrtCreateStringR2022a((emlrtCTX)&sp, "WordLength");
  pArrays[5] = emlrtCreateDoubleScalar(14.0);
  pArrays[6] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FractionLength");
  pArrays[7] = emlrtCreateDoubleScalar(17.0);
  pArrays[8] = emlrtCreateStringR2022a((emlrtCTX)&sp, "BinaryPoint");
  pArrays[9] = emlrtCreateDoubleScalar(17.0);
  pArrays[10] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Slope");
  pArrays[11] = emlrtCreateDoubleScalar(7.62939453125E-6);
  pArrays[12] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FixedExponent");
  pArrays[13] = emlrtCreateDoubleScalar(-17.0);
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 14, &pArrays[0],
                               "numerictype", true, &location);
}

static void c_matrx_mul_wrapper_fixpt_hdl_m(const emlrtStack &sp)
{
  mex_InitInfAndNan();
  emlrtAssignP(&d_eml_mx, numerictype(sp, emlrtMCI));
  emlrtAssignP(&c_eml_mx, b_numerictype(sp, emlrtMCI));
  emlrtAssignP(&b_eml_mx, c_numerictype(sp, emlrtMCI));
  emlrtAssignP(&eml_mx, fimath(sp, emlrtMCI));
  x_TB_logger_emx_init();
  w_TB_logger_emx_init();
  y_TB_logger_emx_init();
  matrx_mul_fixpt_logger_init();
  x_TB_logger_init();
  w_TB_logger_init();
  y_TB_logger_init();
}

static const mxArray *c_numerictype(const emlrtStack &sp, emlrtMCInfo &location)
{
  const mxArray *pArrays[10];
  const mxArray *m;
  pArrays[0] = emlrtCreateStringR2022a((emlrtCTX)&sp, "WordLength");
  pArrays[1] = emlrtCreateDoubleScalar(14.0);
  pArrays[2] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FractionLength");
  pArrays[3] = emlrtCreateDoubleScalar(13.0);
  pArrays[4] = emlrtCreateStringR2022a((emlrtCTX)&sp, "BinaryPoint");
  pArrays[5] = emlrtCreateDoubleScalar(13.0);
  pArrays[6] = emlrtCreateStringR2022a((emlrtCTX)&sp, "Slope");
  pArrays[7] = emlrtCreateDoubleScalar(0.0001220703125);
  pArrays[8] = emlrtCreateStringR2022a((emlrtCTX)&sp, "FixedExponent");
  pArrays[9] = emlrtCreateDoubleScalar(-13.0);
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 10, &pArrays[0],
                               "numerictype", true, &location);
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

static const mxArray *numerictype(const emlrtStack &sp, emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = emlrtCreateStringR2022a((emlrtCTX)&sp, "WordLength");
  pArrays[1] = emlrtCreateDoubleScalar(14.0);
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 2, &pArrays[0],
                               "numerictype", true, &location);
}

void matrx_mul_wrapper_fixpt_hdl_mex_initialize()
{
  emlrtStack st{nullptr, nullptr, nullptr};
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 3U, "ForceOff");
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "fixed_point_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    c_matrx_mul_wrapper_fixpt_hdl_m(st);
  }
}
