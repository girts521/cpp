#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
  std::cout << "Default constructor has been called" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
  std::cout << "Default constructor with param has been called" << std::endl;
}

Zombie::Zombie(const Zombie &src) : name(src.name) 
{
  std::cout << "The copy constructor has been called" << std::endl;
}

Zombie &Zombie::operator=(const Zombie &src)
{
  if (this == &src) return *this;
  this->name = src.name;
  return *this;
}

Zombie::~Zombie(void)
{
  std::cout << this->name << " The standard destructor has been called" << std::endl;
}

void Zombie::announce(void)
{
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
  this->name = name;
}
