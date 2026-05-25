#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void) {
  std::cout << "The default constructor has been called" << std::endl;
  this->_index = 0;
}

PhoneBook::PhoneBook(const PhoneBook &src) : _index(src._index) {
  std::cout << "The copy constructor has been called" << std::endl;

  for (int i = 0; i < 8; i++)
    this->_contact_list[i] = src._contact_list[i];
}

PhoneBook::~PhoneBook(void) {
  std::cout << "The destructor has been called" << std::endl;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &src) {
  std::cout << "The assignment operator has been called" << std::endl;

  if (this == &src)
    return *this;

  this->_index = src._index;
  for (int i = 0; i < 8; i++)
    this->_contact_list[i] = src._contact_list[i];

  return *this;
}

void PhoneBook::addContact(void) {
  Contact new_contact;

  std::cout << "Adding a new contact" << std::endl;

  new_contact.setName();
  new_contact.setLastName();
  new_contact.setNickname();
  new_contact.setPhoneNumber();
  new_contact.setDarkestSecret();

  if (_index == 8)
    _index = 0;

  _contact_list[_index++] = new_contact;
}

void PhoneBook::searchContact(void) {
  int index;
  std::string s_index;

  if (this->_index == 0) {
    std::cout << "Phonebook is empty!" << std::endl;
    return;
  }

  Utils::printTable(_contact_list, 8);

  while (true) {
    std::cout << "Index: ";
    if (!std::getline(std::cin, s_index))
      exit(0);

    if (s_index.length() == 1 && s_index[0] >= '1' && s_index[0] <= '8') {
      index = s_index[0] - '0';

      if (!_contact_list[index - 1].getName().empty()) {
        break;
      }
    }

    std::cout << "Error: Invalid index. Enter a valid number (1-8) for an "
                 "existing contact."
              << std::endl;
  }

  std::cout << "First name: " << _contact_list[index - 1].getName()
            << std::endl;
  std::cout << "Last name: " << _contact_list[index - 1].getLastName()
            << std::endl;
  std::cout << "Nickname: " << _contact_list[index - 1].getNickname()
            << std::endl;
  std::cout << "Phone number: " << _contact_list[index - 1].getPhoneNumber()
            << std::endl;
  std::cout << "Darkest secret: " << _contact_list[index - 1].getDarkestSecret()
            << std::endl;
}
