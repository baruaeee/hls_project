#include "calc_rice_k_fixptClass.hpp"
#include "calc_rice_k_fixptClass_tb.hpp"

int main()
{
  calc_rice_k_fixptClass dut;
  calc_rice_k_fixptClass_tb tb;
  input_struct inputs;
  output_struct outputs;
  while (!tb.is_stimuli_done()) {
    tb.generate_stimulus(inputs);
    calc_rice_k_fixpt_wrapper(inputs.u_in, inputs.reset_rsvd, outputs.k_out);
    tb.check_output(outputs);
  }

  tb.print_pass_fail();
  if (tb.is_sim_passing()) {
    return 0;
  } else {
    return 1;
  }
}
