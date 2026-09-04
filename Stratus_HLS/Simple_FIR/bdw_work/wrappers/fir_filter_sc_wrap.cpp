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
* This file is used to wrap the three different versions of the DUT
* block called "fir_filter". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/


#include	"fir_filter_sc_wrap.h"
#include	"fir_filter_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports
void fir_filter_wrapper::thread_x_value()
{
   x_value = x.read().value;
}
void fir_filter_wrapper::thread_y()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = y_value.read();
   y.write(tmp);
}
void fir_filter_wrapper::thread_h_value_0()
{
   h_value_0 = h[0].read().value;
}
void fir_filter_wrapper::thread_h_value_1()
{
   h_value_1 = h[1].read().value;
}
void fir_filter_wrapper::thread_h_value_2()
{
   h_value_2 = h[2].read().value;
}
void fir_filter_wrapper::thread_h_value_3()
{
   h_value_3 = h[3].read().value;
}


void fir_filter_wrapper::InitInstances(  )
{
            
    fir_filter0 = new fir_filter( "fir_filter" );

    fir_filter0->clk(clk);
    fir_filter0->rst(rst);
    fir_filter0->x_vld(x_vld);
    fir_filter0->x_value(x_value);
    fir_filter0->y_vld(y_vld);
    fir_filter0->y_value(y_value);
    fir_filter0->h_value_0(h_value_0);
    fir_filter0->h_value_1(h_value_1);
    fir_filter0->h_value_2(h_value_2);
    fir_filter0->h_value_3(h_value_3);

}

void fir_filter_wrapper::InitThreads()
{
    SC_METHOD(thread_x_value);
      sensitive << x;
    SC_METHOD(thread_y);
      sensitive << y_value;
    SC_METHOD(thread_h_value_0);
      sensitive << h[0];
    SC_METHOD(thread_h_value_1);
      sensitive << h[1];
    SC_METHOD(thread_h_value_2);
      sensitive << h[2];
    SC_METHOD(thread_h_value_3);
      sensitive << h[3];

}

void fir_filter_wrapper::DeleteInstances()
{
    if (fir_filter0)
    {
        delete fir_filter0;
        fir_filter0 = 0;
    }
}

