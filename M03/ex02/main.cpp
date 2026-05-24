#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== Testing FragTrap Construction ===" << std::endl;
	FragTrap ft("Fraggy");
	std::cout << std::endl;

	std::cout << "=== Testing FragTrap attack (override) ===" << std::endl;
	ft.attack("Enemy");
	std::cout << std::endl;

	std::cout << "=== Testing highFivesGuys ===" << std::endl;
	ft.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== Testing takeDamage ===" << std::endl;
	ft.takeDamage(40);
	std::cout << std::endl;

	std::cout << "=== Testing beRepaired ===" << std::endl;
	ft.beRepaired(25);
	std::cout << std::endl;

	std::cout << "=== Testing copy ===" << std::endl;
	FragTrap ft2(ft);
	std::cout << std::endl;

	std::cout << "=== Testing assignment ===" << std::endl;
	FragTrap ft3("Temp");
	ft3 = ft;
	std::cout << std::endl;

	std::cout << "=== Testing destruction ===" << std::endl;
	return 0;
}