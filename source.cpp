#include "duco.h"
#include <iostream>
#include <pessum.h>
using namespace duco;

int main(int argc, char const *argv[]) {
  pessum::InitializePessum(true, true);
  duco::InitializeDuco();
  duco::operation::LoadArithmeticOperations();
  std::cout << duco::operation::ops["SUB"].RunDoubleFunction(2, 1.5, 2.5)
            << "\n";
  pessum::TerminatePessum();
  return 0;
}
