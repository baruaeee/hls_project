/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _FIR_FILTER_SC_FOREIGN_INCLUDED_
#define _FIR_FILTER_SC_FOREIGN_INCLUDED_

#include <systemc.h>

#if !defined(XM_SYSTEMC) && defined(NC_SYSTEMC)
#define xmsc_foreign_module ncsc_foreign_module
#endif


// Declaration of wrapper with RTL level ports

struct fir_filter : public xmsc_foreign_module
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


    const char* hdl_name() const { return "fir_filter"; }
    
	fir_filter( sc_module_name name )
		: xmsc_foreign_module(name)
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
		  	

		
    {
    }

};

#endif /* _FIR_FILTER_SC_FOREIGN_INCLUDED_ */
