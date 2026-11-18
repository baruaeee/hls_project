#pragma once

#include "rtwtypes.h"
#include "split_quotient_remainder_wrapper_fixpt_hdl_mex_types.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void c_split_quotient_remainder_fixp();

namespace coder {
void e_split_quotient_remainder_fixp(const emlrtStack &sp, uint16_T varargin_1,
                                     uint8_T varargin_2, uint8_T varargin_3,
                                     uint8_T varargin_4);

void split_quotient_remainder_fixpt_logger(const emlrtStack *sp,
                                           struct0_T *loggedData);

} // namespace coder
void k_in_TB_logger_emx_free();

void k_in_TB_logger_emx_init();

void k_in_TB_logger_init();

void q_out_TB_logger_emx_free();

void q_out_TB_logger_emx_init();

void q_out_TB_logger_init();

void r_out_TB_logger_emx_free();

void r_out_TB_logger_emx_init();

void r_out_TB_logger_init();

void u_in_TB_logger_emx_free();

void u_in_TB_logger_emx_init();

void u_in_TB_logger_init();
