#ifndef DUCO_ARRAY_H_
#define DUCO_ARRAY_H_
#include <string>
#include <vector>
namespace duco {
namespace matrix {
class Matrix {
private:
  int valcount, rows, cols;
  std::vector<std::vector<double>> vals;
  double SubDeterminate(std::vector<std::vector<double>> matrix);

public:
  Matrix(int nrow = 0, int ncol = 0, ...);
  Matrix(const Matrix &clone);
  virtual ~Matrix();
  double Determinate();
  void Transpose();
  void SumRows();
  void SumCols();
  double Sum();
  std::vector<std::vector<double>> GetMatrix();
  std::string String();
};
}
}
#endif
