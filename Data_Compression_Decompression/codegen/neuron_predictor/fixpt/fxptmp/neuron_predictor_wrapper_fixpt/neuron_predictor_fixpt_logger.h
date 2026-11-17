#pragma once

#include "neuron_predictor_wrapper_fixpt_hdl_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void c_neuron_predictor_fixpt_logger();

namespace coder {
void b_neuron_predictor_fixpt_logger(const emlrtStack &sp, int16_T varargin_1,
                                     boolean_T varargin_2, int16_T varargin_3,
                                     int16_T varargin_4);

void neuron_predictor_fixpt_logger(const emlrtStack *sp, struct0_T *loggedData);

} // namespace coder
void predicted_TB_logger_emx_free();

void predicted_TB_logger_emx_init();

void predicted_TB_logger_init();

void reset_TB_logger_emx_free();

void reset_TB_logger_emx_init();

void reset_TB_logger_init();

void residual_TB_logger_emx_free();

void residual_TB_logger_emx_init();

void residual_TB_logger_init();

void x_in_TB_logger_emx_free();

void x_in_TB_logger_emx_init();

void x_in_TB_logger_init();
