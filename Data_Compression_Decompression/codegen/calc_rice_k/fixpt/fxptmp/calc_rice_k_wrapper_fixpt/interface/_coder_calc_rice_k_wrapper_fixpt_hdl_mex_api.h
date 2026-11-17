#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void calc_rice_k_fixpt_logger_api(const mxArray **plhs);

void calc_rice_k_wrapper_fixpt_api(const mxArray *const prhs[2],
                                   const mxArray **plhs);
