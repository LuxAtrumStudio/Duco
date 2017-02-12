#include "duco_files/duco_headers.hpp"
#include <iostream>
using namespace duco;

int main(int argc, char const *argv[]) {
  duco::LoadOperMap();
  equation::Equation eq("3x+4");
  std::cout << eq.SolveEquation(1.5) << "\n";

  return 0;
}
