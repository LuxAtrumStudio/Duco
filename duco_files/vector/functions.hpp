#ifndef DUCO_VECTOR_FUNCTIONS_HPP
#define DUCO_VECTOR_FUNCTIONS_HPP
#include "vector.hpp"
namespace duco {
namespace vector {
double Dot(Vector a, Vector b);
Vector Cross(Vector a, Vector b);
Vector Add(Vector a, Vector b, double alpha = 1, double beta = 1);
double Angle(Vector a, Vector b);
Vector Multiply(Vector a, Vector b, double alpha = 1, double beta = 1);
Vector Divide(Vector a, Vector b, double alpha = 1, double beta = 1);
}
}
#endif
