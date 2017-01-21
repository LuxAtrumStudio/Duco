#include "../manipulation/manipulation.hpp"
#include "vector.hpp"
#include <stdarg.h>
#include <string>
#include <vector>

duco::vector::Vector::Vector(double nvars, ...) {
  va_list ap;
  va_start(ap, nvars);
  for (int i = 0; i < nvars; i++) {
    vals.push_back(va_arg(ap, double));
  }
  va_end(ap);
  length = nvars;
}

duco::vector::Vector::~Vector() {
  vals.clear();
  length = 0;
}

double duco::vector::Vector::Sum() {
  double total = 0;
  for (int i = 0; i < length; i++) {
    total += vals[i];
  }
  return (total);
}

void duco::vector::Vector::ScalarMultiply(double val) {
  for (int i = 0; i < length; i++) {
    vals[i] *= val;
  }
}

std::string duco::vector::Vector::String() {
  std::string out = "<";
  for (int i = 0; i < length - 1; i++) {
    out += manipulation::ReduceDouble(vals[i]) + ", ";
  }
  out += manipulation::ReduceDouble(vals[length - 1]) + ">";
  return (out);
}
