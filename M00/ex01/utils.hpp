#ifndef UTILS_HPP
#define UTILS_HPP

#include "Contact.hpp"
#include <string>

namespace Utils {
std::string truncate(std::string str);
void printTable(Contact contacts[], int count);
} // namespace Utils

#endif
