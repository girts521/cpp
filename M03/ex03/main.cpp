#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "=== Testing DiamondTrap Construction ===" << std::endl;
	DiamondTrap dt("Girts");
	std::cout << std::endl;

	std::cout << "=== Testing whoAmI ===" << std::endl;
	dt.whoAmI();
	std::cout << std::endl;

	std::cout << "=== Testing attack (should use ScavTrap's) ===" << std::endl;
	dt.attack("Target");
	std::cout << std::endl;

	std::cout << "=== Testing guardGate (inherited) ===" << std::endl;
	dt.guardGate();
	std::cout << std::endl;

	std::cout << "=== Testing highFivesGuys (inherited) ===" << std::endl;
	dt.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== Testing takeDamage ===" << std::endl;
	dt.takeDamage(30);
	std::cout << std::endl;

	std::cout << "=== Testing beRepaired ===" << std::endl;
	dt.beRepaired(20);
	std::cout << std::endl;

	std::cout << "=== Testing copy construction ===" << std::endl;
	DiamondTrap dt2(dt);
	dt2.whoAmI();
	std::cout << std::endl;

	std::cout << "=== Testing assignment ===" << std::endl;
	DiamondTrap dt3("Temp");
	dt3 = dt;
	dt3.whoAmI();
	std::cout << std::endl;

	std::cout << "=== Testing destruction ===" << std::endl;
	return 0;
}