#pragma once

#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void split_quotient_remainder_wrapper_fixpt(const emlrtStack *sp, real_T u_in,
                                            real_T k_in, real_T *q_out,
                                            real_T *r_out);
