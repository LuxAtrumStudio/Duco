#include "../duco_headers.hpp"
#include "functions.hpp"
#include <math.h>
#include <stdarg.h>
#include <string>
#include <vector>

double duco::vector::Dot(Vector a, Vector b) {
  double product = 0;
  if (a.length != b.length) {
    LogLoc(WARNING, "Vectors must have same length for dot product", lvec,
           "Dot");
    return (0);
  } else if (a.length == b.length) {
    for (int i = 0; i < a.length; i++) {
      product += (a.vals[i] * b.vals[i]);
    }
  }
  return (product);
}

duco::vector::Vector duco::vector::Cross(Vector a, Vector b) {
  Vector cross;
  if (a.length != 3 || b.length != 3) {
    LogLoc(WARNING, "Vectors must have length of 3 for cross product", lvec,
           "Cross");
    return (cross);
  } else if (a.length == 3 && b.length == 3) {
    cross.PushBack((a.vals[1] * b.vals[2]) - (b.vals[1] * a.vals[2]));
    cross.PushBack((b.vals[0] * a.vals[2]) - (a.vals[0] * b.vals[2]));
    cross.PushBack((a.vals[0] * b.vals[1]) - (b.vals[0] * a.vals[1]));
  }
  return (cross);
}

duco::vector::Vector duco::vector::Add(Vector a, Vector b, double alpha,
                                       double beta) {
  Vector sum;
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.length != b.length) {
    LogLoc(WARNING, "Vectors must have same length for addition", lvec, "Add");
    return (sum);
  } else if (a.length == b.length) {
    for (int i = 0; i < a.length; i++) {
      sum.PushBack(a.vals[i] + b.vals[i]);
    }
  }
  return (sum);
}

double duco::vector::Angle(Vector a, Vector b) {
  double dot = Dot(a, b), amag = a.Magnitude(), bmag = b.Magnitude();
  double angle = (dot) / (amag + bmag);
  angle = acos(angle);
  return (angle);
}

duco::vector::Vector duco::vector::Multiply(Vector a, Vector b, double alpha,
                                            double beta) {
  Vector product;
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.length != b.length) {
    LogLoc(WARNING, "Vectors must have same length for multiplication", lvec,
           "Multiply");
    return (product);
  } else if (a.length == b.length) {
    for (int i = 0; i < a.length; i++) {
      product.PushBack(a.vals[i] * b.vals[i]);
    }
  }
  return (product);
}
duco::vector::Vector duco::vector::Divide(Vector a, Vector b, double alpha,
                                          double beta) {
  Vector product;
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.length != b.length) {
    LogLoc(WARNING, "Vectors must have same length for division", lvec,
           "Divide");
    return (product);
  } else if (a.length == b.length) {
    for (int i = 0; i < a.length; i++) {
      product.PushBack(a.vals[i] / b.vals[i]);
    }
  }
  return (product);
}
