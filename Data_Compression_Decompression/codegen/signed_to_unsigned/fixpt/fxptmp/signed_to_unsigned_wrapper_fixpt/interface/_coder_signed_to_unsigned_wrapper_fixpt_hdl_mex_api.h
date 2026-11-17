#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void d_signed_to_unsigned_fixpt_logg(const mxArray **plhs);

void d_signed_to_unsigned_wrapper_fi(const mxArray *const prhs[1],
                                     const mxArray **plhs);
