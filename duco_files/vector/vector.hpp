#ifndef DUCO_VECTOR_H_
#define DUCO_VECTOR_H_
#include <string>
#include <vector>
namespace duco {
namespace vector {
class Vector {
private:
public:
  // Structure public data
  int length;
  std::vector<double> vals;
  // Constructors and destructors
  Vector(double nvars = 0, ...);
  Vector(const Vector &clone);
  virtual ~Vector();
  // Data manipulation
  void SetVals(std::vector<double> vars);
  void PushBack(double val);
  void PopBack();
  // Local calculations
  double Sum();
  double Magnitude();
  void ScalarMultiply(double val);
  // Return functions
  std::vector<double> GetVector();
  std::string String();
};
}
}
#endif
