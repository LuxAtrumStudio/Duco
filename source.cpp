#include "duco_files/duco_headers.hpp"
#include <iostream>
using namespace duco;

int main(int argc, char const *argv[]) {
  matrix::Matrix mat(3, 3, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
  std::cout << mat.GetString() << ":" << mat.Determinate() << "\n";
  return 0;
}
