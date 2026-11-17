#include "neuron_predictor_fixptClass.hpp"
#include "neuron_predictor_fixptClass_tb.hpp"

int main()
{
  neuron_predictor_fixptClass dut;
  neuron_predictor_fixptClass_tb tb;
  input_struct inputs;
  output_struct outputs;
  while (!tb.is_stimuli_done()) {
    tb.generate_stimulus(inputs);
    neuron_predictor_fixpt_wrapper(inputs.x_in, inputs.reset_rsvd,
      outputs.residual, outputs.predicted);
    tb.check_output(outputs);
  }

  tb.print_pass_fail();
  if (tb.is_sim_passing()) {
    return 0;
  } else {
    return 1;
  }
}
