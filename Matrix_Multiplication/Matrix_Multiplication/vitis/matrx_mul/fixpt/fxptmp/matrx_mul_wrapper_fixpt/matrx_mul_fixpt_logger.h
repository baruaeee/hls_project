#pragma once

#include "matrx_mul_wrapper_fixpt_hdl_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace coder {
void b_matrx_mul_fixpt_logger(const emlrtStack &sp,
                              const int16_T varargin_1[16],
                              const uint16_T varargin_2[16],
                              const int16_T varargin_3[16]);

void matrx_mul_fixpt_logger(const emlrtStack *sp, struct0_T *loggedData);

} // namespace coder
void matrx_mul_fixpt_logger_init();

void w_TB_logger_emx_free();

void w_TB_logger_emx_init();

void w_TB_logger_init();

void x_TB_logger_emx_free();

void x_TB_logger_emx_init();

void x_TB_logger_init();

void y_TB_logger_emx_free();

void y_TB_logger_emx_init();

void y_TB_logger_init();
