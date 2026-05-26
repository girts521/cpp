#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "=== Test 1: Virtual polymorphism (Animal/Dog/Cat) ==="
            << std::endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << "Dog type: " << j->getType() << std::endl;
  std::cout << "Cat type: " << i->getType() << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  std::cout << std::endl
            << "=== Test 2: Wrong polymorphism (WrongAnimal/WrongCat) ==="
            << std::endl;
  const WrongAnimal *wrong = new WrongAnimal();
  const WrongAnimal *wcat = new WrongCat();

  std::cout << "WrongCat type: " << wcat->getType() << std::endl;
  wcat->makeSound();

  delete wrong;
  delete wcat;

  std::cout << std::endl
            << "=== Test 3: Direct Cat and Dog objects ===" << std::endl;
  Dog dog;
  Cat cat;
  dog.makeSound();
  cat.makeSound();

  std::cout << std::endl << "=== Test 4: Copy construction ===" << std::endl;
  Dog originalDog;
  Dog copyDog(originalDog);
  copyDog.makeSound();

  std::cout << std::endl << "=== Test 5: Assignment ===" << std::endl;
  Dog dog1;
  Dog dog2;
  dog2 = dog1;
  dog2.makeSound();

  return 0;
}
