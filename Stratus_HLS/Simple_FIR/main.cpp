#include "fir_filter.h"
#include "tb.h"

int sc_main(int argc, char* argv[]) {
    sc_clock clk("clk", 10, SC_NS); // Establish a baseline 10ns clock period
    sc_signal<bool> rst("rst");
    sc_signal<bool> x_vld("x_vld"), y_vld("y_vld");
    sc_signal<data_t> x("x"), y("y");
    sc_signal<data_t> h[N_TAPS];

    fir_filter filter_inst("DUT");
    tb         tb_inst("Vector_Generator");

    // Connect top modules structural ports
    filter_inst.clk(clk); filter_inst.rst(rst);
    filter_inst.x_vld(x_vld); filter_inst.x(x);
    filter_inst.y_vld(y_vld); filter_inst.y(y);
    for(int i=0; i<N_TAPS; i++) filter_inst.h[i](h[i]);

    tb_inst.clk(clk); tb_inst.rst(rst);
    tb_inst.x_vld(x_vld); tb_inst.x(x);
    tb_inst.y_vld(y_vld); tb_inst.y(y);
    for(int i=0; i<N_TAPS; i++) tb_inst.h[i](h[i]);

    sc_start(); // Trigger behavioral simulation loop
    return 0;
}
