//
// Verilog co-simulation wrapper module for the fir_filter module.

// This module contains the followng items:
//	- An instance of the verilog RTL module created by stratus_vlg.
//	- Wires and reg's connected to the ports of the RTL module.
//	- A clock generator using the project's clock frequency and connected to
//    the RTL module's clock port.
//
// The wires and reg's will be connected to sc_signals in the SystemC simulaton
// by esc_link_signals calls in the proxy module found in the fir_filter_cosim.h 
// file.

`timescale 1 ps / 1 ps

module fir_filter_cosim;

	reg clk;
	reg rst;
	reg x_vld;
	reg[15:0] x_value;
	wire y_vld;
	wire[15:0] y_value;
	reg[15:0] h_value_0;
	reg[15:0] h_value_1;
	reg[15:0] h_value_2;
	reg[15:0] h_value_3;


	`include "hub.v"

	fir_filter fir_filter0( .clk(clk),
	 .rst(rst),
	 .x_vld(x_vld),
	 .x_value(x_value),
	 .y_vld(y_vld),
	 .y_value(y_value),
	 .h_value_0(h_value_0),
	.h_value_1(h_value_1),
	.h_value_2(h_value_2),
	.h_value_3(h_value_3) );


	// Variables that can be set externally
	reg clk_firstEdge;
	reg clk_initialized;
	reg clk_started;
	real clk_startTime;
	real clk_firstHalf;
	real clk_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    clk_firstEdge = 1'b1;
	    clk_startTime = 0.000;    // Offset from time 0 to first edge.
	    clk_firstHalf = 5.000;    // Delay for first half of cycle.
	    clk_secondHalf = 5.000;    // Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on clk_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( clk_initialized !== 1'b1 )
	        @( clk_initialized );
	
	    if ( clk_startTime > 0.0 ) begin
	        clk_started = #clk_startTime 1;
	    end
	    else begin
	        clk_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( fir_filter0.clk ) begin
	    if ( clk_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( clk_started !== 1'b1 )
	        @( clk_started );
	
	    clk <= clk_firstEdge;
	    if ( clk_firstHalf > 0.0 ) begin
	        #clk_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        clk = ~clk_firstEdge;
	    end
	    else begin
	        clk = ~clk_firstEdge;
	    end
	    if ( clk_secondHalf > 0.0 ) begin
	        #clk_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg rst_firstEdge;
	reg rst_initialized;
	reg rst_started;
	real rst_startTime;
	real rst_firstHalf;
	real rst_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    rst_firstEdge = 1'b1;
	    rst_startTime = 0.000;    // Offset from time 0 to first edge.
	    rst_firstHalf = 5.000;    // Delay for first half of cycle.
	    rst_secondHalf = 5.000;    // Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on rst_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( rst_initialized !== 1'b1 )
	        @( rst_initialized );
	
	    if ( rst_startTime > 0.0 ) begin
	        rst_started = #rst_startTime 1;
	    end
	    else begin
	        rst_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( fir_filter0.rst ) begin
	    if ( rst_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( rst_started !== 1'b1 )
	        @( rst_started );
	
	    rst <= rst_firstEdge;
	    if ( rst_firstHalf > 0.0 ) begin
	        #rst_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        rst = ~rst_firstEdge;
	    end
	    else begin
	        rst = ~rst_firstEdge;
	    end
	    if ( rst_secondHalf > 0.0 ) begin
	        #rst_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg x_vld_firstEdge;
	reg x_vld_initialized;
	reg x_vld_started;
	real x_vld_startTime;
	real x_vld_firstHalf;
	real x_vld_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    x_vld_firstEdge = 1'b1;
	    x_vld_startTime = 0.000;    // Offset from time 0 to first edge.
	    x_vld_firstHalf = 5.000;    // Delay for first half of cycle.
	    x_vld_secondHalf = 5.000;    // Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on x_vld_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( x_vld_initialized !== 1'b1 )
	        @( x_vld_initialized );
	
	    if ( x_vld_startTime > 0.0 ) begin
	        x_vld_started = #x_vld_startTime 1;
	    end
	    else begin
	        x_vld_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( fir_filter0.x_vld ) begin
	    if ( x_vld_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( x_vld_started !== 1'b1 )
	        @( x_vld_started );
	
	    x_vld <= x_vld_firstEdge;
	    if ( x_vld_firstHalf > 0.0 ) begin
	        #x_vld_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        x_vld = ~x_vld_firstEdge;
	    end
	    else begin
	        x_vld = ~x_vld_firstEdge;
	    end
	    if ( x_vld_secondHalf > 0.0 ) begin
	        #x_vld_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end


endmodule
