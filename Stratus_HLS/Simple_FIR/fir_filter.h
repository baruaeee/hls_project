#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#include "defines.h"
#include "cynw_p2p.h" // Cadence point-to-point handshake streaming library

SC_MODULE(fir_filter) {
    // Standard hardware control pins
    sc_in_clk SC_NAMED(clk);
    sc_in<bool> SC_NAMED(rst);

    // Synthesizable I/O using Cadence's streaming protocol
    cynw_p2p<DT_IN>::in   SC_NAMED(din);  // Stream input channel
    cynw_p2p<DT_OUT>::out SC_NAMED(dout); // Stream output channel

    void filter_thread();

    SC_CTOR(fir_filter) {
        SC_CTHREAD(filter_thread, clk.pos());
        reset_signal_is(rst, 0); // Active low reset (matching Cadence default)

        // MANDATORY PER MANUAL: Bind clock and reset to your streaming interfaces
        din.clk_rst(clk, rst);
        dout.clk_rst(clk, rst);
    }
};

#endif // FIR_FILTER_H
