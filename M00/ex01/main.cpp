#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main(void) {
  PhoneBook phonebook;
  std::string command;

  while (true) {
    std::cout << "Phonebook: ";

    if (!std::getline(std::cin, command)) {
      std::cout << "\nEOF detected. Exiting securely." << std::endl;
      exit(0);
    }

    if (command == "ADD") {
      phonebook.addContact();
    } else if (command == "SEARCH") {
      phonebook.searchContact();
    } else if (command == "EXIT") {
      return (0);
    } else if (!command.empty()) {
      std::cout
          << "Error: Invalid command. Only ADD, SEARCH, or EXIT are accepted."
          << std::endl;
    }
  }
  return (0);
}
