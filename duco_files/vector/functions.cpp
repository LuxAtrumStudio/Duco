#include "../duco_headers.hpp"
#include "functions.hpp"
#include <math.h>
#include <stdarg.h>
#include <string>
#include <vector>

double duco::vector::Dot(Vector v, Vector w) {
  double product = 0;
  if (v.length != w.length) {
    return (0);
  } else if (v.length == w.length) {
    for (int i = 0; i < v.length; i++) {
      product += (v.vals[i] * w.vals[i]);
    }
  }
  return (product);
}

duco::vector::Vector duco::vector::Cross(Vector v, Vector w) {
  Vector cross;
  if (v.length != 3 || w.length != 3) {
    return (cross);
  } else if (v.length == 3 && w.length == 3) {
    cross.PushBack((v.vals[1] * w.vals[2]) - (w.vals[1] * v.vals[2]));
    cross.PushBack((w.vals[0] * v.vals[2]) - (v.vals[0] * w.vals[2]));
    cross.PushBack((v.vals[0] * w.vals[1]) - (w.vals[0] * v.vals[1]));
  }
  return (cross);
}

duco::vector::Vector duco::vector::Add(Vector v, Vector w, double alpha,
                                       double beta) {
  Vector sum;
  v.ScalarMultiply(alpha);
  w.ScalarMultiply(beta);
  if (v.length != w.length) {
    return (sum);
  } else if (v.length == w.length) {
    for (int i = 0; i < v.length; i++) {
      sum.PushBack(v.vals[i] + w.vals[i]);
    }
  }
  return (sum);
}

double duco::vector::Angle(Vector v, Vector w) {
  double dot = Dot(v, w), vmag = v.Magnitude(), wmag = w.Magnitude();
  double angle = (dot) / (vmag + wmag);
  angle = acos(angle);
  return (angle);
}
