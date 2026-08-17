#include "fir_filter.h"

void fir_filter::filter_thread() {
    // Local internal hardware arrays
    DT_IN shift_reg[N_TAPS];
    DT_IN coeffs[N_TAPS] = {1, 2, 2, 1}; // Example filter coefficients

    // MANDATORY PER MANUAL: Initialize all variables prior to the first wait()
    {
        HLS_PROTOCOL("reset");
        din.reset();   // Safely clears input validation channels
        dout.reset();  // De-asserts valid lines until output data is ready

        for (int i = 0; i < N_TAPS; i++) {
            shift_reg[i] = 0;
        }
        wait(); // Halts execution until reset is fully released by the chip
    }

    // Continuous Math Loop
    while (1) {
        // Read data using blocking get()
        DT_IN in_val = din.get();

        // Shift register update
        for (int i = N_TAPS - 1; i > 0; i--) {
            shift_reg[i] = shift_reg[i - 1];
        }
        shift_reg[0] = in_val;

        // Multiply-Accumulate block
        DT_OUT acc = 0;
        for (int i = 0; i < N_TAPS; i++) {
            acc += shift_reg[i] * coeffs[i];
        }

        // Output data using blocking put()
        dout.put(acc);
    }
}
