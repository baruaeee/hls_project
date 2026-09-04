###############################################################################
# 1. Technology Library Configuration (From your sample template)
###############################################################################
# set LIB_PATH "[get_install_path]/share/stratus/techlibs/GPDK045/gsclib045_svt_v4.4/gsclib045/timing"
# use_tech_lib "$LIB_PATH/slow_vdd1v2_basicCells.lib"

use_tech_lib "$env(GPDK)/gsclib045/timing/slow_vdd1v2_basicCells.lib"

###############################################################################
# 2. Global Compiler and Timing Settings
###############################################################################
set CLOCK_PERIOD 10.0
set_attr clock_period         $CLOCK_PERIOD
set_attr cycle_slack          [expr 0.10 * $CLOCK_PERIOD]
set_attr default_input_delay  2.0

# Sensible starting point project optimizations from your sample
set_attr message_detail       1
set_attr verilog_dialect      systemverilog
set_attr flatten_arrays       all
# Correct Syntax: unroll_loops must be a boolean switch (on | off)
set_attr unroll_loops         on


###############################################################################
# 3. Testbench System Level Modules (Listed individually per sample)
###############################################################################
define_system_module main main.cpp
define_system_module tb tb.cpp

###############################################################################
# 4. SC_MODULE to be Synthesized
###############################################################################
define_hls_module fir_filter fir_filter.cpp

# Declare HLS macro configuration layer explicitly
define_hls_config fir_filter config_HLS

###############################################################################
# 5. Simulation Verification Configurations (Using sample foreach mapping loop)
###############################################################################
use_systemc_simulator builtin
use_verilog_simulator xcelium
enable_waveform_logging -vcd

# This loops over all hls_configs and automatically builds your simulation targets:
# It creates 'config_HLS_B' for behavioral and 'config_HLS_V' for Verilog RTL
foreach config [find -hls_config *] {
  set cname [get_attr name $config]
  define_sim_config ${cname}_B "fir_filter BEH $cname"
  define_sim_config ${cname}_V "fir_filter RTL_V $cname"
}
