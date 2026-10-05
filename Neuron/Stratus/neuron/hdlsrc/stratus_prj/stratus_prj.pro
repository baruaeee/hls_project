#################################################
# Stratus IDE project file generated;
# Stratus IDE project file format version: 2
#################################################
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

STRATUSHOME = $$(STRATUS_HOME)
SYSTEMCHOME = $$(STRATUS_HOME)/tools.lnx86/stratus/systemc/2.3.3

TEMPLATE = app
INCLUDEPATH += $${SYSTEMCHOME}/include
INCLUDEPATH += $${SYSTEMCHOME}/include/tlm
INCLUDEPATH += $${STRATUSHOME}/share/stratus/include
INCLUDEPATH += ./bdw_work/wrappers
INCLUDEPATH += ./
INCLUDEPATH += memlib/c_parts

SOURCES += \ 
		main.cc \ 
		neuron_fixpt.cc \ 
		system.cc \ 
		tb.cc \ 
		memlib/c_parts/DPRAM.cc \ 
		memlib/c_parts/SPRAM.cc \ 

HEADERS += \ 
		hlsutils.hpp \ 
		neuron_fixpt.h \ 
		neuron_fixpt_types.h \ 
		neuron_fixptClass.hpp \ 
		neuron_fixptClass_tb.hpp \ 
		rtwtypes.hpp \ 
		system.h \ 
		tb.h \ 
		memlib/c_parts/DPRAM.h \ 
		memlib/c_parts/SPRAM.h \ 

OTHER_FILES += \ 
		Makefile \ 
		project.tcl \ 

