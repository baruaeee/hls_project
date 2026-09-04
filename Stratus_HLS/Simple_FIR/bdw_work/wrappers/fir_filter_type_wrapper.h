/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file contains the fir_filter_type_wrapper module
* for use in the verilog verification wrapper fir_filter_vlwrapper.v
* It creats an instance of the fir_filter module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/


#ifndef _FIR_FILTER_TYPE_WRAP_INCLUDED_
#define _FIR_FILTER_TYPE_WRAP_INCLUDED_


#include <systemc.h>
#include "fir_filter.h"


// Declaration of wrapper with RTL level ports

SC_MODULE(fir_filter_type_wrapper)
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

    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    void thread_x();
    void thread_y_value();
    void thread_h_0();
    void thread_h_1();
    void thread_h_2();
    void thread_h_3();


	SC_HAS_PROCESS(fir_filter_type_wrapper);

	fir_filter_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("fir_filter")) )
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
		  	

		  ,fir_filter0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~fir_filter_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	fir_filter* fir_filter0;
};

#endif /*  */
