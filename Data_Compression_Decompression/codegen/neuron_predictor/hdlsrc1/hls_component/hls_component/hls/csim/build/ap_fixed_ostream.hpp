#pragma once
#include <iostream>
#include "ap_fixed.h"

// Overload << for ap_ufixed and ap_fixed to avoid ambiguity
template<int W, int I, ap_q_mode Q, ap_o_mode O, int N>
std::ostream& operator<<(std::ostream& os, const ap_ufixed<W,I,Q,O,N>& val) {
    return os << val.to_double();
}

template<int W, int I, ap_q_mode Q, ap_o_mode O, int N>
std::ostream& operator<<(std::ostream& os, const ap_fixed<W,I,Q,O,N>& val) {
    return os << val.to_double();
}
