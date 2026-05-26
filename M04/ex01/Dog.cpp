#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
  type = "Dog";
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Dog copy constructor called (deep copy)" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
  }
  return *this;
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Woof! Woof!" << std::endl; }

void Dog::setIdea(int index, const std::string &idea) {
  if (index >= 0 && index < 100)
    brain->ideas[index] = idea;
}

std::string Dog::getIdea(int index) const {
  if (index >= 0 && index < 100)
    return brain->ideas[index];
  return "";
}
