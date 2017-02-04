#include "../duco_headers.hpp"
#include "exponential.hpp"
#include <math.h>
#include <string>

double duco::exponential::Exp(double val) { return (exp(val)); }
double duco::exponential::Pow(double base, double exponent) {
  return (pow(base, exponent));
}
double duco::exponential::Log(double val, double base) {
  if (base == 10) {
    return (log10(val));
  } else {
    return (log10(val) / log10(base));
  }
}
double duco::exponential::Ln(double val) { return (log(val)); }
double duco::exponential::Root(double val, double degree) {
  if (degree == 2) {
    return (sqrt(val));
  } else if (degree == 3) {
    return (cbrt(val));
  } else {
    return (pow(val, (1.0 / degree)));
  }
}
