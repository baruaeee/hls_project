#include "_coder_neuron_predictor_wrapper_fixpt_hdl_mex_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8]{
      "789ced593b73d340103e2b4ec8830443c1a481494915273304dc063b813c9c38d84020c3"
      "388e7c76446449235b8e4d153a3a2829292929292929296998e127f0"
      "032838db5a3f36de9cc8c3631cedccf9b4b7a7fd76ef4edfddf85860251e608c4db186bc"
      "9d6ed493ae1e726b85750ab607dc3a88749061d73289ecefdc5a358d",
      "12af941a8a9129f0e69b9a6139a554d5e245a1d8bc68ea659ead5b729ace535a8127db95"
      "8d9a56586e3335959aa9f61cdde7ea41d229307bbfd88a506f579ae3"
      "b14be41b649d82ed58f078e07e8077744a3cf07f5b820776833bb669a42d9b6735b564da"
      "e9433b6359dc4ee7b48a556ac5f383c0bb8efc63bc801b713cba996c",
      "e82375bd58b23523dff25f21fc83ce08fb08c2c5f8609f6e35fd54dc7eed05e2f846e078"
      "1d7795882384ec3b4b2fc3f1c5d4fae2839998ad9579389629a5a366"
      "c14ac7b82aaa707921ac9a599ee74618cf51b83e37c79a3ba76eb650c791addf6b1ef3a2"
      "c677928dd6eba76b7f5ef5120fe4b2e051df87d7757993c00b21fbfd",
      "f53de76023598e2de4ac95c8131e49981b6bd1561c09098e2c0e46e8bdf23fa8df77afd6"
      "c7b1a02ec93e01cf10c75702c7eb78ef10718490fd22d691bf3f0c1e"
      "5eafbefff8e3e5bbaf53d5757d73754fcd1c6eada94ba9d5a5c1d91f7689f7fbf59c7f4b"
      "8207f6ee2490d6cd7c9edb6cf0f97b8875f2f77702c7ebb86b441c21",
      "643f07fece891fd1f1c41974d9bc77fcf3c6e7f30bc5eb159f575e3cd7238e93c83bf3f3"
      "73cbf722f985adeaa3873e9f63f1f9bcbff83cc87c3eaf89cfe7ff07"
      "9ecfe7e7e3ffd778f7f7c73cfa3f1aefee5f417686ee431263ddfd7abd0fa1d60bdc878c"
      "213be8c0bf20cdff1f46bbe3fd3baf77faa9dd8b3c73ff674ab7e125",
      "083cd9bce2bca879fd1038f97dca7f2470b27f05f50bba6d1151b645f928cab4b0cdb495"
      "3ba2648c6a73afa304cf3de043c13a2ef81e628886eac88b7a5688f6"
      "21a21d730fc69b6beb3c85eca07f76ebd3f2e838d271ff04b22b840ee7852b6e9d652673"
      "d81ed31917c56479b183ab2c239e3be3ff72c6f82724f16f7b8c1ffc",
      "40fc9c1544f45ce491adffceb29cc8e0782690c7ef33e6714392c77b491eb096701e13a8"
      "f69257f73edd5b65e76eaff953f7d5d07f46923f48932f093e93f125"
      "f64bf9b724ef53fe65fb2cec47fd8ebf4bf8bf2ac1978def30717ef3e7f362f1474fb9ff"
      "83bf4f847f05d9f1b90e78ad5fce75207f01a88eb674",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 9104U, &nameCaptureInfo);
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
                emlrtMxCreateString("neuron_predictor_wrapper_fixpt"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/MATLAB "
                          "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/"
                          "fixpt/neuron_predictor_wrapper_fixpt.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740303.5284027777));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 1, "QualifiedName",
                emlrtMxCreateString("neuron_predictor_fixpt_logger"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "ResolvedFilePath",
      emlrtMxCreateString("/MATLAB "
                          "Drive/Dat_Comp_Decomp/v5/codegen/neuron_predictor/"
                          "fixpt/fxptmp/neuron_predictor_fixpt_logger.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(740303.528900463));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("26.2.0.3437455 (R2026b) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("trIsB6bgCNfcPWTe4d39QH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}
