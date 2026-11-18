#include "_coder_split_quotient_remainder_wrapper_fixpt_hdl_mex_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8]{
      "789ced59cd4f1341149f2e850002d69818bc182e1a4f146242ca11daca47ac80c55834a6"
      "5ddb6959ec7eb0dd02bde90d4f78e4643cf23f78f1e89fe0c53b478f"
      "5e4cdcb6fbdaee4b1fb35028d8ee4ba6b36f7e33eff766def4cdb6c3022b8900636c82d5"
      "2573bf5e8f3b7ac8a925e6168c079c3a88749041071947f891536775",
      "cde207565dd1649537462a9a51b6362b062fd98ac94b7a718fe76a485e29f24d45e5c956"
      "e57955539fb6400da50a559fa3db3cfb3e595699b95d6a7a586c559a"
      "eb41cc37c8dc82712c783d703fe03bbc201fd87f24e003bc6414152bbd5bd62d856b56da"
      "e4aaac68396ea6f74dd930ec3aaf1c1856d3af9f04ef1dc48379038e",
      "e789e85ab2ae0fd5f92d53d10a4dfb07847dd019810f215ecc0ff864b3e997e4f46b2de0"
      "c76f82c7ebfa7f22fc0821fc4dfc6d38b1b0f96c61712a662a7b3c1c"
      "93ad7454578d748c67ed2a9cac05680302f4020214ceea395ee05a988a60b81639127607"
      "785a75fc11edf7db1ee74fc5619c0dd7ea2fecef4e37f940fa858ffa",
      "1e79ddbff708be10c22d6b55cf2d6c3d79bd56b1662a91fccef29cac2f35fd5817f088fc"
      "6084de2dfbfd9e073e7438ff0782f9034ebad727e70f3c831fa7048f"
      "d775ff48f81142f8f5ed3bffdce945be6e9d3ba57985cfc6e65e2eef6fa951d94accef2e"
      "4577177be7dcc910e36feaef8d87023ec0cf4e07e9a25e287093f57e",
      "be1f6097fb7be308e90cf503fccaf37ddefeb0cd788ab39dfdbb95a7bef979ff4af9ba95"
      "f75736e2115955e33ba5d4ac1e89af98abebb1d51efabd9121c6fb79"
      "bf2eff7bde0f323feffb79bf77f8fcbc7f39f64f47db8f1ff168ff70b4bd7d09e10cddf3"
      "a446dadbf57acf43ed17b8e7194138e8909f41c09f1fc3edf9ce9ff7",
      "dd76aaf73daf9c7fbad22d7c29824f14573c2f2aaec781b3c753f62381b3ed4ba85fd069"
      "8bd8256597af7699b4b1a996f2d82eb256699c8594e0d8033f14ace3"
      "82ef5506682ad7bca86789681f20da71eec17c332d9d27100efa89535f348fe2fd81fb2f"
      "235c22f42154e798cecaec1d2b32ee7a06bfbf77e8f798c0ef8c47bf",
      "6fa19a33d5f6b4ea73aef639cdf24c215aab02f3f9d3e17cee0ae6732c980fec253c9f4e"
      "e6779e56d1fff05ed781ba8f87fe53827500699c87445e13e54d6c97"
      "b26f08c653f645e72d9c4b379d3f43d81f636e39effa0e12ef717e3caf967ff882ef0160"
      "ef04e92012c2f1fbdd67c2ee75bddf81fc0353931798",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 9328U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7]{
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7]{
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216]{
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 2, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("split_quotient_remainder_wrapper_fixpt"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "/MATLAB "
          "Drive/Dat_Comp_Decomp/Split_Quotient_Remainder/codegen/"
          "split_quotient_remainder/fixpt/split_quotient_remainder_wrapper_f"
          "ixpt.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740304.0655324074));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 1, "QualifiedName",
                emlrtMxCreateString("split_quotient_remainder_fixpt_logger"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "ResolvedFilePath",
      emlrtMxCreateString(
          "/MATLAB "
          "Drive/Dat_Comp_Decomp/Split_Quotient_Remainder/codegen/"
          "split_quotient_remainder/fixpt/fxptmp/split_quotient_remainder_fi"
          "xpt_logger.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(740304.0658680556));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("26.2.0.3468271 (R2026b) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("xFfoN8lQFr4TRbEBe2WwLG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}
