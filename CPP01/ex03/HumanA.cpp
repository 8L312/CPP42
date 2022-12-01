#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name) , _weapon(weapon)
{
//	std::cout << "Constructor of HumanA called" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
//	std::cout << "Destructor of HumanA called" << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}
