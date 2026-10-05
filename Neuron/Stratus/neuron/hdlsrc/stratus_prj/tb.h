#pragma once

#include "systemc.h"
#include "esc.h"
#include "stratus_hls.h"
#include "cynw_p2p.h"
#include "neuron_fixpt_types.h"
#include "neuron_fixptClass_tb.hpp"

SC_MODULE(tb)
{
 public:
  sc_in< bool >  clk {"clk"};
  sc_out< bool > rst {"rst"};
  sc_in < bool > rst_in {"rst_in"};

  cynw_p2p< ifin_t, ioConfig >::out p_ifin {"p_ifin"};
  cynw_p2p< cynw_fixed <(int)14, (int)-1, (sc_dt::sc_q_mode)5, (sc_dt::sc_o_mode)3, (int)0 >, ioConfig >::in p_ifout {"p_ifout"};
  neuron_fixptClass_tb inst;

  SC_CTOR(tb)
  {
    SC_CTHREAD( source, clk.pos() );
    SC_CTHREAD( sink,   clk.pos() );
    reset_signal_is( rst_in, false );
    rst_in(rst);

    p_ifin.clk_rst( clk, rst_in );
	p_ifout.clk_rst( clk, rst_in );

    ofile.open( "outfile.dat" );
    if( !ofile.is_open() ) {
      cerr << "Unable to open outfile.dat for writing!" << endl;
      esc_stop();
    }
  }

  ~tb() {
    ofile.close();
  }

 private:
  // Local data members of type sc_time, used to keep track of
  // simulation timings (e.g. latency of the DUT). */
  sc_time start_time;

  ofstream ofile;
  void source();
  void sink();
};

