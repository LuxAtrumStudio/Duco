#include "vector.hpp"
#include <math.h>
#include <stdarg.h>
#include <vector>

duco::vector::Vector::Vector() { length = 0; }

duco::vector::Vector::Vector(int nvars, ...) {
  va_list ap;
  va_start(ap, nvars);
  for (int i = 0; i < nvars; i++) {
    vals.push_back(va_arg(ap, double));
  }
  va_end(ap);
  length = nvars;
}

duco::vector::Vector::Vector(std::vector<double> invals) {
  vals = invals;
  length = vals.size();
}

duco::vector::Vector::Vector(const Vector &copy) {
  vals = copy.vals;
  length = copy.length;
}

duco::vector::Vector::~Vector() {
  vals.clear();
  length = 0;
}

void duco::vector::Vector::SetVals(int nvars, ...) {
  vals.clear();
  va_list ap;
  va_start(ap, nvars);
  for (int i = 0; i < nvars; i++) {
    vals.push_back(va_arg(ap, double));
  }
  va_end(ap);
  length = nvars;
}

void duco::vector::Vector::SetVals(std::vector<double> invals) {
  vals.clear();
  vals = invals;
  length = vals.size();
}

void duco::vector::Vector::PopBack() {
  if (length > 0) {
    vals.pop_back();
    length--;
  }
}

void duco::vector::Vector::PushBack(double val) {
  vals.push_back(val);
  length++;
}

void duco::vector::Vector::Resize(int nvars, double val) {
  while (length > nvars && length > 0) {
    PopBack();
  }
  while (length < nvars) {
    PushBack(val);
  }
}

void duco::vector::Vector::ScalarMultiply(double val) {
  for (int i = 0; i < length; i++) {
    vals[i] *= val;
  }
}

void duco::vector::Vector::Pow(double val) {
  for (int i = 0; i < length; i++) {
    vals[i] = pow(vals[i], val);
  }
}

double duco::vector::Vector::Total() {
  double total = 0;
  for (int i = 0; i < length; i++) {
    total += vals[i];
  }
  return (total);
}

double duco::vector::Vector::Magnitude() {
  double mag = 0;
  for (int i = 0; i < length; i++) {
    mag += pow(vals[i], 2);
  }
  mag = pow(mag, 0.5);
  return (mag);
}

int duco::vector::Vector::GetLength() { return (length); }

std::vector<double> duco::vector::Vector::GetVector() { return (vals); }

std::string duco::vector::Vector::GetString() {
  std::string str = "<";
  for (int i = 0; i < length; i++) {
    str += std::to_string(vals[i]);
    if (i != length - 1) {
      str += ",";
    }
  }
  str += ">";
  return (str);
}

double duco::vector::Vector::GetVal(int n) {
  if (n >= 0 && n < length) {
    return (vals[n]);
  } else {
    return (0);
  }
}
