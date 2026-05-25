#include "Zombie.hpp"
#include <iostream>

int main(void) {
  std::cout << "--- TESTING STACK ALLOCATION ---" << std::endl;
  randomChump("Stack_Walker");

  std::cout << "\n--- TESTING HEAP ALLOCATION ---" << std::endl;
  Zombie *heapZombie = newZombie("Heap_Crawler");

  heapZombie->announce();

  std::cout << "\n--- CLEANING UP HEAP ---" << std::endl;
  delete heapZombie;

  std::cout << "\n--- PROGRAM END ---" << std::endl;
  return 0;
}
