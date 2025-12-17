#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

std::string Utils::truncate(std::string str)
{
  if (str.length() > 10) return str.substr(0, 9) + ".";
  return str;
}

void Utils::printTable(Contact contacts[], int count)
{
  std::cout << "|" << std::setw(10) << "index" << "|"
            << std::setw(10) << "First name" << "|"
            << std::setw(10) << "Last name" << "|"
            << std::setw(10) << "Nickname" << "|" << std::endl;

  for (int i = 0; i < count; i++)
  {
    if (contacts[i].name.length() > 0)
      std::cout << "|" << std::setw(10) << i + 1 << "|"
              << std::setw(10) << Utils::truncate(contacts[i].name) << "|"
              << std::setw(10) << Utils::truncate(contacts[i].last_name) << "|" 
              << std::setw(10) << Utils::truncate(contacts[i].nickname) << "|" << std::endl;
  }
}

void Utils::setVar(std::string &varRef, const std::string &varName)
{
  while(varRef.length() <= 0)
  {
    std::cout << varName;
    if (!std::getline(std::cin, varRef))
      exit(0);
    std::cout << std::endl;
  }
}
