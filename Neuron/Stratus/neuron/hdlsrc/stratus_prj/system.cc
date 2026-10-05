#include "system.h"

void TOP::initInstances()
{
  iTb = new tb( "tb" );
  iTb->clk(clk);
  iTb->rst(rst);

  iDut = new neuron_fixpt_wrapper( "neuron_fixpt_wrapper" );
  iDut->clk(clk);
  iDut->rst(rst);

  iTb->p_ifin(ci);
  iDut->p_ifin(ci);
  iDut->p_ifout(co);
  iTb->p_ifout(co);
}

void TOP::deleteInstances()
{
  delete iTb;
  delete iDut;
}

