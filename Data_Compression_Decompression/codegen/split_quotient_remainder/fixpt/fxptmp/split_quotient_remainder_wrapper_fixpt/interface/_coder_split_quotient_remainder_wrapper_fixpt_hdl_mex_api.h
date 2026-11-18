#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void d_split_quotient_remainder_fixp(const mxArray **plhs);

void d_split_quotient_remainder_wrap(const mxArray *const prhs[2], int32_T nlhs,
                                     const mxArray *plhs[2]);
