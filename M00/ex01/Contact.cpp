#include <string>
#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
  std::cout << "The default contructor has been called" << std::endl;
}

Contact::Contact(const Contact &src)
{
  std::cout << "The copy contructor has been called" << std::endl;
}

Contact& Contact::operator=(const Contact &src)
{
  std::cout << "The assignment contructor has been called" << std::endl;
}

Contact::~Contact(void)
{
  std::cout << "The Destructor has been called" << std::endl;
}
