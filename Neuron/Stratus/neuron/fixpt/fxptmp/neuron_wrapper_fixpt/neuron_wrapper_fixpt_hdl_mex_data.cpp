#include "neuron_wrapper_fixpt_hdl_mex_data.h"
#include "rt_nonfinite.h"

emlrtCTX emlrtRootTLSGlobal{nullptr};

const mxArray *eml_mx{nullptr};

const mxArray *b_eml_mx{nullptr};

const mxArray *c_eml_mx{nullptr};

const mxArray *d_eml_mx{nullptr};

const mxArray *e_eml_mx{nullptr};

emlrtContext emlrtContextGlobal{
    true,
    false,
    131675U,
    nullptr,
    "neuron_wrapper_fixpt_hdl_mex",
    nullptr,
    false,
    {1511293120U, 2570482084U, 1335128479U, 330037357U},
    nullptr};
