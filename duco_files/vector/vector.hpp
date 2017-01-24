#ifndef DUCO_VECTOR_HPP
#define DUCO_VECTOR_HPP
#include <string>
#include <vector>
namespace duco {
namespace vector {
class Vector {
public:
  // Structure public data
  int length;
  std::vector<double> vals;
  // Constructors and destructors
  Vector(double nvars = 0, ...);
  Vector(const Vector &clone);
  virtual ~Vector();
  // Data manipulation
  void PopBack();
  void PushBack(double val);
  void Resize(int nvars);
  void SetVals(Vector vars);
  void SetVals(std::vector<double> vars);
  // Local calculations
  double Magnitude();
  double Sum();
  void ScalarMultiply(double val);
  // Return functions
  std::vector<double> GetVector();
  std::string String();

private:
};
}
}
#endif
