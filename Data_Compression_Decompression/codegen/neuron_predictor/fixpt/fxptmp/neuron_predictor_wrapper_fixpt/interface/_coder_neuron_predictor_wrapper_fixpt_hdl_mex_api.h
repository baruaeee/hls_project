#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void d_neuron_predictor_fixpt_logger(const mxArray **plhs);

void d_neuron_predictor_wrapper_fixp(const mxArray *const prhs[2], int32_T nlhs,
                                     const mxArray *plhs[2]);
