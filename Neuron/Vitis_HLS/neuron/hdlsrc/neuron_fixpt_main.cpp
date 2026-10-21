#include "neuron_fixptClass.hpp"
#include "neuron_fixptClass_tb.hpp"

int main()
{
  neuron_fixptClass dut;
  neuron_fixptClass_tb tb;
  input_struct inputs;
  output_struct outputs;
  while (!tb.is_stimuli_done()) {
    tb.generate_stimulus(inputs);
    neuron_fixpt_wrapper(inputs.x, inputs.w, inputs.b, outputs.y);
    tb.check_output(outputs);
  }

  tb.print_pass_fail();
  if (tb.is_sim_passing()) {
    return 0;
  } else {
    return 1;
  }
}
