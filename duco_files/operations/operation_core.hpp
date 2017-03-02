#ifndef DUCO_OPERATION_HPP
#define DUCO_OPERATION_HPP
#include <functional>
#include <map>
#include <string>
namespace duco {
namespace operation {
extern std::map<std::string, std::function<double(double, double)>> ops;
void LoadArithmeticOperations();
}
}
#endif
