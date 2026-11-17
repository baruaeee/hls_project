#pragma once

#include "rtwtypes.h"
#include "signed_to_unsigned_wrapper_fixpt_hdl_mex_types.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void c_signed_to_unsigned_fixpt_logg();

namespace coder {
void b_signed_to_unsigned_fixpt_logg(const emlrtStack &sp, int16_T varargin_1,
                                     uint16_T varargin_2);

void signed_to_unsigned_fixpt_logger(const emlrtStack *sp,
                                     struct0_T *loggedData);

} // namespace coder
void e_in_TB_logger_emx_free();

void e_in_TB_logger_emx_init();

void e_in_TB_logger_init();

void u_out_TB_logger_emx_free();

void u_out_TB_logger_emx_init();

void u_out_TB_logger_init();
