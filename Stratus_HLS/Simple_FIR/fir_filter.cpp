#include "fir_filter.h"

void fir_filter::filter_thread() {
    // -------------------------------------------------------------
    // 1. HARDWARE RESET INITIALIZATION LAYER
    // -------------------------------------------------------------
    y_vld.write(false);
    y.write(0.0);

    HLS_FLATTEN_ARRAY(shift_reg);
    for (int i = 0; i < N_TAPS; i++) {
        shift_reg[i] = 0.0;
    }
    wait();

    // -------------------------------------------------------------
    // 2. CONTINUOUS HARDWARE EXECUTION LOOP
    // -------------------------------------------------------------
    while (true) {
        // Upstream stall logic check
        if (!x_vld.read()) {
            y_vld.write(false);
            wait();
            continue;
        }

        // CRITICAL FIX: The pipeline macro MUST be the very first statement
        // inside the operational block of the loop!
        HLS_PIPELINE_LOOP(SOFT_STALL_PL, 1, "filter_pipeline");

        // Move variable definitions BELOW the pipeline directive
        acc_t acc = 0.0;

        // Unified MAC and register shift loop execution
        for (int i = N_TAPS - 1; i >= 0; i--) {
            if (i == 0) {
                shift_reg[0] = x.read();
            } else {
                shift_reg[i] = shift_reg[i-1];
            }
            acc += shift_reg[i] * h[i].read();
        }

        // Output results to pins
        y.write((data_t)acc);
        y_vld.write(true);

        wait();
    }
}
