#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    int N = 5;
    
    std::cout << "--- ALLOCATING HORDE OF " << N << " ZOMBIES ---" << std::endl;
    Zombie *horde = zombieHorde(N, "Tobby");

    if (!horde)
    {
        std::cout << "Horde allocation failed (Invalid N)." << std::endl;
        return 1;
    }

    std::cout << "\n--- HORDE ATTACK ---" << std::endl;
    for(int i = 0; i < N; i++)
        horde[i].announce();

    std::cout << "\n--- DESTROYING HORDE ---" << std::endl;
    delete[] horde;

    std::cout << "\n--- PROGRAM END ---" << std::endl;
    return 0;
}
