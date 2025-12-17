#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main(void)
{
  PhoneBook phonebook;
  std::string command;

  std::cout << "Phonebook: ";
  if (!std::getline(std::cin, command))
    exit(0);

  while (1)
  {
    if (command == "ADD")
      phonebook.addContact();
    else if (command == "SEARCH")
      phonebook.searchContact();
    else if (command == "EXIT")
      return (0);
    std::cout << "Phonebook: ";
    if (!std::getline(std::cin, command))
      exit(0);
  }
}
