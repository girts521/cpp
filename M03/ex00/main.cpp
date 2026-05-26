#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
  ClapTrap ct("Clappy");
  std::cout << std::endl;

  ct.attack("Target1");
  std::cout << std::endl;

  ct.takeDamage(3);
  std::cout << std::endl;

  ct.beRepaired(5);
  std::cout << std::endl;

  ClapTrap ct2(ct);
  std::cout << std::endl;

  ClapTrap ct3("Temp");
  ct3 = ct;
  std::cout << std::endl;

  ClapTrap noEnergy("NoEP");
  for (int i = 0; i < 11; i++)
    noEnergy.attack("dummy");
  std::cout << std::endl;

  ClapTrap noHP("NoHP");
  noHP.takeDamage(10);
  noHP.attack("someone");
  noHP.beRepaired(5);
  std::cout << std::endl;

  return 0;
}
