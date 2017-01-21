#ifndef DUCO_MATRIX_FUNCTIONS_H_
#define DUCO_MATRIX_FUNCTIONS_H_
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
