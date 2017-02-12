#include "duco.h"
#include <iostream>
using namespace duco;

int main(int argc, char const *argv[]) {
  duco::LoadOperMap();
  equation::Equation eq("3x+4x");
  std::cout << eq.SolveEquation(1.5) << "\n";

  return 0;
}
