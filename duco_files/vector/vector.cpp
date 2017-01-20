#include "../manipulation/manipulation.hpp"
#include "vector.hpp"
#include <stdarg.h>

duco::vec::Vector::Vector(double nvars, ...) {
  va_list ap;
  va_start(ap, nvars);
  for (int i = 0; i <= nvars; i++) {
    vals.push_back(va_arg(ap, double));
  }
  va_end(ap);
  length = nvars;
}

duco::vec::Vector::~Vector() {
  vals.clear();
  length = 0;
}

double duco::vec::Vector::Sum() {
  double total = 0;
  for (int i = 0; i < length; i++) {
    total += vals[i];
  }
  return (total);
}

std::string duco::vec::Vector::String() {
  std::string out = "<";
  for (int i = 0; i < length - 1; i++) {
    // out += manipulation::ReduceDouble(vals[i]) + ", ";
  }
  // out += manipulation::ReduceDouble(vals[length]) + ">";
  return (out);
}
