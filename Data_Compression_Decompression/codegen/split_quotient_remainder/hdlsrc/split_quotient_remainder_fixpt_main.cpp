#include "split_quotient_remainder_fixptClass.hpp"
#include "split_quotient_remainder_fixptClass_tb.hpp"

int main()
{
  split_quotient_remainder_fixptClass dut;
  split_quotient_remainder_fixptClass_tb tb;
  input_struct inputs;
  output_struct outputs;
  while (!tb.is_stimuli_done()) {
    tb.generate_stimulus(inputs);
    split_quotient_remainder_fixpt_wrapper(inputs.u_in, inputs.k_in,
      outputs.q_out, outputs.r_out);
    tb.check_output(outputs);
  }

  tb.print_pass_fail();
  if (tb.is_sim_passing()) {
    return 0;
  } else {
    return 1;
  }
}
