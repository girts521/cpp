#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== Testing ScavTrap Construction ===" << std::endl;
	ScavTrap st("Guardian");
	std::cout << std::endl;

	std::cout << "=== Testing ScavTrap attack (override) ===" << std::endl;
	st.attack("Bandit");
	std::cout << std::endl;

	std::cout << "=== Testing guardGate ===" << std::endl;
	st.guardGate();
	std::cout << std::endl;

	std::cout << "=== Testing takeDamage ===" << std::endl;
	st.takeDamage(30);
	std::cout << std::endl;

	std::cout << "=== Testing beRepaired ===" << std::endl;
	st.beRepaired(15);
	std::cout << std::endl;

	std::cout << "=== Testing ClapTrap construction and ScavTrap copy ===" << std::endl;
	ScavTrap st2(st);
	std::cout << std::endl;

	std::cout << "=== Testing assignment ===" << std::endl;
	ScavTrap st3("Temp");
	st3 = st;
	std::cout << std::endl;

	std::cout << "=== Testing destruction ===" << std::endl;
	return 0;
}