#pragma once

#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

struct struct1_T {
  coder::array<int16_T, 3U> x;
  coder::array<uint16_T, 3U> w;
};

struct struct2_T {
  coder::array<int16_T, 3U> y;
};

struct struct0_T {
  struct1_T inputs;
  struct2_T outputs;
  real_T iterCount;
};
