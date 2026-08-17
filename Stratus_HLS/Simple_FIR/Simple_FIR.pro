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

SOURCES += \ 
		fir_filter.cc \ 
		fir_tb.cc \ 
		tb.cc \ 

HEADERS += \ 
		defines.h \ 
		fir_filter.h \ 

OTHER_FILES += \ 
		Makefile \ 
		project.tcl \ 

