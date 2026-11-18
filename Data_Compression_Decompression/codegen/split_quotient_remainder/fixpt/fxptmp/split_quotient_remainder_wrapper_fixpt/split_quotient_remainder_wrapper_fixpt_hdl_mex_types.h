#pragma once

#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

struct struct1_T {
  coder::array<uint16_T, 2U> u_in;
  coder::array<uint8_T, 2U> k_in;
};

struct struct2_T {
  coder::array<uint8_T, 2U> q_out;
  coder::array<uint8_T, 2U> r_out;
};

struct struct0_T {
  struct1_T inputs;
  struct2_T outputs;
  real_T iterCount;
};
