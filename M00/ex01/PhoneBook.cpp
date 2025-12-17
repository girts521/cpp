#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
  std::cout << "The default constructor has been called" << std::endl;
  this->_index = 0;
}

PhoneBook::PhoneBook(const PhoneBook &src) : _index(src._index)
{
  std::cout << "The copy constructor has been called" << std::endl;

  for (int i = 0; i < 8; i++)
    this->_contact_list[i] = src._contact_list[i];
}

PhoneBook::~PhoneBook(void)
{
  std::cout << "The destructor has been called" << std::endl;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &src)
{
  std::cout << "The assignment operator has been called" << std::endl;

  if (this == &src) return *this;

  this->_index = src._index;
  for (int i = 0; i < 8; i++)
    this->_contact_list[i] = src._contact_list[i];

  return *this;
}

void PhoneBook::addContact(void)
{
  Contact new_contact;

  std::cout << "Adding a new contact" << std::endl;

  Utils::setVar(new_contact.name, "Please enter your name: ");
  Utils::setVar(new_contact.last_name, "Please enter your last name: ");
  Utils::setVar(new_contact.nickname, "Please enter your nickname: ");
  Utils::setVar(new_contact.phone_number, "Please enter your phone number: ");
  new_contact.setDarkestSecret();

  if (_index == 8) _index = 0;
  _contact_list[_index++] = new_contact;
}

void PhoneBook::searchContact(void)
{
  int index;
  std::string s_index;

  if (this->_index == 0) 
  {
      std::cout << "Phonebook is empty!" << std::endl;
      return;
  }

  Utils::printTable(_contact_list, 8);
  std::cout << "Index: ";
  if (!std::getline(std::cin, s_index)) return;
  index = std::atoi(s_index.c_str());

  while (index <= 0 || index > 8 || _contact_list[index - 1].name.empty())
  {
    std::cout << "Enter a correct Index: ";
    if (!std::getline(std::cin, s_index)) return;
    index = std::atoi(s_index.c_str());
  }

  std::cout << "First name: " << _contact_list[index - 1].name << std::endl;
  std::cout << "Last name: " << _contact_list[index - 1].last_name << std::endl;
  std::cout << "Nickname: " << _contact_list[index - 1].nickname << std::endl;
  std::cout << "Phone number: " << _contact_list[index - 1].phone_number << std::endl;
  _contact_list[index - 1].printSecret();
}
