#include "tb.h"

void tb::source()
{
  unsigned long long in_count = 0;
  input_struct ml_in_struct;
  ifin_t ifin_struct;

  p_ifin.reset();
  rst.write( 0 );
  wait(5);
  rst.write( 1 );
  wait();

  bool first_stimulus = true;
  inst.generate_stimulus( ml_in_struct );
  for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
    ifin_struct.x[ndx_0_0] = ml_in_struct.x[ndx_0_0];
  }
  for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
    ifin_struct.w[ndx_0_0] = ml_in_struct.w[ndx_0_0];
  }
  ifin_struct.b = ml_in_struct.b;

  while( !inst.is_stimuli_done() ) {
    // Start time of the first input is recorded to measure the latency.
    if( in_count == 0) {
      start_time = sc_time_stamp();
    }

    // Generate ML tb data
	if( first_stimulus ) {
	  first_stimulus = false;
	} else {
	  inst.generate_stimulus( ml_in_struct );
	  for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
	    ifin_struct.x[ndx_0_0] = ml_in_struct.x[ndx_0_0];
	  }
	  for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
	    ifin_struct.w[ndx_0_0] = ml_in_struct.w[ndx_0_0];
	  }
	  ifin_struct.b = ml_in_struct.b;

	}

    // Send data to neuron_fixpt
    p_ifin.put( ifin_struct );
    in_count++;
  }

  // Wait for sink thread to terminate
  while( true ) {
    p_ifin.put( ifin_struct );
  }
}

void tb::sink()
{
  sc_time current_time, last_time, clock_period;
  double latency, throughput, avg_throughput;
  unsigned long long out_count = 0;

  // First, we need to determine the clock period so we can measure
  // latency in terms of clock cycles. This is accomplished through
  // some SystemC magic code using the "clk" port.

  sc_clock *clk_p = dynamic_cast<sc_clock *>(clk.get_interface());
  clock_period = clk_p->period(); /* get period from the sc_clock object. */

  // reset
  p_ifout.reset();
  wait();
  
  cynw_fixed <(int)14, (int)-1, (sc_dt::sc_q_mode)5, (sc_dt::sc_o_mode)3, (int)0 > y;
  output_struct ml_out_struct;
  
  while( !inst.is_checker_done() ) {
        
    // Wait for neuron_fixpt to produce a value
    y = p_ifout.get();
    ml_out_struct.y = y;

    inst.check_output( ml_out_struct );

    //
    // Check latency
    //
    if (out_count == 0) {
      /* Measure the latency to receive the first output. */
      current_time = sc_time_stamp();
      latency      = (current_time - start_time)/clock_period;
      /* Record the latency in the simulation report. */
      esc_log_latency("neuron_fixpt", (unsigned) latency, "neuron_fixpt_latency");
    } else {
      // measure the throughput (cycles/output) by measuring the time since the last output was received.
      current_time = sc_time_stamp();
      throughput   += (current_time - last_time)/clock_period;
    }
    last_time = current_time;
    out_count++;
  }

  avg_throughput = (throughput / (out_count-1));
  cout << "\nTB: Latency for the first output is " << latency << " cycles.\n";
  cout << "TB: Throughput is " << avg_throughput << " cycles per output.\n\n";

  inst.print_pass_fail();
  if( inst.is_sim_passing() ) {
    esc_log_pass();
  } else {
    esc_log_fail();
  }

  // Sim is now done
  esc_stop();
}

