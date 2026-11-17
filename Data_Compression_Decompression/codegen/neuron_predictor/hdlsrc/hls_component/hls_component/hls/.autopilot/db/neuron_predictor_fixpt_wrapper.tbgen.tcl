set moduleName neuron_predictor_fixpt_wrapper
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set isPipelined_legacy 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set restart_counter_num 0
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set svuvm_can_support 1
set cdfgNum 2
set C_modelName {neuron_predictor_fixpt_wrapper}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
set C_modelArgList {
	{ x_in int 11 regular  }
	{ reset_rsvd uint 1 regular  }
	{ residual int 10 regular {pointer 1}  }
	{ predicted int 12 regular {pointer 1}  }
}
set hasAXIMCache 0
set l_AXIML2Cache [list]
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "x_in", "interface" : "wire", "bitwidth" : 11, "direction" : "READONLY"} , 
 	{ "Name" : "reset_rsvd", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "residual", "interface" : "wire", "bitwidth" : 10, "direction" : "WRITEONLY"} , 
 	{ "Name" : "predicted", "interface" : "wire", "bitwidth" : 12, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 12
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ x_in sc_in sc_lv 11 signal 0 } 
	{ reset_rsvd sc_in sc_lv 1 signal 1 } 
	{ residual sc_out sc_lv 10 signal 2 } 
	{ residual_ap_vld sc_out sc_logic 1 outvld 2 } 
	{ predicted sc_out sc_lv 12 signal 3 } 
	{ predicted_ap_vld sc_out sc_logic 1 outvld 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "x_in", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "x_in", "role": "default" }} , 
 	{ "name": "reset_rsvd", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "reset_rsvd", "role": "default" }} , 
 	{ "name": "residual", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "residual", "role": "default" }} , 
 	{ "name": "residual_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "residual", "role": "ap_vld" }} , 
 	{ "name": "predicted", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "predicted", "role": "default" }} , 
 	{ "name": "predicted_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "predicted", "role": "ap_vld" }}  ]}

set ArgLastReadFirstWriteLatency {
	neuron_predictor_fixpt_wrapper {
		x_in {Type I LastRead 0 FirstWrite -1}
		reset_rsvd {Type I LastRead 0 FirstWrite -1}
		residual {Type O LastRead -1 FirstWrite 2}
		predicted {Type O LastRead -1 FirstWrite 2}
		inst_x_hist_not_empty {Type IO LastRead -1 FirstWrite -1}
		inst_x_hist_0 {Type IO LastRead -1 FirstWrite -1}
		inst_x_hist_1 {Type IO LastRead -1 FirstWrite -1}
		inst_x_hist_2 {Type IO LastRead -1 FirstWrite -1}
		inst_x_hist_3 {Type IO LastRead -1 FirstWrite -1}
		inst_w_1 {Type IO LastRead -1 FirstWrite -1}
		inst_w_2 {Type IO LastRead -1 FirstWrite -1}
		inst_w_3 {Type IO LastRead -1 FirstWrite -1}
		inst_w_0 {Type IO LastRead -1 FirstWrite -1}
		inst_b {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "3", "Max" : "3"}
	, {"Name" : "Interval", "Min" : "4", "Max" : "4"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	x_in { ap_none {  { x_in in_data 0 11 } } }
	reset_rsvd { ap_none {  { reset_rsvd in_data 0 1 } } }
	residual { ap_vld {  { residual out_data 1 10 }  { residual_ap_vld out_vld 1 1 } } }
	predicted { ap_vld {  { predicted out_data 1 12 }  { predicted_ap_vld out_vld 1 1 } } }
}

set maxi_interface_dict [dict create]

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
