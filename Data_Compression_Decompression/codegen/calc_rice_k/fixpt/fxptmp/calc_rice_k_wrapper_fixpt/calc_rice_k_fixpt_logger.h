#pragma once

#include "calc_rice_k_wrapper_fixpt_hdl_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void calc_rice_k_fixpt_logger_init();

namespace coder {
void b_calc_rice_k_fixpt_logger(const emlrtStack &sp, uint16_T varargin_1,
                                boolean_T varargin_2, uint8_T varargin_3);

void calc_rice_k_fixpt_logger(const emlrtStack *sp, struct0_T *loggedData);

} // namespace coder
void k_out_TB_logger_emx_free();

void k_out_TB_logger_emx_init();

void k_out_TB_logger_init();

void reset_TB_logger_emx_free();

void reset_TB_logger_emx_init();

void reset_TB_logger_init();

void u_in_TB_logger_emx_free();

void u_in_TB_logger_emx_init();

void u_in_TB_logger_init();
