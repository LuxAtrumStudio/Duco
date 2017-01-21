#include "../manipulation/manipulation.hpp"
#include "functions.hpp"
#include "vector.hpp"
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
