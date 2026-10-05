#pragma once

#include "neuron_wrapper_fixpt_hdl_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void b_TB_logger_emx_free();

void b_TB_logger_emx_init();

void b_TB_logger_init();

namespace coder {
void b_neuron_fixpt_logger(const emlrtStack &sp, const int16_T varargin_1[4],
                           const uint16_T varargin_2[4], uint8_T varargin_3,
                           int16_T varargin_4);

void neuron_fixpt_logger(const emlrtStack *sp, struct0_T *loggedData);

} // namespace coder
void neuron_fixpt_logger_init();

void w_TB_logger_emx_free();

void w_TB_logger_emx_init();

void w_TB_logger_init();

void x_TB_logger_emx_free();

void x_TB_logger_emx_init();

void x_TB_logger_init();

void y_TB_logger_emx_free();

void y_TB_logger_emx_init();

void y_TB_logger_init();
