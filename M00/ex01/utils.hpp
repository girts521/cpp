#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "Contact.hpp"

namespace Utils 
{
  std::string truncate(std::string str); 
  void printTable(Contact contacts[], int count);
}

#endif
