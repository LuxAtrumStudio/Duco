#include "duco.h"
#include <iostream>
#include <pessum.h>
using namespace duco;

int main(int argc, char const *argv[]) {
  pessum::InitializePessum(true, true);
  duco::InitializeDuco();
  std::cout << operation::trigonometry::Lot(10, -1, 5, 10, true) << "\n";
  pessum::TerminatePessum();
  return 0;
}
