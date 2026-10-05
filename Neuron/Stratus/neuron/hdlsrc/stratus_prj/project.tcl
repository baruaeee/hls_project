#
# BDW Project File
#
# This file contains all of the basic options needed to synthesize
# and simulate a BDW project
#

#
# Technology Libraries
#
set LIB_PATH  "[get_install_path]/share/stratus/techlibs/GPDK045/gsclib045_svt_v4.4/gsclib045/timing"
set LIB_LEAF  "slow_vdd1v2_basicCells.lib"
set LEF_LIB   "$LIB_PATH/../lef/gsclib045_tech.lef"
use_tech_lib  "$LIB_PATH/$LIB_LEAF"

use_hls_lib memlib

#
# Basic GCC compiler options
#
set clk_period 100.0
set_attr cc_options "-DCLOCK_PERIOD=${clk_period} -DCLOCK_UNIT=SC_NS "
set_attr hls_cc_options "-DCLOCK_PERIOD=${clk_period} -DCLOCK_UNIT=SC_NS "

#
# Global Stratus command line options
#
set_attr clock_period        $clk_period
set_attr cycle_slack         [expr { $clk_period * 0.20 }]
set_attr default_input_delay [expr { $clk_period * 0.05 }]
set_attr path_delay_limit    113

set_attr unroll_loops        on
set_attr flatten_arrays      all
set_attr balance_expr        delay
set_attr dpopt_auto          op
set_attr rtl_annotation      op,stack
set_attr lsb_trimming        on
set_attr power               on
set_attr ignore_scan_cells   on
set_attr undef_func          error

define_post_elab_tcl {
    report arrays -verbose
}

define_post_sched_tcl {
    report latencies -verbose
    report ops_by_func -verbose
    report ops_by_state -verbose
}

define_post_rtl_tcl {
    report resources -verbose
    report summary -verbose
}

#
# System Modules
#
define_system_module main main.cc
define_io_config main TLM
define_io_config main PIN

define_system_module system system.cc
define_io_config system TLM
define_io_config system PIN

define_system_module tb tb.cc
define_io_config tb TLM
define_io_config tb PIN

define_post_elab_tcl {
    map_arrays_to_spmems {  }
    map_arrays_to_dpmems {  }
}

#
# HLS Modules
#
define_hls_module neuron_fixpt { neuron_fixpt.cc  }
define_io_config neuron_fixpt TLM
define_io_config neuron_fixpt PIN
define_hls_config neuron_fixpt SLOW -DLAT=1000
define_hls_config neuron_fixpt FAST -DLAT=HLS_ACHIEVABLE
define_hls_config neuron_fixpt PIPE -DLAT=HLS_ACHIEVABLE \
    -add_post_elab_tcl { pipeline_default "main" "HARD_STALL" 1 }

#
# Simulation and Power Configurations
#
use_systemc_simulator xcelium
use_verilog_simulator xcelium
enable_waveform_logging -shm

define_sim_config BEH      -io_config TLM
define_sim_config BEH_TLM  -io_config TLM
define_sim_config BEH_PIN  -io_config PIN

foreach config [find -hls_config *] {
    set cname [get_attr name $config]
    if {$cname == "TLM"} { continue }
    if {$cname == "PIN"} { continue }
	
    define_sim_config V_${cname} "neuron_fixpt RTL_V $cname" 
    define_power_config P_${cname} "V_${cname} -frame_count 100" \
		-options \
		[list BDW_LEF_LIB "$LEF_LIB"] \
		{BDW_PWR_PLOT_PWR_OPTS "-stim /stim#1"}
}

#
# Genus Logic Synthesis Configurations
#
define_logic_synthesis_config G {neuron_fixpt -all} \
    -options {BDW_LS_NOGATES 1}

######################################################################
# Micro-architecture Functions
######################################################################

proc dpopt_default {regionName} {
    dpopt_region -flags {NO_ALTS} [find -region $regionName]
}

proc pipeline_default {loopName stallType ii} {
    pipeline_loops -type $stallType -initiation_interval $ii [find -loop $loopName]
}

proc map_arrays_to_spmems { array_list } {
    foreach ar $array_list {
		puts "Mapping $ar to a memory"
		map_to_memory -mem_type "SPRAM" [find -array *${ar}*]
    }
}

proc map_arrays_to_dpmems { array_list } {
    foreach ar $array_list {
		puts "Mapping $ar to a memory"
		map_to_memory -mem_type "DPRAM" [find -array *${ar}*]
		constrain_array_max_distance -max -1 [find -array *${ar}*] [find -loop main]
    }
}

proc initialize_memories {} {
    foreach init_loop [find -loop -within [find -region memory_initialize]] {
		unroll_loops -type OFF $init_loop
    }
}

