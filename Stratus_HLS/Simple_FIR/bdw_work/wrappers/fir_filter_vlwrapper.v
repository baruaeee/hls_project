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
* Verilog Verification wrapper module for the fir_filter module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module fir_filter_vlwrapper(
      clk,
       rst,
       x_vld,
       x_value,
       y_vld,
       y_value,
       h_value_0,
      h_value_1,
      h_value_2,
      h_value_3

    );

`ifdef BDW_RTL_fir_filter
	input clk;
	input rst;
	input x_vld;
	input [15:0] x_value;
	output y_vld;
	output [15:0] y_value;
	input [15:0] h_value_0;
	input [15:0] h_value_1;
	input [15:0] h_value_2;
	input [15:0] h_value_3;


    // Instantiate the Verilog module 
    fir_filter fir_filter_v(
        .clk(clk),
         .rst(rst),
         .x_vld(x_vld),
         .x_value(x_value),
         .y_vld(y_vld),
         .y_value(y_value),
         .h_value_0(h_value_0),
        .h_value_1(h_value_1),
        .h_value_2(h_value_2),
        .h_value_3(h_value_3)

    );
`else
	input clk;
	input rst;
	input x_vld;
	input [15:0] x_value;
	output y_vld;
	reg y_vld;
	wire m_y_vld;
	output [15:0] y_value;
	reg[15:0] y_value;
	wire [15:0] m_y_value;
	input [15:0] h_value_0;
	input [15:0] h_value_1;
	input [15:0] h_value_2;
	input [15:0] h_value_3;


    // Instantiate the Verilog module that instantiates the SystemC module
    fir_filter_type_wrapper fir_filter_sc(
        .clk(clk),
         .rst(rst),
         .x_vld(x_vld),
         .x_value(x_value),
         .y_vld(m_y_vld),
         .y_value(m_y_value),
         .h_value_0(h_value_0),
        .h_value_1(h_value_1),
        .h_value_2(h_value_2),
        .h_value_3(h_value_3)

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    always @(m_y_vld)
     begin
      y_vld <= m_y_vld;
     end
    always @(m_y_value)
     begin
      y_value <= m_y_value;
     end


`endif

endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module

`ifndef BDW_RTL_fir_filter

module fir_filter_type_wrapper(
      clk,
       rst,
       x_vld,
       x_value,
       y_vld,
       y_value,
       h_value_0,
      h_value_1,
      h_value_2,
      h_value_3

    ) (* integer foreign = "SystemC";
    *);

	input clk;
	input rst;
	input x_vld;
	input [15:0] x_value;
	output y_vld;
	output [15:0] y_value;
	input [15:0] h_value_0;
	input [15:0] h_value_1;
	input [15:0] h_value_2;
	input [15:0] h_value_3;


endmodule

`endif
