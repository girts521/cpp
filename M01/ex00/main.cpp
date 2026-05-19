// #include "Zombie.hpp"
//
// int main(void)
// {
//   Zombie *new_zombie = newZombie("Carl");
//
//   new_zombie->announce();
//
//   randomChump("tommy");
//
//   delete new_zombie;
// }
//

#include "Zombie.hpp"

int main(void) {
    std::cout << "--- TESTING STACK ALLOCATION ---" << std::endl;
    // randomChump handles creation, announcement, and automatic destruction.
    randomChump("Stack_Walker");

    std::cout << "\n--- TESTING HEAP ALLOCATION ---" << std::endl;
    // newZombie creates the object, but we must handle it.
    Zombie* heapZombie = newZombie("Heap_Crawler");
    
    // We must manually make it announce
    heapZombie->announce();

    std::cout << "\n--- CLEANING UP HEAP ---" << std::endl;
    // If we do not call delete, we fail the memory leak check.
    delete heapZombie;

    std::cout << "\n--- PROGRAM END ---" << std::endl;
    return 0;
}
