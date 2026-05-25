#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

Contact::Contact(void) {
  std::cout << "The default contructor has been called" << std::endl;
}

Contact::Contact(const Contact &src)
    : _darkest_secret(src._darkest_secret), name(src.name),
      last_name(src.last_name), nickname(src.nickname),
      phone_number(src.phone_number) {
  std::cout << "The copy contructor has been called" << std::endl;
}

Contact &Contact::operator=(const Contact &src) {
  std::cout << "The assignment contructor has been called" << std::endl;

  if (this == &src)
    return *this;

  this->_darkest_secret = src._darkest_secret;
  this->name = src.name;
  this->last_name = src.last_name;
  this->nickname = src.nickname;
  this->phone_number = src.phone_number;

  return *this;
}

Contact::~Contact(void) {
  std::cout << "The Destructor has been called" << std::endl;
}

std::string Contact::getName(void) const { return this->name; }

std::string Contact::getLastName(void) const { return this->last_name; }

std::string Contact::getNickname(void) const { return this->nickname; }

std::string Contact::getPhoneNumber(void) const { return this->phone_number; }

std::string Contact::getDarkestSecret(void) const {
  return this->_darkest_secret;
}

void Contact::setName(void) {
  this->name = "";
  while (this->name.empty()) {
    std::cout << "Please enter first name: ";
    if (!std::getline(std::cin, this->name))
      exit(0);
    if (this->name.empty())
      std::cout << "Error: First name cannot be empty." << std::endl;
  }
}

void Contact::setLastName(void) {
  this->last_name = "";
  while (this->last_name.empty()) {
    std::cout << "Please enter last name: ";
    if (!std::getline(std::cin, this->last_name))
      exit(0);
    if (this->last_name.empty())
      std::cout << "Error: Last name cannot be empty." << std::endl;
  }
}

void Contact::setNickname(void) {
  this->nickname = "";
  while (this->nickname.empty()) {
    std::cout << "Please enter nickname: ";
    if (!std::getline(std::cin, this->nickname))
      exit(0);
    if (this->nickname.empty())
      std::cout << "Error: Nickname cannot be empty." << std::endl;
  }
}

void Contact::setPhoneNumber(void) {
  this->phone_number = "";
  while (this->phone_number.empty()) {
    std::cout << "Please enter phone number: ";
    if (!std::getline(std::cin, this->phone_number))
      exit(0);
    if (this->phone_number.empty())
      std::cout << "Error: Phone number cannot be empty." << std::endl;
  }
}

void Contact::setDarkestSecret(void) {
  this->_darkest_secret = "";
  while (this->_darkest_secret.empty()) {
    std::cout << "Please enter your darkest secret: ";
    if (!std::getline(std::cin, this->_darkest_secret))
      exit(0);
    if (this->_darkest_secret.empty())
      std::cout << "Error: Darkest secret cannot be empty." << std::endl;
  }
}
