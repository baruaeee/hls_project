set SynModuleInfo {
  {SRCNAME fir_filter MODELNAME fir_filter RTLNAME fir_filter IS_TOP 1
    SUBMODULES {
      {MODELNAME fir_filter_mul_16s_16s_24_1_1 RTLNAME fir_filter_mul_16s_16s_24_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME fir_filter_mac_muladd_16s_16s_24ns_24_4_1 RTLNAME fir_filter_mac_muladd_16s_16s_24ns_24_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
    }
  }
}
