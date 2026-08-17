// If NOT defined...
#ifndef FIR_FILTER_H
// ...then define it
// after defined if this file included again in another file
// the above condition false and not include twice
#define FIR_FILTER_H


#include <ap_fixed.h>	// Xilings library for fixed point numbers

// 4-tap FIR Filter
// coefficients: simple averaging filter (0.25 0.25 0.25 0.25)

#define N_TAPS 4	// number of sample (4 "taps")
#define DWIDTH 16	// Data Width (each number uses 16 bits)
#define IWIDTH 8	// Integer bits (e.g. 10101010.00000000)

typedef ap_fixed<DWIDTH, IWIDTH> data_t;	// nick name for "ap_fixed<16,8>"
// full precision is DWIDTH*2(for multiplication)+2(for adding 4 taps=log₂(4) = 2), IWIDTH*2+2
// for small taps simple precesion as below enough
typedef ap_fixed<DWIDTH+4, IWIDTH+2> acc_t;	// Wider for accumulation

// y is a pointer and *y it the value stored in the pointed address
// HLS interprets y as an output port
void fir_filter(data_t *y, data_t x, data_t h[N_TAPS]);

#endif
