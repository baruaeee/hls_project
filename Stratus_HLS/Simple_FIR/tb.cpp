#include "tb.h"

void tb::source_process() {
    // Instantiate filter averaging coefficients
    for(int i = 0; i < N_TAPS; i++) h[i].write(0.25);

    x.write(0.0);
    x_vld.write(false);
    rst.write(true);  // Activate hardware reset
    wait(2);
    rst.write(false); // Release reset
    wait();

    // Pulse Stream: Vector generation test sequence
    for (int i = 0; i < 10; i++) {
        x_vld.write(true);
        if (i == 3) x.write(1.0); // Pulse value matching your main.cpp
        else        x.write(0.0);
        wait();
    }
    x_vld.write(false);
    wait(10);
    sc_stop(); // Safe SystemC termination command
}

void tb::sink_process() {
    while(true) {
        if (y_vld.read()) {
            cout << "Input Stream Cycle Data Output: " << y.read().to_double() << endl;
        }
        wait();
    }
}
