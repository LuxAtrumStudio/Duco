#ifndef DUCO_ARRAY_HPP
#define DUCO_ARRAY_HPP
#include "../vector/vector.hpp"
#include <string>
#include <vector>
namespace duco {
namespace matrix {
class Matrix {
public:
  // Structure public data
  int valcount = 0, rows = 0, cols = 0;
  std::vector<std::vector<double>> vals;
  // Constructors ad destructors
  Matrix(int nrow = 0, int ncol = 0, ...);
  Matrix(int nrow = 0, int ncol = 0);
  Matrix(const Matrix &clone);
  ~Matrix();
  // Data manipulation
  void PopBackCol();
  void PopBackRow();
  void PushBackCol(vector::Vector col);
  void PushBackCol(std::vector<double> col);
  void PushBackRow(vector::Vector row);
  void PushBackRow(std::vector<double> row);
  void Resize(int nrow, int ncol);
  void SetVals(Matrix vars);
  void SetVals(std::vector<std::vector<double>> vars);
  void Transpose();
  // Local calculations
  double Determinate();
  void ScalarMultiply(double val);
  double Sum();
  void SumCols();
  void SumRows();
  void VectorMultiply(vector::Vector vec, int col = 0);
  void VectorMultiply(std::vector<double> vec, int col = 0);
  // Return functions
  std::vector<std::vector<double>> GetMatrix();
  std::string String();

private:
  double SubDeterminate(std::vector<std::vector<double>> matrix);
};
}
}
#endif
