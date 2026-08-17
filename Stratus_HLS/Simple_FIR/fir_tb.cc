#include "defines.h"
#include <esc.h> // Required Cadence simulation environment control library

int sc_main(int argc, char *argv[]) {
    esc_initialize(argc, argv); // Warm up Cadence simulation configurations

    // System-level simulation clock definition
    sc_clock clk("clk", 10, SC_NS, 0.5);
    sc_signal<bool> rst("rst");

    // Channels to connect Testbench nodes to the DUT
    cynw_p2p<DT_IN>  test_input_channel("in_chan");
    cynw_p2p<DT_OUT> test_output_channel("out_chan");

    // Connect top modules (In a simple scratch build, instantiation goes here)
    // For standard tutorials, this block binds stimulus sources to your filter pins.

    return 0;
}
