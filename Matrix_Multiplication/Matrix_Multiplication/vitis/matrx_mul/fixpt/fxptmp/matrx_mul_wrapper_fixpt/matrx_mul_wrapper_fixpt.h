#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void matrx_mul_wrapper_fixpt(const emlrtStack *sp, const real_T x[16],
                             const real_T w[16], real_T y[16]);
