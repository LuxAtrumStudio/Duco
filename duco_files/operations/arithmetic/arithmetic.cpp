#include "arithmetic.hpp"
#include <cmath>
#include <pessum.h>

double duco::operation::arithmetic::Add(double a, double b) { return (a + b); }

double duco::operation::arithmetic::Sub(double a, double b) { return (a - b); }

double duco::operation::arithmetic::Mul(double a, double b) { return (a * b); }

double duco::operation::arithmetic::Div(double a, double b) {
  if (b != 0) {
    return (a / b);
  } else if (b == 0) {
    pessum::logging::Log("warning", "Dividing by 0 produces Nan", "duc/ope/ari",
                         "Div");
  }
  return (0.0);
}

double duco::operation::arithmetic::Round(double a, int integer) {
  a *= pow(10, integer);
  if (fmod(a, 0.5) == 0) {
    if (fmod(a + 0.5, 2) == 0) {
      a += 0.5;
    } else {
      a -= 0.5;
    }
  } else {
    a += 0.5;
    a = floor(a);
  }
  a /= pow(10, integer);
  return (a);
}

double duco::operation::arithmetic::Floor(double a, int integer) {
  a *= pow(10, integer);
  a = floor(a);
  a /= pow(10, integer);
  return (a);
}

double duco::operation::arithmetic::Ceil(double a, int integer) {
  a *= pow(10, integer);
  a = ceil(a);
  a /= pow(10, integer);
  return (a);
}

double duco::operation::arithmetic::Pow(double a, double b) {
  a = pow(a, b);
  return (a);
}

double duco::operation::arithmetic::Root(double a, double b) {
  if (a < 0.0) {
    pessum::logging::Log("warning",
                         "Root of number less than zero produces Nan",
                         "duc/ope/ari", "Root");
  } else {
    a = pow(a, (1.0 / b));
  }
  return (a);
}

double duco::operation::arithmetic::Log(double a, double b) {
  if (a == 0 || b == 0) {
    pessum::logging::Log("warning", "Input is out of domain", "duc/ope/ari",
                         "Log");
  } else if (a < 0 || b < 0) {
    pessum::logging::Log("warning", "Input results in nonreal answer",
                         "duc/ope/ari", "Log");
  } else {
    a = (log(a) / log(b));
  }
  return (a);
}

double duco::operation::arithmetic::Abs(double a) { return (fabs(a)); }

double duco::operation::arithmetic::Hypot(double a, double b) {
  return (sqrt(pow(a, 2) + pow(b, 2)));
}
