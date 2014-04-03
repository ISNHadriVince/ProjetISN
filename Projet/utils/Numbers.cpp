#include "Numbers.hpp"
#include <sstream>

int parseInt(std::string str) {
    std::istringstream flux(str);
    int i;
    flux >> i;
    return i;
}
