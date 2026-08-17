#ifndef DEFINES_H
#define DEFINES_H

#include <systemc.h>
#include <ac_fixed.h>

#define N_TAPS 4

// Custom data types
typedef ac_fixed<16, 8, true> DT_IN;   // 16-bit input
typedef ac_fixed<20, 10, true> DT_OUT; // 20-bit accumulator output

#endif // DEFINES_H
