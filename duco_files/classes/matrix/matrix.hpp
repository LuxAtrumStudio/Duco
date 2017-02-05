#ifndef DUCO_CLASS_MATRIX
#define DUCO_CLASS_MATRIX
#include "../class_headers.hpp"
#include <string>
#include <vector>
namespace duco {
namespace matrix {
class Matrix {
public:
  // Constructors and destructor
  Matrix();
  Matrix(bool Identity, int nrow, int ncol);
  Matrix(int nrow, int ncol, ...);
  Matrix(std::vector<std::vector<double>> invals);
  Matrix(const Matrix &copy);
  ~Matrix();
  // Data manipulation
  void SetVals(int nrow, int ncol, ...);
  void SetVals(std::vector<std::vector<double>> invals);
  void PopBackRow();
  void PopBackCol();
  void PushBackRow(std::vector<double> row);
  void PushBackRow(duco::vector::Vector row);
  void PushBackCol(std::vector<double> col);
  void Resize(int nrow, int ncol, double val = 0);
  void Transpose();
  void SetVal(int row, int col, double val);
  // Internal functions
  void ScalarMultiply(double val);
  // Returning functions
  double Determinate();
  double Total();
  double Trace();
  // Data returning functions
  int GetRows();
  int GetCols();
  std::pair<int, int> GetSize();
  std::vector<std::vector<double>> GetMatrix();
  std::string GetString();
  double GetVal(int row, int col);
  std::vector<duco::vector::Vector> GetVectors();

private:
  int rows, cols;
  std::vector<std::vector<double>> vals;
  double RecursiveDeterminate(std::vector<std::vector<double>> mat);
};
}
}
#endif
