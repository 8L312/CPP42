#include "ClapTrap.hpp"

int main()
{
	ClapTrap	random;
	ClapTrap	Judas("Judas");

	ClapTrap	Fedor = Judas;
	ClapTrap	Pierre(Fedor);

	std::cout << std::endl;

	random.takeDamage(100);
	random.beRepaired(42);
	random.takeDamage(1);
	Judas.takeDamage(5);
	Judas.attack("Pikachu");
	Judas.beRepaired(10);

	std::cout << std::endl;

	return (0);
}
