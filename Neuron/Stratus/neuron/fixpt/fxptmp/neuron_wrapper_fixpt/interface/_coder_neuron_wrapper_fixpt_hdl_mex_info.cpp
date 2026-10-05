#include "_coder_neuron_wrapper_fixpt_hdl_mex_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6]{
      "789ced96c16ed340108637a82024281451f51138a1ae40546a8f28a54d911bb5b549910a"
      "729c781cbbf5ae57f6a6496ebc0127de8563252edc792188ed4d9c25"
      "66abba3534780e998c7eef7e3313f957506d6fbf86107a8492f8b496e4e5b45e49f31d34"
      "1bb25e4bf392548bb89b2acb92fe39cddd807218f2a4a01681c9493b",
      "201eb52837460c500851e09f831d2b8ee783e111d0b345735c919d8c3429c6d2f87bdd85"
      "ee99de272874a369877eb698eca39d33ef129a0d599743de87fc9ce0"
      "0dafc813f7af2a7842a7d00f036a0e428b31084dc71b329eeda35db08f7bb97d248a1df4"
      "3b3e4c7917057927b9bc59fde4cd474c28c7038fdac1203223d70a01",
      "ef7afc0858801b9a6e1a2e445e849bf182b0ce438bf7239cec0bc77bc2f396b74ee2fb55"
      "fb7b7cc979e43c7dfe7e9cbf906fa765f244fc2fbca2efe15a0e6f45"
      "d2fdd3b3437ba3f372d362db23edf84837b67a6f77a67d1c2838aa3e504e5dd6fd1739e7"
      "6feb7bcd0acef350318fd0d3567ef3e5a2fc070abed08174c0b6c15e",
      "773c94e57f2dc8d7157ca15fe7ef59f9f3e2f1caf267976e847ba39ef6be7ebea5d75b0d"
      "76acf117db8be3cfed9cf3ffeaffdba70a9ed0b3afbee907bd1e8433"
      "7dfc6d1ffd5e906f29f842bf161f757e7d1086e7ec3475d5f27ce0092dd7579f7ff8f1ac"
      "4c9e8845f755fa8abeeb348c560b0e0e5f83d16d6a0edddfad7c558e",
      "dbe6abed2bf621c765e7ae7c74fe5c958f2651f9e89f39aa3e504e7dd3f7ff04e6004fd"
      "e",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 5784U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("neuron_wrapper_fixpt"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/mnt/windows_share/GitRepo/HLS_Thesis/Neuron/"
                          "Stratus/neuron/fixpt/neuron_wrapper_fixpt.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740260.477650463));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 1, "QualifiedName",
                emlrtMxCreateString("neuron_fixpt_logger"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "ResolvedFilePath",
      emlrtMxCreateString("/mnt/windows_share/GitRepo/HLS_Thesis/Neuron/"
                          "Stratus/neuron/fixpt/fxptmp/neuron_fixpt_logger.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(740260.4790856482));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.2.0.2998904 (R2025b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("OXS5FsyjOXuvGASMr5oSiG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}
