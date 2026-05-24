#include "ClapTrap.hpp"

int main(void)
{
	// Test construction
	ClapTrap ct("Clappy");
	std::cout << std::endl;

	// Test attack
	ct.attack("Target1");
	std::cout << std::endl;

	// Test takeDamage
	ct.takeDamage(3);
	std::cout << std::endl;

	// Test beRepaired
	ct.beRepaired(5);
	std::cout << std::endl;

	// Test copy constructor
	ClapTrap ct2(ct);
	std::cout << std::endl;

	// Test copy assignment
	ClapTrap ct3("Temp");
	ct3 = ct;
	std::cout << std::endl;

	// Test no energy: drain all energy
	ClapTrap noEnergy("NoEP");
	for (int i = 0; i < 11; i++)
		noEnergy.attack("dummy");
	std::cout << std::endl;

	// Test no HP
	ClapTrap noHP("NoHP");
	noHP.takeDamage(10); // HP goes to 0
	noHP.attack("someone");
	noHP.beRepaired(5);
	std::cout << std::endl;

	// Destructors will be called here
	return 0;
}