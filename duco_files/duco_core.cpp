#include "duco_core.hpp"
#include <pessum.h>

using namespace pessum::logging;

namespace duco {
int lduc, lexp, lman, lmat, lnot, ltri, lvec;
}

void duco::InitializeDuco() {
  pessum::InitializePessumComponents();
  lduc = AddLogLocation("duco/");
  lexp = AddLogLocation("duco/exponential/");
  lman = AddLogLocation("duco/manipulation/");
  lmat = AddLogLocation("duco/matrix/");
  lnot = AddLogLocation("duco/notation/");
  ltri = AddLogLocation("duco/trigonometry/");
  lvec = AddLogLocation("duco/vector/");
  LogLoc(SUCCESS, "Initialized Duco", lduc, "InitializeDuco");
}

void duco::TerminateDuco() {
  LogLoc(SUCCESS, "Terminated Duco", lduc, "TerminateDuco");
  pessum::TerminatePessumComponents();
}
