#include "_coder_signed_to_unsigned_wrapper_fixpt_hdl_mex_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8]{
      "789ced594b4fdb4010de9850c2b3e9a5a2a7e6d81341ea83702b105a1035cfb4145595e3"
      "3a9b60881f721c02a807d473a5f6d853c5b13fa33fa3974a1c7be407"
      "f45027f13af6d4c31a28290f8fb4598fbfddf9667736b39b2c49cc8b0942c80871e55ebb"
      "1a76d5b45b0b2428104fb87512e84c7a5d6418e09fdc5a31749beeda",
      "6d459735eaf55475b36e17f64c5a73148bd68cea0e2db590b25aa50555a36b7e65b1a969"
      "cf7c90a734a1e6f3cc2655b6d7ea1ab1366b1d0fab7ec59b8f2232de"
      "24090ac4a1c0f980ed18dfc119f998fd0c878fe135b5a2d392641b525d779f1b966c9ad4"
      "92caeaae69337f7e207c77807dc897703d166796d6dafaad36af6da9",
      "7aa533de5dc43ed30982df02bc909fe1a39d573f05b79dbf303f8e109ea8f3fe1ef1230d"
      "f037b36fb3e254e1c5d474266fa93b349b976d69c6d04c294f15a7ca"
      "8ab2290583a33795ac62946885ead9bf03976d052c040846744c2384bfae6f471c2f36ef"
      "c324d5aa3f4abfb7bac9c7e4a6f061df9ba8ebf52ec29706b8b55fae",
      "e617f7ed97dbca2cdd126579a5216ecc75fc58e6f0f0fc2088de2dfb4748ffebfabd3fef"
      "ba19053a1c2fc343bcba11fb0a7be68d33ea7cdb881f698077757dc5"
      "fbc9b5e3ebd67eb2f050aee7361a626ea931b535bd32b9ae28e6ec35da4f8a48ffcbfa7b"
      "e13e878fe1581690aa46a5422d6ebebbea79bd8704f3fa2f8427eabc",
      "7f40fc4803fce2f27ad9f970fa7302dbcef2ddcb4b5fe33c7fa17cddcaf3f31bcf2bcb93"
      "8fc7270aaf1ed5279eacce2f2cccad4ec7791e4a9ce72f579e4f9238"
      "cf37a5888c2bcef357832fcef3ffc6fec14078fffe88f63303e1f6058013700f739c0ab7"
      "1bf51e065b2fec1ea61fe04c67799989b77e117f4e9fef83769af731",
      "ebeedf55928fefb82f9c8f1757382e2cae5f1227f7c7ece71227db1740bba4fb2ee794d7"
      "4e3974caa883657ce58153647dcfdb033181b167fcac401d1678ffd1"
      "835305c6853d0bc8fb1ee43dcc3d906fdcd77804e05edcdcfaac79b42fc42f7ffb1cc005"
      "a0b39a9d234ac42075f28e54090df879784e3f534087ed9f46f473d0",
      "ad29d11c2fa9e36fa9f53946ca44f5f9fbfd9cfe0e71fc2d72fc65fa20a8c3fdc646c33f"
      "2f471d0f768fcdda6738e361e2ed5348bee1e5332caed0bec9e98fd9"
      "e7ed836cbfb8ecfc45c4fe1009ca69e7b717395fc5f1bc58fed419f76766ef1b625f0038"
      "3c777d46ecfeaf7317933f1705df0f",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 9128U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("signed_to_unsigned_wrapper_fixpt"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "/MATLAB "
          "Drive/Dat_Comp_Decomp/Map_signed_to_unsingned/codegen/"
          "signed_to_unsigned/fixpt/signed_to_unsigned_wrapper_fixpt.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740303.588287037));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 1, "QualifiedName",
                emlrtMxCreateString("signed_to_unsigned_fixpt_logger"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "ResolvedFilePath",
      emlrtMxCreateString(
          "/MATLAB "
          "Drive/Dat_Comp_Decomp/Map_signed_to_unsingned/codegen/"
          "signed_to_unsigned/fixpt/fxptmp/signed_to_unsigned_fixpt_logger.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(740303.5884953703));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("26.2.0.3437455 (R2026b) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("hetaHM41e1XupDuDvEbwsE"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}
