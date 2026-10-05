#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

real_T neuron_wrapper_fixpt(const emlrtStack *sp, const real_T x[4],
                            const real_T w[4], real_T b);
