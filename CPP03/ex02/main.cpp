#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\n\n";

	FragTrap	Frag("Fraggy");

	Frag.attack("le pape");
	Frag.takeDamage(8);
	Frag.beRepaired(20);
	Frag.highFivesGuys();
	//Frag.guardGate();

	std::cout << "\n\n";

	ScavTrap	Scav("Scavy");

	Scav.attack("Judas");
	Scav.takeDamage(50);
	Scav.beRepaired(2000);
	Scav.guardGate();
	
	std::cout << "\n\n";

	ClapTrap	Clap("Clapy");

	Clap.takeDamage(5);
	Clap.attack("Pikachu");
	Clap.beRepaired(10);
//	Clap.guardGate();

	std::cout << "\n\n";

	return (0);
}
