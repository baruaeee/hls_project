#ifndef TB_H
#define TB_H

#include <systemc.h>
#include "fir_filter.h"

SC_MODULE(tb) {
    sc_in<bool> clk;
    sc_out<bool> rst;
    sc_out<bool> x_vld;
    sc_out<data_t> x;
    sc_in<bool> y_vld;
    sc_in<data_t> y;
    sc_out<data_t> h[N_TAPS];

    void source_process();
    void sink_process();

    SC_CTOR(tb) {
        SC_CTHREAD(source_process, clk.pos());
        SC_CTHREAD(sink_process, clk.pos());
    }
};

#endif
