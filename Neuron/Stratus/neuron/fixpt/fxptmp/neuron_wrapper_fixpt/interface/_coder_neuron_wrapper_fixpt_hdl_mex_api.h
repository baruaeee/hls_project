#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void neuron_fixpt_logger_api(const mxArray **plhs);

void neuron_wrapper_fixpt_api(const mxArray *const prhs[3],
                              const mxArray **plhs);
