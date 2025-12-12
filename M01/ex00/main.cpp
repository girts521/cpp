#include "Zombie.hpp"

int main(void)
{
  Zombie *new_zombie = newZombie("Carl");

  new_zombie->announce();

  randomChump("tommy");

  delete new_zombie;
}
