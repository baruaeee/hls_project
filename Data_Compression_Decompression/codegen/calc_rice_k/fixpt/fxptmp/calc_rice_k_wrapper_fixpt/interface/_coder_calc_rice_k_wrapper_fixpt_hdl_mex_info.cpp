#include "_coder_calc_rice_k_wrapper_fixpt_hdl_mex_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8]{
      "789ced59bf53134114de84808002a171624769451ca0481b02384a90603282c338c779d9"
      "8423f76bee120c54fc075a3a569694da595ad24969e37f62e126b917"
      "2e8f3cee242462b837b3d97bf7edbeefbdddbdb73b591679b611618c4db396d413ad7aca"
      "d5e36e1d659d82f1885bc7900e32ea2253087fefd68a695479bdda52",
      "0c59e7ed9eaa61d5aa85238b3b42b1b9636a87bcd8444aaac60baacef35ee54543d3d73c"
      "505b69408de7cc3e572af99aceec7de7c243cdabb4c7638f8837c63a"
      "05e358f078e076c077724d3eb0ffc8870f7045d614c956152e55a477b66c59dc964a6add"
      "aa227f7e127cb3c83ee68bb81e6f6436f32d7daca93b555b35ca9ef5",
      "46d8079d11f818e2c5fc80272e5efd8abaedbc05fc382378828ebb42f81147f8eeea9be4"
      "46ba904d2fcfadd8ea214faec8552963ea96b4c21551255f36e62427"
      "dbb22e55928a59e4656e243db3956cce52929cbf79bdc9e3b77e6702c6458def141b6fd6"
      "5f7ffc3e18241fc85de1a3be8fa0ebf221c11747786929b5f8fa78b1",
      "96c96b8e91b69c2de77936b77ce147ce87c7cf0f46e883b23facdf77afeb6316e9382ec0"
      "bdfedca57d029ec18fef044fd0f1de25fc8823bc1feb28dc1f868f6f"
      "50fb43455e58df9257ed9a5538ced55e95cccd743e3b44fbc31ed1bf5fe7fc5ee72d8174"
      "cc07f8a5ef5fd2cc7299dbc39eb7475867de3e2778828eb74af81147",
      "f84de5ed92f811ada9e973b3f8e0f2cea7f3308ff7936f50793cbdae55eb4a76e120bdb4"
      "b0bd5a5c2b1d384ff399308f6309f3f8edc8e33116e6f1868479fcff"
      "e00bf3f8cdd83f9becde7f22a0fdfdc9eef6a30867e8fe2335d1dd6ed0fb0f6abdc0fdc7"
      "04c24187fc0b02fe9c8e77e7fbfbbcde69a7710fb2edfeaf2479f852",
      "049fdfbce2b8a879fd18b9ba3f653f15b9da7e14b58bb9ef52a2ec88f2599484c0e63ce5"
      "b128b271d4deeb28c1730ffc50b08e0bbe7718a1a93ae2a29ea3c4fb"
      "11e23dce3d98ef89a7f134c241ffe2d6d7cda39348c7ed73088f123a9c17eeb9759199ac"
      "c6de328d71514c56163bb8c264f1dce9ffb71efdbfefe3ff4e40ffc1",
      "0ef8cf992ebce7228e62f3779e9544049723f13be7058d6306e9b87d1de1380e5863380e"
      "d083c4d3bd0deb88f3a4c738a97b68683fe71327487bbf23f2965f5e"
      "c47629fb964f7fcabedf7e0afbce6de7df23ec3ff0e1f71bdf51e29c16ce677ff9c7afb9"
      "cf83bd53c27e14e1f8fcf681b0fbafce6f207f00534aa743",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 9064U, &nameCaptureInfo);
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
                emlrtMxCreateString("calc_rice_k_wrapper_fixpt"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/MATLAB "
                          "Drive/Dat_Comp_Decomp/Rice_Param_k/codegen/"
                          "calc_rice_k/fixpt/calc_rice_k_wrapper_fixpt.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740303.9205671296));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 1, "QualifiedName",
                emlrtMxCreateString("calc_rice_k_fixpt_logger"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 1, "ResolvedFilePath",
                emlrtMxCreateString(
                    "/MATLAB "
                    "Drive/Dat_Comp_Decomp/Rice_Param_k/codegen/calc_rice_k/"
                    "fixpt/fxptmp/calc_rice_k_fixpt_logger.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(740303.9232638889));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("26.2.0.3468271 (R2026b) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("eu1n1TivdYnnP8BdREYPrD"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}
