#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

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

void PhoneBook::addContact(void)
{
  std::cout << "Adding a new contact" << std::endl;
  Contact new_contact;

  while(new_contact.name.length() <= 0)
  {
    std::cout << "Please enter your name: ";
    if (!std::getline(std::cin, new_contact.name))
      exit(0);
    std::cout << std::endl;
  }

  while(new_contact.last_name.length() <= 0)
  {
    std::cout << "Please enter your last name: ";
    if (!std::getline(std::cin, new_contact.last_name))
      exit(0);
    std::cout << std::endl;
  }

  while(new_contact.nickname.length() <= 0)
  {
    std::cout << "Please enter your nickname: ";
    if (!std::getline(std::cin, new_contact.nickname))
      exit(0);
    std::cout << std::endl;
  }

  while(new_contact.phone_number.length() <= 0)
  {
    std::cout << "Please enter your phone number: ";
    if (!std::getline(std::cin, new_contact.phone_number))
      exit(0);
    std::cout << std::endl;
  }

  new_contact.setDarkestSecret();

  if (_index == 8)
    _index = 0;
  _contact_list[_index] = new_contact;
  _index++;
}

void PhoneBook::searchContact(void) {
  int index;
  std::string s_index;

  if (this->_index == 0) 
  {
      std::cout << "Phonebook is empty!" << std::endl;
      return;
  }

  Utils::printTable(_contact_list, 8);
  std::cout << "Index: ";
  if (!std::getline(std::cin, s_index))
    return ;
  index = std::atoi(s_index.c_str());
  while (index <= 0 || index > 8 || _contact_list[index - 1].name.empty())
  {
    std::cout << "Enter a correct Index: ";
    if (!std::getline(std::cin, s_index))
      return ;
    index = std::atoi(s_index.c_str());
  }
  std::cout << "First name: " << _contact_list[index - 1].name << std::endl;
  std::cout << "Last name: " << _contact_list[index - 1].last_name << std::endl;
  std::cout << "Nickname: " << _contact_list[index - 1].nickname << std::endl;
  std::cout << "Phone number: " << _contact_list[index - 1].phone_number << std::endl;
  _contact_list[index - 1].printSecret();
}
