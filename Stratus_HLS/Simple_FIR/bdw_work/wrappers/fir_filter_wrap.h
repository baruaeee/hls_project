/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _FIR_FILTER_WRAP_INCLUDED_
#define _FIR_FILTER_WRAP_INCLUDED_

#ifndef BDW_NO_SUBMOD_WRAPPERS


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */


#if defined(STRATUS_VLG) 

#include <systemc.h>

#define fir_filter_wrapper fir_filter

/* This is the section that is seen during processing by stratus_vlg of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(fir_filter)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_in< bool > x_vld;
	sc_in< sc_int< 16 > > x_value;
	sc_out< bool > y_vld;
	sc_out< sc_int< 16 > > y_value;
	sc_in< sc_int< 16 > > h_value_0;
	sc_in< sc_int< 16 > > h_value_1;
	sc_in< sc_int< 16 > > h_value_2;
	sc_in< sc_int< 16 > > h_value_3;

	SC_CTOR(fir_filter);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by stratus_hls or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_fixed.h"


#define fir_filter_wrapper fir_filter

/* Only port declarations are required for nested modules.
 */
SC_MODULE(fir_filter)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_in< bool > x_vld;
	sc_in< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > x;
	sc_out< bool > y_vld;
	sc_out< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > y;
	sc_in< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > h[4];


	SC_HAS_PROCESS(fir_filter);
    	fir_filter_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("fir_filter")) );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct fir_filter;
struct fir_filter_cosim;
struct fir_filter_rtl;

#include "cynw_fixed.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(fir_filter_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_in< bool > x_vld;
	sc_in< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > x;
	sc_out< bool > y_vld;
	sc_out< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > y;
	sc_in< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > h[4];

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    sc_signal< sc_int< 16 > > x_value;
    sc_signal< sc_int< 16 > > y_value;
    sc_signal< sc_int< 16 > > h_value_0;
    sc_signal< sc_int< 16 > > h_value_1;
    sc_signal< sc_int< 16 > > h_value_2;
    sc_signal< sc_int< 16 > > h_value_3;

    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    void thread_x_value();
    void thread_y();
    void thread_h_value_0();
    void thread_h_value_1();
    void thread_h_value_2();
    void thread_h_value_3();


	SC_HAS_PROCESS(fir_filter_wrapper);

    	fir_filter_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("fir_filter")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,x_vld("x_vld")
		  	,x("x")
		  	,y_vld("y_vld")
		  	,y("y")
		  	,h()
		  	

          		  ,fir_filter0(0), fir_filter_cosim0(0), fir_filter_rtl0(0)
		

    {
        InitInstances( );
		InitThreads();
    }


    // destructor
    ~fir_filter_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( fir_filter_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( fir_filter_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( fir_filter_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( fir_filter_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    
        
#ifdef fir_filter_INTERNAL
	fir_filter* behModule() { return fir_filter0; }
#else
	fir_filter* behModule() { return fir_filter0; }
#endif
	fir_filter_cosim* cosimModule() { return fir_filter_cosim0; }
    	fir_filter_rtl* rtlModule() { return fir_filter_rtl0; }

#ifdef fir_filter_INTERNAL
	fir_filter* fir_filter0;
#else
	fir_filter* fir_filter0;
#endif
	fir_filter_cosim* fir_filter_cosim0;
	fir_filter_rtl* fir_filter_rtl0;
	};

// Declaration of wrapper with RTL level ports

SC_MODULE(fir_filter_wrapper_r)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_in< bool > x_vld;
	sc_in< sc_int< 16 > > x_value;
	sc_out< bool > y_vld;
	sc_out< sc_int< 16 > > y_value;
	sc_in< sc_int< 16 > > h_value_0;
	sc_in< sc_int< 16 > > h_value_1;
	sc_in< sc_int< 16 > > h_value_2;
	sc_in< sc_int< 16 > > h_value_3;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    sc_signal< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > x;
    sc_signal< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > y;
    sc_signal< cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > > h[4];

    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };

	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    void thread_x();
    void thread_y_value();
    void thread_h_0();
    void thread_h_1();
    void thread_h_2();
    void thread_h_3();


	SC_HAS_PROCESS(fir_filter_wrapper_r);

	fir_filter_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("fir_filter")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,x_vld("x_vld")
		  	,x_value("x_value")
		  	,y_vld("y_vld")
		  	,y_value("y_value")
		  	,h_value_0("h_value_0"),
		  h_value_1("h_value_1"),
		  h_value_2("h_value_2"),
		  h_value_3("h_value_3")
		  	

          		  ,fir_filter0(0), fir_filter_cosim0(0), fir_filter_rtl0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~fir_filter_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( fir_filter_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( fir_filter_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( fir_filter_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( fir_filter_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
	
#ifdef fir_filter_INTERNAL
	fir_filter* behModule() { return fir_filter0; }
#else
	fir_filter* behModule() { return fir_filter0; }
#endif
	fir_filter_cosim* cosimModule() { return fir_filter_cosim0; }
		fir_filter_rtl* rtlModule() { return fir_filter_rtl0; }

protected:
#ifdef fir_filter_INTERNAL
	fir_filter* fir_filter0;
#else
	fir_filter* fir_filter0;
#endif
	fir_filter_cosim* fir_filter_cosim0;
	fir_filter_rtl* fir_filter_rtl0;
	};

#endif

/* Restore ioConfig define values for parent module. */


#else /* BDW_NO_SUBMOD_WRAPPERS */

#define fir_filter_wrapper fir_filter
#include "fir_filter.h"

#endif /* BDW_NO_SUBMOD_WRAPPERS */

#endif /*  */
