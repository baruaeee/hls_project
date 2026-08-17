# 1. Register your simulation verification infrastructure
define_system_module basic_tb tb.cc

# 2. Register your actual synthesizable design component
define_hls_module fir_filter fir_filter.cc

# 3. Setup interface configurations for dual-mode verification (TLM and RTL Pins)
define_io_config fir_filter TLM
define_io_config fir_filter PIN

# 4. Create standard synthesis compilation build targets
define_hls_config fir_filter BASIC
