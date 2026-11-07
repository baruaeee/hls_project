#include "matrx_mul_fixptClass.hpp"
#include "matrx_mul_fixptClass_tb.hpp"

int main()
{
  matrx_mul_fixptClass dut;
  matrx_mul_fixptClass_tb tb;
  input_struct inputs;
  output_struct outputs;
  while (!tb.is_stimuli_done()) {
    tb.generate_stimulus(inputs);
    matrx_mul_fixpt_wrapper(inputs.x, inputs.w, outputs.y);
    tb.check_output(outputs);
  }

  tb.print_pass_fail();
  if (tb.is_sim_passing()) {
    return 0;
  } else {
    return 1;
  }
}
