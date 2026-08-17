#include "fir_filter.h"

void fir_filter(data_t *y, data_t x, data_t h[N_TAPS]){
	// #pragma is commands to HLS tools dictating the HW building
	// ap_vld =>> HW assert valid signl when 'y' has new data
	#pragma HLS INTERFACE mode=ap_vld port=y
	#pragma HLS INTERFACE mode=ap_vld port=x

	// Array h uses ap_memory (RAM interface)
	#pragma HLS INTERFACE mode=ap_memory port=h

	// #pragma  HLS INTERFACE =>> port are defined as INTERFACE (not internal wire/signal)
	// "ap_ctrl_hs" Specifies the Control Handshake protocol.
	// This generates dedicated, discrete control signals
	// (ap_start, ap_done, ap_idle, and ap_ready) to control
	// the execution lifecycle of the IP block (or communicate with HW by ext. CPU).
	// "port=return" =>> "not about a (c/c++) data input or data output pin.
	// Its about the control pins that manage the starting and stopping of this entire hardware block.
	#pragma HLS INTERFACE mode=ap_ctrl_hs port=return

	// Shift register for input samples
	// static = the values in the variable stays
	// between function call (accessible outside the function)
	// HLS Synthesize this as hardware registers
	// (or RAM) that retain state across clock cycles.
	static data_t shift_reg[N_TAPS];

	// "type=complete" =>> break array into registers to access all components simultaneously
	// without this HLS might use a RAM or the values clould be read one per cycle.
	#pragma HLS ARRAY_PARTITION variable=shift_reg complete

	// SHIFT: move old samples right
	// Shift in new sample (MSD-first: tap[3] gets newest)
	//SHIFT:	// naming of the following for loop
	// i>0 =>> shift_reg[0] ignored in the loop (keep for newest data)
	#pragma HLS UNROLL
	for (int i = N_TAPS-1; i > 0; i--){
		// copy the loop body multiple times (to do the iteration done in parallel)
		// without this this for loop will take 'N_TAPS-1' clock cycle.
	//	#pragma HLS UNROLL
		shift_reg[i] = shift_reg[i-1];
	}
	shift_reg[0] = x;	// load new sample

	// MAC: sum of products
	// Use UNROLL (not PIPELINE) because each iteration depends on 'acc'
	// Pipelinig to reduce clock cycles
	// II (Initiation Interval) =>> loop iteration delay times
	// (II=1, new iteration every clock cycle)
	// #pragma HLS PIPELINE II=1

	acc_t acc = 0;
	//MAC:
	#pragma HLS UNROLL
	for (int i = 0; i < N_TAPS; i++){
	//	#pragma HLS UNROLL
		acc += shift_reg[i] * h[i];
	}
	*y = acc;
}
