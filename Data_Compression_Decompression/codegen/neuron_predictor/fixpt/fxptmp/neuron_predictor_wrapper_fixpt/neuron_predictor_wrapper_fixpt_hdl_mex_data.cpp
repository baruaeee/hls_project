#include "neuron_predictor_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

emlrtCTX emlrtRootTLSGlobal{nullptr};

boolean_T x_hist_not_empty;

const mxArray *eml_mx{nullptr};

const mxArray *b_eml_mx{nullptr};

const mxArray *c_eml_mx{nullptr};

const mxArray *d_eml_mx{nullptr};

emlrtContext emlrtContextGlobal{
    true,
    false,
    131691U,
    nullptr,
    "neuron_predictor_wrapper_fixpt_hdl_mex",
    nullptr,
    false,
    {1511293120U, 2570482084U, 1335128479U, 330037357U},
    nullptr};
