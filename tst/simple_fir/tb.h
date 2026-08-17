///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2024 Cadence Design Systems, Inc. All rights reserved worldwide.
//
// The code contained herein is the proprietary and confidential information
// of Cadence or its licensors, and is supplied subject to a previously
// executed license and maintenance agreement between Cadence and customer.
// This code is intended for use with Cadence high-level synthesis tools and
// may not be used with other high-level synthesis tools. Permission is only
// granted to distribute the code as indicated. Cadence grants permission for
// customer to distribute a copy of this code to any partner to aid in designing
// or verifying the customer's intellectual property, as long as such
// distribution includes a restriction of no additional distributions from the
// partner, unless the partner receives permission directly from Cadence.
//
// ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT,
// FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE
// LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS,
// INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR
// INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY,
// CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _TB_H_
#define _TB_H_

#include <cynw_p2p.h>           // This also includes systemc.h etc
#include "defines.h"            // The type definitions for the input and output

SC_MODULE(tb)
{
public:
    // Declare clock and reset ports
    sc_in_clk SC_NAMED(clk);
    sc_in < bool > SC_NAMED(rst);

    sc_out < std::array<sc_uint<8>,8> > SC_NAMED(coeffs);

    // Declare modular interface ports
    cynw_p2p < input_t >::out SC_NAMED(dout);    // data going in to the design
    cynw_p2p < output_t >::in SC_NAMED(din); // data going out of the design

  SC_CTOR(tb)
    {
        // Declare the source thread. Since it drives the reset signal,
        // no reset_signal_is() is needed for the source thread
        SC_CTHREAD(source, clk.pos());
        reset_signal_is(rst, 0); // active low

        // Declare the sink thread
        SC_CTHREAD(sink, clk.pos());
        reset_signal_is(rst, 0); // active low

        // connect clk/rst to cynw_p2p ports
        din.clk_rst(clk, rst);
        dout.clk_rst(clk, rst);
    }
  private:
    // Class data member of type sc_time, used to keep track of
    // simulation timings (e.g. latency of the DUT).
    sc_time sample_sent_time;

    void source();
    void sink();

    ifstream stim_file;         // File stream for reading the stimulus
    ofstream resp_file;         // File stream for writing the responses

    // Utility functions for managing the stimulus file
    void open_stimulus_file(const char *_name = NULL);
    input_t read_stimulus_value(bool & eof);
    void close_stimulus_file();

    // Utility functions for managing the response file
    void open_response_file(const char *_name = NULL);
    void write_response_value(output_t);
    void close_response_file();

    // Utility function for managing the golden file
    int count_golden_file(const char *_name = NULL);

    // Utility to convert a time in simulation time units to clock cycles
    int clock_cycle(sc_time time);
};

#endif // _TB_H_
