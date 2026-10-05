#pragma once

#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

struct struct1_T {
  coder::array<int16_T, 2U> x;
  coder::array<uint16_T, 2U> w;
  coder::array<uint8_T, 2U> b;
};

struct struct2_T {
  coder::array<int16_T, 2U> y;
};

struct struct0_T {
  struct1_T inputs;
  struct2_T outputs;
  real_T iterCount;
};
