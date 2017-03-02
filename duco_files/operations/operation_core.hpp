#ifndef DUCO_OPERATION_HPP
#define DUCO_OPERATION_HPP
#include "method/method.hpp"
#include <functional>
#include <map>
#include <string>
namespace duco {
namespace operation {
extern std::map<std::string, Method> ops;
void LoadArithmeticOperations();
void LoadTrigonometryOperations();
}
}
#endif
