#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n\n";

	ScavTrap	Scav("Jean-Eudes");
	ScavTrap	John = Scav;

	std::cout << std::endl;

	John.attack("his target");
	John.takeDamage(400);
	John.guardGate();

	std::cout << std::endl;

	Scav.attack("Judas");
	Scav.takeDamage(50);
	Scav.beRepaired(50);
	Scav.guardGate();
	Scav.~ScavTrap();
	
	std::cout << "\n\n";

	ClapTrap	Clap("Bertrand");

	std::cout << std::endl;

	Clap.takeDamage(5);
	Clap.attack("Pikachu");
	for (int i = 0; i < 10; i++)
		Clap.beRepaired(10);
//	Clap.guardGate();

	std::cout << "\n\n";

	return (0);
}
