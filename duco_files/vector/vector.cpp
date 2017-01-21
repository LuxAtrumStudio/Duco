#include "../duco_headers.hpp"
#include "vector.hpp"
#include <math.h>
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

duco::vector::Vector::Vector(const Vector &clone) {
  vals = clone.vals;
  length = clone.length;
}

duco::vector::Vector::~Vector() {
  vals.clear();
  length = 0;
}

void duco::vector::Vector::SetVals(std::vector<double> vars) {
  vals = vars;
  length = vars.size();
}

void duco::vector::Vector::PushBack(double val) {
  vals.push_back(val);
  length++;
}

void duco::vector::Vector::PopBack() {
  vals.pop_back();
  length--;
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

double duco::vector::Vector::Magnitude() {
  double magnitude = 0;
  for (int i = 0; i < length; i++) {
    magnitude += pow(vals[i], 2);
  }
  magnitude = pow(magnitude, 0.5);
  return (magnitude);
}

std::string duco::vector::Vector::String() {
  std::string out = "<";
  for (int i = 0; i < length - 1; i++) {
    out += manipulation::ReduceDouble(vals[i]) + ", ";
  }
  out += manipulation::ReduceDouble(vals[length - 1]) + ">";
  return (out);
}
