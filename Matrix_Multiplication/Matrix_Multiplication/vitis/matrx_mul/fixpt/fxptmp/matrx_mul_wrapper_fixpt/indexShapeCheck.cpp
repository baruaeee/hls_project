#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

static emlrtRSInfo w_emlrtRSI{
    33, "indexShapeCheck",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"};

static emlrtRTEInfo i_emlrtRTEI{
    122, 5, "errOrWarnIf",
    "/MATLAB/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"};

namespace coder {
namespace internal {
void indexShapeCheck(const emlrtStack &sp, const int32_T matrixSize[3],
                     const int32_T indexSize[2])
{
  emlrtStack st;
  boolean_T guard1;
  boolean_T nonSingletonDimFound;
  st.prev = &sp;
  st.tls = sp.tls;
  nonSingletonDimFound = (matrixSize[0] != 1);
  guard1 = false;
  if (matrixSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1 && (matrixSize[2] != 1)) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }
  if (nonSingletonDimFound && (indexSize[1] != 1)) {
    nonSingletonDimFound = (matrixSize[0] != 1);
    if (nonSingletonDimFound || ((matrixSize[1] == 1) != (indexSize[1] == 1))) {
      nonSingletonDimFound = true;
    }
    if (nonSingletonDimFound || (matrixSize[2] != 1)) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }
  } else {
    nonSingletonDimFound = false;
  }
  st.site = &w_emlrtRSI;
  if (nonSingletonDimFound) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
                                  "Coder:FE:PotentialMatrixMatrix_MV",
                                  "Coder:FE:PotentialMatrixMatrix_MV", 0);
  }
}

} // namespace internal
} // namespace coder
