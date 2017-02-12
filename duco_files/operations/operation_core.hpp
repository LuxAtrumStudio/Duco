#ifndef DUCO_OPERATION
#define DUCO_OPERATION
#include <functional>
#include <map>
#include <string>
namespace duco {
extern std::map<std::string, std::function<double(double)>> unaryopmap;
extern std::map<std::string, std::function<double(double, double)>> binaryopmap;
void LoadOperMap();
}
#endif
