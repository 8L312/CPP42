#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
//	std::cout << "Constructor of HumanB called" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
//	std::cout << "Destructor of HumnaB called" << std::endl;
	return ;
}

void	HumanB::attack(void)
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
		return ;
	}
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
	return ;
}
