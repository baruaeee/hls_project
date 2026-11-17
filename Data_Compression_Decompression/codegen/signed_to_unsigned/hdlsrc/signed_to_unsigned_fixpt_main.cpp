#include "signed_to_unsigned_fixptClass.hpp"
#include "signed_to_unsigned_fixptClass_tb.hpp"

int main()
{
  signed_to_unsigned_fixptClass dut;
  signed_to_unsigned_fixptClass_tb tb;
  input_struct inputs;
  output_struct outputs;
  while (!tb.is_stimuli_done()) {
    tb.generate_stimulus(inputs);
    signed_to_unsigned_fixpt_wrapper(inputs.e_in, outputs.u_out);
    tb.check_output(outputs);
  }

  tb.print_pass_fail();
  if (tb.is_sim_passing()) {
    return 0;
  } else {
    return 1;
  }
}
