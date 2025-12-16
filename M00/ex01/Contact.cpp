#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Contact::Contact(void)
{
  std::cout << "The default contructor has been called" << std::endl;
}

Contact::Contact(const Contact &src)
    : _darkest_secret(src._darkest_secret),
      name(src.name), last_name(src.last_name), nickname(src.nickname),
      phone_number(src.phone_number) 
{
  std::cout << "The copy contructor has been called" << std::endl;
}

Contact &Contact::operator=(const Contact &src)
{
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

Contact::~Contact(void)
{
  std::cout << "The Destructor has been called" << std::endl;
}

void Contact::setDarkestSecret(void)
{
  while(_darkest_secret.length() <= 0)
  {
    std::cout << "Please enter your darkest secret: ";
    if (!std::getline(std::cin, _darkest_secret))
      exit(0);
    std::cout << std::endl;
  }
}

void Contact::printSecret(void)
{
  std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}
