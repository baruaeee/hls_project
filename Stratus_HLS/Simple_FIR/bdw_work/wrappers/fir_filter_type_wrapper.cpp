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

#include "fir_filter_type_wrapper.h"


SC_MODULE_EXPORT(fir_filter_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports
void fir_filter_type_wrapper::thread_x()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = x_value.read();
   x.write(tmp);
}
void fir_filter_type_wrapper::thread_y_value()
{
   y_value = y.read().value;
}
void fir_filter_type_wrapper::thread_h_0()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_0.read();
   h[0].write(tmp);
}
void fir_filter_type_wrapper::thread_h_1()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_1.read();
   h[1].write(tmp);
}
void fir_filter_type_wrapper::thread_h_2()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_2.read();
   h[2].write(tmp);
}
void fir_filter_type_wrapper::thread_h_3()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_3.read();
   h[3].write(tmp);
}


void fir_filter_type_wrapper::InitInstances()
{
    fir_filter0 = new fir_filter( "fir_filter" );

    fir_filter0->clk(clk);
    fir_filter0->rst(rst);
    fir_filter0->x_vld(x_vld);
    fir_filter0->x(x);
    fir_filter0->y_vld(y_vld);
    fir_filter0->y(y);
    fir_filter0->h[0](h[0]);
    fir_filter0->h[1](h[1]);
    fir_filter0->h[2](h[2]);
    fir_filter0->h[3](h[3]);

}

void fir_filter_type_wrapper::InitThreads()
{
    SC_METHOD(thread_x);
      sensitive << x_value;
    SC_METHOD(thread_y_value);
      sensitive << y;
    SC_METHOD(thread_h_0);
      sensitive << h_value_0;
    SC_METHOD(thread_h_1);
      sensitive << h_value_1;
    SC_METHOD(thread_h_2);
      sensitive << h_value_2;
    SC_METHOD(thread_h_3);
      sensitive << h_value_3;

}

void fir_filter_type_wrapper::DeleteInstances()
{
        delete fir_filter0;
        fir_filter0 = 0;
}

