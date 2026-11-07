#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace coder {
namespace internal {
void indexShapeCheck(const emlrtStack &sp, const int32_T matrixSize[3],
                     const int32_T indexSize[2]);

}
} // namespace coder
