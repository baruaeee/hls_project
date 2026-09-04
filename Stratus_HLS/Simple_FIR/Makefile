# =============================================================================
# Cadence Stratus HLS Top-Level Wrapper Makefile
# =============================================================================

# 1. First, tell make where the Cadence configuration rules live
include Makefile.prj

# 2. Add an explicit alias target to resolve your 'config_HLS_B' name mismatch
config_HLS_B: sim_config_HLS_B
config_HLS_V: sim_config_HLS_V

# 3. Standard clean target to refresh the workspace safely
clean:
	rm -rf bdw_work INCA_libs xcelium.d *.log wave.*
