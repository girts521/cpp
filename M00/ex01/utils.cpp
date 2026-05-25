#include "utils.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>

std::string Utils::truncate(std::string str) {
  if (str.length() > 10)
    return str.substr(0, 9) + ".";
  return str;
}

void Utils::printTable(Contact contacts[], int count) {
  std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10)
            << "First name" << "|" << std::setw(10) << "Last name" << "|"
            << std::setw(10) << "Nickname" << "|" << std::endl;

  for (int i = 0; i < count; i++) {
    if (contacts[i].getName().length() > 0)
      std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10)
                << Utils::truncate(contacts[i].getName()) << "|"
                << std::setw(10) << Utils::truncate(contacts[i].getLastName())
                << "|" << std::setw(10)
                << Utils::truncate(contacts[i].getNickname()) << "|"
                << std::endl;
  }
}
