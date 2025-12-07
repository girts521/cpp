#include <string>
#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
  std::cout << "The default contructor has been called" << std::endl;
}

Contact::Contact(const Contact &src) : name(src.name), last_name(src.last_name), nickname(src.nickname), phone_number(src.phone_number)
{
  std::cout << "The copy contructor has been called" << std::endl;
}

Contact& Contact::operator=(const Contact &src)
{
  std::cout << "The assignment contructor has been called" << std::endl;
  if (this == &src) return *this;
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
