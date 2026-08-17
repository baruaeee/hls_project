set moduleName fir_filter
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type function
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {fir_filter}
set C_modelType { void 0 }
set C_modelArgList {
	{ y int 16 regular {pointer 1}  }
	{ x int 16 regular  }
	{ h_0 int 16 regular {pointer 0}  }
	{ h_1 int 16 regular {pointer 0}  }
	{ h_2 int 16 regular {pointer 0}  }
	{ h_3 int 16 regular {pointer 0}  }
}
set hasAXIMCache 0
set C_modelArgMapList {[ 
	{ "Name" : "y", "interface" : "wire", "bitwidth" : 16, "direction" : "WRITEONLY"} , 
 	{ "Name" : "x", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "h_0", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "h_1", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "h_2", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "h_3", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 14
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ x_ap_vld sc_in sc_logic 1 invld 1 } 
	{ y sc_out sc_lv 16 signal 0 } 
	{ y_ap_vld sc_out sc_logic 1 outvld 0 } 
	{ x sc_in sc_lv 16 signal 1 } 
	{ h_0 sc_in sc_lv 16 signal 2 } 
	{ h_1 sc_in sc_lv 16 signal 3 } 
	{ h_2 sc_in sc_lv 16 signal 4 } 
	{ h_3 sc_in sc_lv 16 signal 5 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "x_ap_vld", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "x", "role": "ap_vld" }} , 
 	{ "name": "y", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "y", "role": "default" }} , 
 	{ "name": "y_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "y", "role": "ap_vld" }} , 
 	{ "name": "x", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "x", "role": "default" }} , 
 	{ "name": "h_0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "h_0", "role": "default" }} , 
 	{ "name": "h_1", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "h_1", "role": "default" }} , 
 	{ "name": "h_2", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "h_2", "role": "default" }} , 
 	{ "name": "h_3", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "h_3", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4"],
		"CDFG" : "fir_filter",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "5", "EstimateLatencyMin" : "5", "EstimateLatencyMax" : "5",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "y", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "x", "Type" : "Vld", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "x_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "h_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "h_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "h_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "h_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "fir_filter_ap_fixed_ap_fixed_ap_fixed_16_8_5_3_0_shift_reg", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "fir_filter_ap_fixed_ap_fixed_ap_fixed_16_8_5_3_0_shift_reg_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "fir_filter_ap_fixed_ap_fixed_ap_fixed_16_8_5_3_0_shift_reg_2", "Type" : "OVld", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_16s_16s_24_1_1_U1", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_16s_16s_24ns_24_4_1_U2", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_16s_16s_24ns_24_4_1_U3", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_16s_16s_24ns_24_4_1_U4", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fir_filter {
		y {Type O LastRead -1 FirstWrite 5}
		x {Type I LastRead 0 FirstWrite -1}
		h_0 {Type I LastRead 0 FirstWrite -1}
		h_1 {Type I LastRead 0 FirstWrite -1}
		h_2 {Type I LastRead 0 FirstWrite -1}
		h_3 {Type I LastRead 0 FirstWrite -1}
		fir_filter_ap_fixed_ap_fixed_ap_fixed_16_8_5_3_0_shift_reg {Type IO LastRead -1 FirstWrite -1}
		fir_filter_ap_fixed_ap_fixed_ap_fixed_16_8_5_3_0_shift_reg_1 {Type IO LastRead -1 FirstWrite -1}
		fir_filter_ap_fixed_ap_fixed_ap_fixed_16_8_5_3_0_shift_reg_2 {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "5", "Max" : "5"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	y { ap_vld {  { y out_data 1 16 }  { y_ap_vld out_vld 1 1 } } }
	x { ap_vld {  { x_ap_vld in_vld 0 1 }  { x in_data 0 16 } } }
	h_0 { ap_none {  { h_0 in_data 0 16 } } }
	h_1 { ap_none {  { h_1 in_data 0 16 } } }
	h_2 { ap_none {  { h_2 in_data 0 16 } } }
	h_3 { ap_none {  { h_3 in_data 0 16 } } }
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
