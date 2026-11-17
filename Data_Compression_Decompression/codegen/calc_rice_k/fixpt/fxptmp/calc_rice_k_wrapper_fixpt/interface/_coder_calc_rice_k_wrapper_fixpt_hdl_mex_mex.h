#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void calc_rice_k_fixpt_logger_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs);

void calc_rice_k_wrapper_fixpt_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs,
                                           const mxArray *prhs[2]);

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();
