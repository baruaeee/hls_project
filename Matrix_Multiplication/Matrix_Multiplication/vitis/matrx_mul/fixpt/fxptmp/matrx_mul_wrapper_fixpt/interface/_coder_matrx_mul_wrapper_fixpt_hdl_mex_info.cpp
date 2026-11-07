#include "_coder_matrx_mul_wrapper_fixpt_hdl_mex_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8]{
      "789ced59cd52d35014be0d8501e4a72ed42e71e78a32ce30c08e0af83706c42002eaf407"
      "6edb0b499b49d3125cf906ba74e992a54b973e822bc78d33be80ef60"
      "d2e6a4e9991e125a284cc999b9bd39f96ece77cebdc9974c2f8b3d93638cb129d6b464b2"
      "d94fba7ec2ed25d66e188fb97d1cf960c32e3289f04f6ebf5f299bdc",
      "329b4e39a771ef4a51d66be6d689ceabb663f06a45adf3830652102adf121a57fccebae3"
      "698f7d90e7389073bc52e2fb474a4d6346a9daca50f53bde7c64897a"
      "e3acdd308e0dcf071e077c56977c10ff5e001fe05ace34ac8c565333c7464ed7b9912908"
      "4b37bd3c7e133cb7515ccc13733395573694a63fd2f0aba621cac5e0",
      "3ac167043e8278313fe0c9d6a93f923bcedf208fef044fd8f9de26f24820fceddafb949c"
      "de7a917e34b36a883a4fc9f602082b23d75453e8aad8cf99a2524ed5"
      "8529aa296f71528d4549118b35ab05dfa7d321eba0e673928d36fafbbffe1d3a7dbff8c0"
      "6e0a5fafcffd5d822f81f092f244d6f636357dada05a6961ed997965",
      "71ad95c7cb009ea03c18e1f72bfea03ccf7a8f754c231fd701782b959ba1ff700c797c23"
      "78c2cef33a914702e11774bf44ba3f607cfdd2fdb9a3d7b95abeb059"
      "e7873b0f4bf3e99de7f3c7f9d5c1d1fd2c71fd75fd4e0fbb6ee8d1cfa89562911b6ce075"
      "7a88b5ebf40f8227ec7cbf23f24820bc279d2ed83f9a8ee5da5d3347",
      "b5fba7334b916e5f2a5fafcfff1d822f81f00fbbaf94852579d7d8503695c3ed85a38a31"
      "5764916e638b74fb7ae8769c45ba7d563d916e5f2d5fa4db1713ffe7"
      "78e7ebc742c6d7c73bc79710ced0fec4f258e7b861f727a8fb05f627c6100e3ee82d98f7"
      "ffc16867bef3eb787b1c679fe28dfbe750c6c7b74cf005ad2bae8b5a",
      "d72fb1b3afa7e22fc6ce8e2fa17171f7dca2dd76ecf6d56e491b9bf1b50776cb954fbc77"
      "1b6578ed811f1af671c3fb034334555b5dd4b1449c1f22ce63edc17c"
      "73bec1530807ffd4edbbd5517c7fe0f14f112e11fe08ea0f5885d5589ea98cb71d077d1f"
      "84cd7b2220ef6cc8bc6fa19e33cdced4c9f9a0f13bcb0a4c10671d83",
      "7afef6584fd0f3fc31a01eb8c7703dddd44557dbaa17f2e9b65e6abf18c6cf04d40be6bd"
      "f708fd0ad2471c978a4ffd2f1ff6fdc3081fde3fd79d3f4bc49f60ed"
      "76def91d26bed7a2f5bc5cfed12edff710ef14f96012c2f177dc6722ee557dc781fd0772"
      "7a9253",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 8976U, &nameCaptureInfo);
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
                emlrtMxCreateString("matrx_mul_wrapper_fixpt"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/MATLAB "
                          "Drive/Matrix_Multiplication/vitis/matrx_mul/fixpt/"
                          "matrx_mul_wrapper_fixpt.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740292.5618634259));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 1, "QualifiedName",
                emlrtMxCreateString("matrx_mul_fixpt_logger"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "ResolvedFilePath",
      emlrtMxCreateString("/MATLAB "
                          "Drive/Matrix_Multiplication/vitis/matrx_mul/fixpt/"
                          "fxptmp/matrx_mul_fixpt_logger.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(740292.5621412037));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("26.2.0.3433840 (R2026b) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("DGkHgYM9jsINbiiF8CEcmB"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}
