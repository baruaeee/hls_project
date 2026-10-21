set moduleName neuron_fixpt_wrapper
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
set C_modelName {neuron_fixpt_wrapper}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
set C_modelArgList {
	{ x_0 int 14 regular {pointer 0}  }
	{ x_1 int 14 regular {pointer 0}  }
	{ x_2 int 14 regular {pointer 0}  }
	{ x_3 int 14 regular {pointer 0}  }
	{ w_0 int 14 regular {pointer 0}  }
	{ w_1 int 14 regular {pointer 0}  }
	{ w_2 int 14 regular {pointer 0}  }
	{ w_3 int 14 regular {pointer 0}  }
	{ b int 1 unused  }
	{ y int 14 regular {pointer 1}  }
}
set hasAXIMCache 0
set l_AXIML2Cache [list]
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "x_0", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "x_1", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "x_2", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "x_3", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "w_0", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "w_1", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "w_2", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "w_3", "interface" : "wire", "bitwidth" : 14, "direction" : "READONLY"} , 
 	{ "Name" : "b", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "y", "interface" : "wire", "bitwidth" : 14, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 17
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ x_0 sc_in sc_lv 14 signal 0 } 
	{ x_1 sc_in sc_lv 14 signal 1 } 
	{ x_2 sc_in sc_lv 14 signal 2 } 
	{ x_3 sc_in sc_lv 14 signal 3 } 
	{ w_0 sc_in sc_lv 14 signal 4 } 
	{ w_1 sc_in sc_lv 14 signal 5 } 
	{ w_2 sc_in sc_lv 14 signal 6 } 
	{ w_3 sc_in sc_lv 14 signal 7 } 
	{ b sc_in sc_lv 1 signal 8 } 
	{ y sc_out sc_lv 14 signal 9 } 
	{ y_ap_vld sc_out sc_logic 1 outvld 9 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "x_0", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "x_0", "role": "default" }} , 
 	{ "name": "x_1", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "x_1", "role": "default" }} , 
 	{ "name": "x_2", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "x_2", "role": "default" }} , 
 	{ "name": "x_3", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "x_3", "role": "default" }} , 
 	{ "name": "w_0", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "w_0", "role": "default" }} , 
 	{ "name": "w_1", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "w_1", "role": "default" }} , 
 	{ "name": "w_2", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "w_2", "role": "default" }} , 
 	{ "name": "w_3", "direction": "in", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "w_3", "role": "default" }} , 
 	{ "name": "b", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "b", "role": "default" }} , 
 	{ "name": "y", "direction": "out", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "y", "role": "default" }} , 
 	{ "name": "y_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "y", "role": "ap_vld" }}  ]}

set ArgLastReadFirstWriteLatency {
	neuron_fixpt_wrapper {
		x_0 {Type I LastRead 0 FirstWrite -1}
		x_1 {Type I LastRead 0 FirstWrite -1}
		x_2 {Type I LastRead 0 FirstWrite -1}
		x_3 {Type I LastRead 0 FirstWrite -1}
		w_0 {Type I LastRead 0 FirstWrite -1}
		w_1 {Type I LastRead 0 FirstWrite -1}
		w_2 {Type I LastRead 0 FirstWrite -1}
		w_3 {Type I LastRead 0 FirstWrite -1}
		b {Type I LastRead -1 FirstWrite -1}
		y {Type O LastRead -1 FirstWrite 1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "1", "Max" : "1"}
	, {"Name" : "Interval", "Min" : "2", "Max" : "2"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	x_0 { ap_none {  { x_0 in_data 0 14 } } }
	x_1 { ap_none {  { x_1 in_data 0 14 } } }
	x_2 { ap_none {  { x_2 in_data 0 14 } } }
	x_3 { ap_none {  { x_3 in_data 0 14 } } }
	w_0 { ap_none {  { w_0 in_data 0 14 } } }
	w_1 { ap_none {  { w_1 in_data 0 14 } } }
	w_2 { ap_none {  { w_2 in_data 0 14 } } }
	w_3 { ap_none {  { w_3 in_data 0 14 } } }
	b { ap_none {  { b in_data 0 1 } } }
	y { ap_vld {  { y out_data 1 14 }  { y_ap_vld out_vld 1 1 } } }
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
