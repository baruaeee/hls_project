# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
# Tool Version Limit: 2023.05
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__SIM_MATHHLS__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

__USE_CLANG__ = 1

ObjDir = obj

HLS_SOURCES = ../../../../fir_tb.cpp ../../../../fir_filter.cpp

override TARGET := csim.exe

AUTOPILOT_ROOT := /home/ipad/Vivado/Vitis_HLS/2023.1
AUTOPILOT_MACH := lnx64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
IFLAG += -fPIC
ifndef AP_GCC_PATH
  AP_GCC_PATH := /home/ipad/Vivado/Vitis_HLS/2023.1/tps/lnx64/gcc-8.3.0/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_TOOL}/clang-3.9-csynth/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -D__HLS_COSIM__

IFLAG += -D__HLS_CSIM__

IFLAG += -D__VITIS_HLS__

IFLAG += -D__SIM_FPO__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E1__
IFLAG += -g
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += -Werror=return-type
CCFLAG += -Wno-abi
TOOLCHAIN += 
CCFLAG += -gcc-toolchain /home/ipad/Vivado/Vitis_HLS/2023.1/tps/lnx64/gcc-8.3.0
LFLAG += -gcc-toolchain /home/ipad/Vivado/Vitis_HLS/2023.1/tps/lnx64/gcc-8.3.0
CCFLAG += -fno-exceptions
LFLAG += -fno-exceptions
CCFLAG += -fprofile-instr-generate="code-%m.profraw"
LFLAG += -fprofile-instr-generate="code-%m.profraw"
CCFLAG += -Wno-c++11-narrowing
CCFLAG += -Werror=uninitialized
CCFLAG += -std=c++11
LFLAG += -std=c++11



include ./Makefile.rules

all: $(TARGET)



$(ObjDir)/fir_tb.o: ../../../../fir_tb.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../fir_tb.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CXX) ${CCFLAG} -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fir_tb.d

$(ObjDir)/fir_filter.o: ../../../../fir_filter.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../fir_filter.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CXX) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fir_filter.d
pObjDir=pobj
POBJECTS := $(basename $(notdir $(HLS_SOURCES)))
POBJECTS := $(POBJECTS:%=$(pObjDir)/%.bc)

$(pObjDir)/fir_tb.bc: ../../../../fir_tb.cpp $(pObjDir)/.dir
	$(Echo) $(CXX)  -gcc-toolchain /home/ipad/Vivado/Vitis_HLS/2023.1/tps/lnx64/gcc-8.3.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ;
	$(Verb) $(CXX)  -gcc-toolchain /home/ipad/Vivado/Vitis_HLS/2023.1/tps/lnx64/gcc-8.3.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ;

$(pObjDir)/fir_filter.bc: ../../../../fir_filter.cpp $(pObjDir)/.dir
	$(Echo) $(CXX)  -gcc-toolchain /home/ipad/Vivado/Vitis_HLS/2023.1/tps/lnx64/gcc-8.3.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c  $(IFLAG) $(DFLAG) $< -o $@ ;
	$(Verb) $(CXX)  -gcc-toolchain /home/ipad/Vivado/Vitis_HLS/2023.1/tps/lnx64/gcc-8.3.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c  $(IFLAG) $(DFLAG) $< -o $@ ;

profile_data: *.profraw
	${AP_CLANG_PATH}/llvm-profdata merge -output=code.profdata *.profraw

profile_all: profile_data $(POBJECTS)
	${AP_CLANG_PATH}/llvm-link -o LinkFile.bc ${POBJECTS} -f; \
	${MKDIR} /home/ipad/HLS_Thesis/vitis_hls/fir_filter/fir_filter_soln/.autopilot/db/dot ; \
	${CP} -r ${pObjDir} /home/ipad/HLS_Thesis/vitis_hls/fir_filter/fir_filter_soln/.autopilot/db/dot ; \
	${CP} LinkFile.bc /home/ipad/HLS_Thesis/vitis_hls/fir_filter/fir_filter_soln/.autopilot/db/dot ; \
	${CD} /home/ipad/HLS_Thesis/vitis_hls/fir_filter/fir_filter_soln/.autopilot/db/dot ; \
	${AP_CLANG_PATH}/opt -dot-callgraph-hls -cfg-hier-userfilelist "/home/ipad/HLS_Thesis/vitis_hls/fir_filter.cpp /home/ipad/HLS_Thesis/vitis_hls/fir_filter.h /home/ipad/HLS_Thesis/vitis_hls/fir_tb.cpp" -csim-top-function-name=fir_filter LinkFile.bc -o LinkFile_fid.bc ; \
	${AP_CLANG_PATH}/opt -dot-cfg-hier-only -cfg-hier-userfilelist "/home/ipad/HLS_Thesis/vitis_hls/fir_filter.cpp /home/ipad/HLS_Thesis/vitis_hls/fir_filter.h /home/ipad/HLS_Thesis/vitis_hls/fir_tb.cpp" -cfg-hier-type csim LinkFile_fid.bc -o LinkFile_pp.bc ; 
