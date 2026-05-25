#include "Zombie.hpp"
#include <iostream>
#include <new>

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0)
    return NULL;

  Zombie *horde = new (std::nothrow) Zombie[N];
  if (!horde) {
    std::cout << "The OS failed to allocate memory, try to pass a smaller N!"
              << std::endl;
    return NULL;
  }

  for (int i = 0; i < N; i++)
    horde[i].setName(name);

  return horde;
}
