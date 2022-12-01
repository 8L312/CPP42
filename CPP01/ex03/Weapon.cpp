#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) , _typeREF(this->_type)
{
//	std::cout << "Constructor of Weapon called" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
//	std::cout << "Destructor of Weapon called" << std::endl;
	return ;
}

std::string	&Weapon::getType(void) const
{
	return (this->_typeREF);
}

void	Weapon::setType(std::string type)
{
	if (type == "")
	{
		std::cout << "Nope, type shouldn't be empty" << std::endl;
	}
	else
		this->_type = type;
	return ;
}
