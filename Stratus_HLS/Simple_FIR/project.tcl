###############################################################################
# 1. Technology Library Configuration
###############################################################################

## This maps the technology baseline constraints.
# set LIB_PATH "[get_install_path]/share/stratus/techlibs/GPDK045/gsclib045_svt_v4.4/gsclib045/timing"
# use_tech_lib "$LIB_PATH/slow_vdd1v2_basicCells.lib"

use_tech_lib "$env(GPDK)/gsclib045/timing/slow_vdd1v2_basicCells.lib"

###############################################################################
# 2. Global Compiler and Timing Settings
###############################################################################

#Sets a target execution window of 10.0 ns (equal to a 100 MHz system execution frequency target).
set CLOCK_PERIOD 10.0
set_attr clock_period         $CLOCK_PERIOD

# Instructs the structural compiler to set aside 1.0 ns of clock cycle as a safety boundary matrix.
# This forces Stratus to calculate all internal pipeline routes to complete processing
# within 9.0 ns (10.0ns - 1.0ns slack), giving downstream placement and routing tool (Innovus)
# enough breathing room to correct for wire parasitic clock delays later.
set_attr cycle_slack          [expr 0.10 * $CLOCK_PERIOD]

# Assumes that input signals arriving from outside the chip boundaries arrive up to 2.0 ns late.
# This limits the internal input combinational logic paths to 7.0 ns before hitting the first register step.
set_attr default_input_delay  2.0

# Sensible starting point project optimizations from sample
set_attr message_detail       1
set_attr verilog_dialect      systemverilog

##  Compiler Global Optimization Switches
###############################################################################

# Instructs the compilation engine to unpack all internal arrays into standalone, independent hardware registers.
# For the FIR filter delay line, it forces the tool to create separate, dedicated parallel flip-flop registers
# instead of synthesizing a sequential, bottlenecked RAM storage block.
set_attr flatten_arrays       all
# Forces the compiler to expand the hardware loops completely. Instead of building a single shared
# Multiplier-Accumulator (MAC) block that loops sequentially over the filter coefficients,
# it duplicates the physical multiplier hardware arrays so all taps are processed simultaneously
# in a single clock cycle.
# Correct Syntax: unroll_loops must be a boolean switch (on | off)
set_attr unroll_loops         on


###############################################################################
# 3. Testbench System Level Modules (Listed individually per sample)
###############################################################################

# Design and Verification Space Setup
# Distinguishes non-synthesizable verification logic (main and tb) from the true physical design
# target module fir_filter.
define_system_module main main.cpp
define_system_module tb tb.cpp

###############################################################################
# 4. SC_MODULE to be Synthesized
###############################################################################

# Define the HDL top module name
define_hls_module fir_filter fir_filter.cpp

# Declare HLS macro configuration layer explicitly
# Creates a named workspace container configuration footprint layout (config_HLS).
# This allows to run different design space exploration passes
# (e.g., a config_Area with loop unrolling turned off can be created to compare metrics later).
define_hls_config fir_filter config_HLS

###############################################################################
# 5. Simulation Verification Configurations (Using sample foreach mapping loop)
###############################################################################
use_systemc_simulator builtin
use_verilog_simulator xcelium
enable_waveform_logging -vcd

# Verification Configuration Automation Loop
# This loops over all hls_configs and automatically builds the simulation targets:
# It creates 'config_HLS_B' for behavioral and 'config_HLS_V' for Verilog RTL
foreach config [find -hls_config *] {
  set cname [get_attr name $config]
  define_sim_config ${cname}_B "fir_filter BEH $cname"
  define_sim_config ${cname}_V "fir_filter RTL_V $cname"
}
