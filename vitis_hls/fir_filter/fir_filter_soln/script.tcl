############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project fir_filter
set_top fir_filter
add_files fir_filter.cpp
add_files fir_filter.h
add_files -tb fir_tb.cpp -cflags "-Wno-unknown-pragmas"
open_solution "fir_filter_soln" -flow_target vivado
set_part {xc7z010i-clg225-1L}
create_clock -period 10 -name default
source "./fir_filter/fir_filter_soln/directives.tcl"
csim_design -clean -profile
csynth_design
cosim_design
export_design -format ip_catalog
