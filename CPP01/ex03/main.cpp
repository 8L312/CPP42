#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() 
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("other type of club aaaaaaaaaa");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("other type of club aaaaaaaa");
		club.setType("");
		jim.attack();
	}

	return (0);
}
