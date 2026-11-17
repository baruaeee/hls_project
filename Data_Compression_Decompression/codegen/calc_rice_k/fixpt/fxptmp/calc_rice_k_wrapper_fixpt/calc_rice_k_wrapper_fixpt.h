#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

real_T calc_rice_k_wrapper_fixpt(const emlrtStack *sp, real_T u_in,
                                 boolean_T reset);
