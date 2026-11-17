set moduleName calc_rice_k_fixpt_wrapper
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
set C_modelName {calc_rice_k_fixpt_wrapper}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
set C_modelArgList {
	{ u_in int 10 regular  }
	{ reset_rsvd uint 1 regular  }
	{ k_out int 4 regular {pointer 1}  }
}
set hasAXIMCache 0
set l_AXIML2Cache [list]
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "u_in", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "reset_rsvd", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "k_out", "interface" : "wire", "bitwidth" : 4, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 10
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ u_in sc_in sc_lv 10 signal 0 } 
	{ reset_rsvd sc_in sc_lv 1 signal 1 } 
	{ k_out sc_out sc_lv 4 signal 2 } 
	{ k_out_ap_vld sc_out sc_logic 1 outvld 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "u_in", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "u_in", "role": "default" }} , 
 	{ "name": "reset_rsvd", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "reset_rsvd", "role": "default" }} , 
 	{ "name": "k_out", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "k_out", "role": "default" }} , 
 	{ "name": "k_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "k_out", "role": "ap_vld" }}  ]}

set ArgLastReadFirstWriteLatency {
	calc_rice_k_fixpt_wrapper {
		u_in {Type I LastRead 0 FirstWrite -1}
		reset_rsvd {Type I LastRead 0 FirstWrite -1}
		k_out {Type O LastRead -1 FirstWrite 1}
		inst_u_hist_not_empty {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_0 {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_1 {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_2 {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_3 {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_4 {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_5 {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_6 {Type IO LastRead -1 FirstWrite -1}
		inst_u_hist_7 {Type IO LastRead -1 FirstWrite -1}
		inst_win_sum {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "1", "Max" : "1"}
	, {"Name" : "Interval", "Min" : "2", "Max" : "2"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	u_in { ap_none {  { u_in in_data 0 10 } } }
	reset_rsvd { ap_none {  { reset_rsvd in_data 0 1 } } }
	k_out { ap_vld {  { k_out out_data 1 4 }  { k_out_ap_vld out_vld 1 1 } } }
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
