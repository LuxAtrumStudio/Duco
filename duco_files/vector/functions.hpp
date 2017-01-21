#ifndef DUCO_VECTOR_FUNCTIONS_H_
#define DUCO_VECTOR_FUNCTIONS_H_
#include "vector.hpp"
namespace duco {
namespace vector {
double Dot(Vector v, Vector w);
Vector Cross(Vector v, Vector w);
Vector Add(Vector v, Vector w, double alpha = 1, double beta = 1);
double Angle(Vector v, Vector w);
}
}
#endif
