#ifndef DUCO_MATRIX_FUNCTIONS_HPP
#define DUCO_MATRIX_FUNCTIONS_HPP
#include "matrix.hpp"
namespace duco {
namespace matrix {
Matrix Product(Matrix a, Matrix b, double alpha = 1, double beta = 1);
Matrix Add(Matrix a, Matrix b, double alpha = 1, double beta = 1);
Matrix Multiply(Matrix a, Matrix b, double alpha = 1, double beta = 1);
Matrix Divide(Matrix a, Matrix b, double alpha = 1, double beta = 1);
}
}
#endif
