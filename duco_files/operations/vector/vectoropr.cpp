#include "../../classes/class_headers.hpp"
#include "vectoropr.hpp"
#include <math.h>
#include <vector>

double duco::vector::Dot(Vector a, Vector b, double alpha, double beta) {
  double product = 0;
  std::vector<double> veca = a.GetVector(), vecb = b.GetVector();
  if (veca.size() != vecb.size()) {
    return (0);
  } else if (veca.size() == vecb.size()) {
    for (int i = 0; i < veca.size(); i++) {
      product += (veca[i] * vecb[i]);
    }
  }
  return (product);
}

duco::vector::Vector duco::vector::Cross(Vector a, Vector b, double alpha,
                                         double beta) {
  Vector cross;
  std::vector<double> veca = a.GetVector(), vecb = b.GetVector();
  if (veca.size() != 3 || vecb.size() != 3) {
    return (cross);
  } else if (veca.size() == 3 && vecb.size() == 3) {
    cross.PushBack((veca[1] * vecb[2]) - (vecb[1] * veca[2]));
    cross.PushBack((vecb[0] * veca[2]) - (veca[0] * vecb[2]));
    cross.PushBack((veca[0] * vecb[1]) - (vecb[0] * veca[1]));
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
  std::vector<double> veca = a.GetVector(), vecb = b.GetVector();
  if (veca.size() != vecb.size()) {
    return (sum);
  } else if (veca.size() == vecb.size()) {
    for (int i = 0; i < veca.size(); i++) {
      sum.PushBack(veca[i] + vecb[i]);
    }
  }
  return (sum);
}

double duco::vector::Angle(Vector a, Vector b, double alpha, double beta) {
  double dot = Dot(a, b), amag = a.Magnitude(), bmag = b.Magnitude();
  double angle = (dot) / (amag + bmag);
  angle = acos(angle);
  return (angle);
}

duco::vector::Vector duco::vector::ElementMultiply(Vector a, Vector b,
                                                   double alpha, double beta) {
  Vector product;
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  std::vector<double> veca = a.GetVector(), vecb = b.GetVector();
  if (veca.size() != vecb.size()) {
    return (product);
  } else if (veca.size() == vecb.size()) {
    for (int i = 0; i < veca.size(); i++) {
      product.PushBack(veca[i] * vecb[i]);
    }
  }
  return (product);
}
duco::vector::Vector duco::vector::ElementDivide(Vector a, Vector b,
                                                 double alpha, double beta) {
  Vector product;
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  std::vector<double> veca = a.GetVector(), vecb = b.GetVector();
  if (veca.size() != vecb.size()) {
    return (product);
  } else if (veca.size() == vecb.size()) {
    for (int i = 0; i < veca.size(); i++) {
      product.PushBack(veca[i] / vecb[i]);
    }
  }
  return (product);
}
