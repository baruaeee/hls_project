#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_start", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_done", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_idle", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_ready", 1, hls_out, -1, "", "", 1),
	Port_Property("x_in", 11, hls_in, 0, "ap_none", "in_data", 1),
	Port_Property("reset_rsvd", 1, hls_in, 1, "ap_none", "in_data", 1),
	Port_Property("residual", 14, hls_out, 2, "ap_vld", "out_data", 1),
	Port_Property("residual_ap_vld", 1, hls_out, 2, "ap_vld", "out_vld", 1),
	Port_Property("predicted", 14, hls_out, 3, "ap_vld", "out_data", 1),
	Port_Property("predicted_ap_vld", 1, hls_out, 3, "ap_vld", "out_vld", 1),
};
const char* HLS_Design_Meta::dut_name = "neuron_predictor_fixpt_wrapper";
