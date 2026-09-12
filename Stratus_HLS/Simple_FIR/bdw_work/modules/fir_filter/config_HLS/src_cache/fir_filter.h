#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#include <systemc.h>
#include <cynw_fixed.h>

#define N_TAPS 4
#define DWIDTH 16
#define IWIDTH 8

// Correct Cadence/SystemC names for rounding and saturation modes
typedef cynw_fixed<DWIDTH, IWIDTH, sc_dt::SC_RND, sc_dt::SC_SAT> data_t;
typedef cynw_fixed<DWIDTH+4, IWIDTH+2, sc_dt::SC_RND, sc_dt::SC_SAT> acc_t;

SC_MODULE(fir_filter) {
    // Clock and Reset Signals
    sc_in<bool> clk;
    sc_in<bool> rst;

    // Handshake Interface Ports
    sc_in<bool>   x_vld;
    sc_in<data_t> x;
    sc_out<bool>  y_vld;
    sc_out<data_t> y;

    // Direct Wire Coefficients Interface
    sc_in<data_t> h[N_TAPS];

    // Internal pipeline storage registers
    data_t shift_reg[N_TAPS];

    // Core execution process thread
    void filter_thread();

    SC_CTOR(fir_filter) {
        SC_CTHREAD(filter_thread, clk.pos());
        // In Stratus SC_CTHREADs, asynchronous reset is declared implicitly
        // using the built-in systemc reset_signal_is wrapper
        reset_signal_is(rst, false); // Active-low reset matching standard configurations
    }
};

#endif
