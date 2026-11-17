#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void neuron_predictor_wrapper_fixpt(const emlrtStack *sp, real_T x_in,
                                    boolean_T reset, real_T *residual,
                                    real_T *predicted);
