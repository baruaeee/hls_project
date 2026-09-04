/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _FIR_FILTER_SC_WRAP_INCLUDED_
#define _FIR_FILTER_SC_WRAP_INCLUDED_

#include <systemc.h>

struct fir_filter;

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

    
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

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
		  	

		  ,fir_filter0(0)

    {
        InitInstances( );
		InitThreads();
    }

    // destructor
    ~fir_filter_wrapper()
    {
        DeleteInstances();
    }

	fir_filter* fir_filter0;
};

#endif /* _FIR_FILTER_SC_WRAP_INCLUDED_ */
