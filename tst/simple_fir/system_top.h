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

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <systemc.h>
#include <cynw_p2p.h>
#include "defines.h"
#include "tb.h"

#include "fir_wrap.h"           // use the generated wrapper for all hls_modules


SC_MODULE(system_top)
{
public:
    // clock and reset signals
    sc_clock SC_NAMED(clk_sig, CLOCK_PERIOD, SC_NS, 0.5, 0, SC_NS, true);
    sc_signal < bool > SC_NAMED(rst_sig);

    // cynw_p2p channels
    cynw_p2p < input_t >::chan SC_NAMED(chan1);
    cynw_p2p < output_t >::chan SC_NAMED(chan2);

    // The stable coefficients
    sc_signal < std::array<sc_uint<8>,8> > SC_NAMED(coeffs_sig);

    // The testbench and fir modules
    fir_wrapper *m_fir;         // use the generated wrapper for all hls_modules
    tb *m_tb;

  SC_CTOR(system_top)
    {
        m_fir = new fir_wrapper("fir_wrapper");

        // Connect the design module
        m_fir->clk.bind(clk_sig);
        m_fir->rst.bind(rst_sig);
        m_fir->coeffs.bind(coeffs_sig);
        m_fir->din.bind(chan1);
        m_fir->dout.bind(chan2);

        // Connect the testbench
        m_tb = new tb("tb");
        m_tb->clk.bind(clk_sig);
        m_tb->rst.bind(rst_sig);
        m_tb->coeffs.bind(coeffs_sig);
        m_tb->dout.bind(chan1);
        m_tb->din.bind(chan2);

        SC_THREAD(gen_rst);
    }

    ~system_top()
    {
        delete m_tb;
        delete m_fir;
    }

  // This thread generates the reset signal
  void gen_rst()
  {
      rst_sig.write(0);           // assert reset (active low)
      wait( clk_sig.posedge_event() );
      wait( clk_sig.posedge_event() );
      rst_sig.write(1);           // deassert reset

      // No more behavior in this thread
  }
};

#endif // _SYSTEM_H_
