#pragma once

#include "cynw_fixed.h"

class ifin_t {
public:
  cynw_fixed <(int)14, (int)2, (sc_dt::sc_q_mode)5, (sc_dt::sc_o_mode)3, (int)0 > x[4];
  cynw_ufixed <(int)14, (int)0, (sc_dt::sc_q_mode)5, (sc_dt::sc_o_mode)3, (int)0 > w[4];
  sc_uint< 1 > b;

  inline ifin_t & operator=( const ifin_t & obj ) {
    for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
      x[ndx_0_0] = obj.x[ndx_0_0];
    }
    for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
      w[ndx_0_0] = obj.w[ndx_0_0];
    }
    b = obj.b;
    return *this;
  }

  inline void set_x( const cynw_fixed <(int)14, (int)2, (sc_dt::sc_q_mode)5, (sc_dt::sc_o_mode)3, (int)0 > (&in_x)[4] ) {
    for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
      x[ndx_0_0] = in_x[ndx_0_0];
    }
  }

  inline void set_w( const cynw_ufixed <(int)14, (int)0, (sc_dt::sc_q_mode)5, (sc_dt::sc_o_mode)3, (int)0 > (&in_w)[4] ) {
    for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
      w[ndx_0_0] = in_w[ndx_0_0];
    }
  }

  inline void set_b( const sc_uint< 1 > (&in_b) ) {
    b = in_b;
  }

  inline bool operator==( const ifin_t & obj ) {
    for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
      if( ! ( x[ndx_0_0] == obj.x[ndx_0_0] ) ) return( false );
    }
    for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
      if( ! ( w[ndx_0_0] == obj.w[ndx_0_0] ) ) return( false );
    }
    if( ! ( b == obj.b ) ) return( false );
    return( true );
  }
};

inline void sc_trace( sc_trace_file* tf,
                      const ifin_t & obj,
                      const std::string name )
{
  char pstr[2048];
  for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
    sprintf( pstr, ".x_%d_", ndx_0_0 );
    sc_trace( tf, obj.x[ndx_0_0], name + pstr );
  }
  for( int ndx_0_0 = 0; ndx_0_0 < 4; ndx_0_0++ ) {
    sprintf( pstr, ".w_%d_", ndx_0_0 );
    sc_trace( tf, obj.w[ndx_0_0], name + pstr );
  }
  sc_trace( tf, obj.b, name + std::string("b") );
}

inline ostream & operator<<( ostream & os, const ifin_t & obj )
{
#ifndef STRATUS_HLS
  os << "operator<< not implemented for type ifin_t!";
#endif
  return( os );
}



