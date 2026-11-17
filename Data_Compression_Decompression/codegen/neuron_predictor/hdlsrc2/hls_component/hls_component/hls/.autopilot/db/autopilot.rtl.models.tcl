set SynModuleInfo {
  {SRCNAME neuron_predictor_fixpt MODELNAME neuron_predictor_fixpt RTLNAME neuron_predictor_fixpt_wrapper_neuron_predictor_fixpt
    SUBMODULES {
      {MODELNAME neuron_predictor_fixpt_wrapper_mul_11s_10s_21_1_1 RTLNAME neuron_predictor_fixpt_wrapper_mul_11s_10s_21_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME neuron_predictor_fixpt_wrapper_mac_muladd_14s_11s_13s_24_2_1 RTLNAME neuron_predictor_fixpt_wrapper_mac_muladd_14s_11s_13s_24_2_1 BINDTYPE op TYPE all IMPL dsp_slice LATENCY 1}
      {MODELNAME neuron_predictor_fixpt_wrapper_mac_muladd_14s_11s_24s_24_2_1 RTLNAME neuron_predictor_fixpt_wrapper_mac_muladd_14s_11s_24s_24_2_1 BINDTYPE op TYPE all IMPL dsp_slice LATENCY 1}
      {MODELNAME neuron_predictor_fixpt_wrapper_mac_muladd_14s_11s_24s_24_1_1 RTLNAME neuron_predictor_fixpt_wrapper_mac_muladd_14s_11s_24s_24_1_1 BINDTYPE op TYPE all IMPL dsp_slice LATENCY 0}
    }
  }
  {SRCNAME neuron_predictor_fixpt_wrapper MODELNAME neuron_predictor_fixpt_wrapper RTLNAME neuron_predictor_fixpt_wrapper IS_TOP 1}
}
