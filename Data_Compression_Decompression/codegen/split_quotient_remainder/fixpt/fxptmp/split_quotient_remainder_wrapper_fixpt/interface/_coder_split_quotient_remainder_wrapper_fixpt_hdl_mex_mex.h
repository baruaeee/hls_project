#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void split_quotient_remainder_fixpt_logger_mexFunction(int32_T nlhs,
                                                       mxArray *plhs[1],
                                                       int32_T nrhs);

void split_quotient_remainder_wrapper_fixpt_mexFunction(int32_T nlhs,
                                                        mxArray *plhs[2],
                                                        int32_T nrhs,
                                                        const mxArray *prhs[2]);
