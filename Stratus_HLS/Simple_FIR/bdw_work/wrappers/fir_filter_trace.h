	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( fir_filter0 != NULL ) {
			esc_trace_signal( &fir_filter0->clk, ( std::string(name()) + std::string( ".fir_filter.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &fir_filter0->rst, ( std::string(name()) + std::string( ".fir_filter.rst" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &fir_filter0->x_vld, ( std::string(name()) + std::string( ".fir_filter.x_vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &fir_filter0->x, ( std::string(name()) + std::string( ".fir_filter.x" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &fir_filter0->y_vld, ( std::string(name()) + std::string( ".fir_filter.y_vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &fir_filter0->y, ( std::string(name()) + std::string( ".fir_filter.y" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &fir_filter0->h, ( std::string(name()) + std::string( ".fir_filter.h" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( fir_filter0 != NULL ) {
			esc_trace_signal( &fir_filter0->clk, ( std::string(name()) + std::string( ".fir_filter.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &fir_filter0->rst, ( std::string(name()) + std::string( ".fir_filter.rst" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &fir_filter0->x_vld, ( std::string(name()) + std::string( ".fir_filter.x_vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &fir_filter0->x, ( std::string(name()) + std::string( ".fir_filter.x" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &fir_filter0->y_vld, ( std::string(name()) + std::string( ".fir_filter.y_vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &fir_filter0->y, ( std::string(name()) + std::string( ".fir_filter.y" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &fir_filter0->h, ( std::string(name()) + std::string( ".fir_filter.h" ) ).c_str(), esc_trace_fsdb );
		}
	}
