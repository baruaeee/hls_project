#include "neuron_predictor_fixpt.h"
#include "neuron_predictor_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

void neuron_predictor_fixpt_init()
{
  x_hist_not_empty = false;
}
