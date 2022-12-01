#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "NoName";
	this->_hp = 100;
	this->_ep = 50;
	this->_att = 20;
	std::cout << "Default constructor called for ScavTrap " << this->_name << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_att = 20;

	std::cout << "Parametric constructor called for ScavTrap " << this->_name << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Copy constructor called for ScavTrap " << this->_name << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called for ScavTrap " << this->_name << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hp == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no more hit point :(\n";
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no more energy point :(\n";
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_att << " points of damage\n";
	this->_ep--;
	return ;
}

void	ScavTrap::guardGate(void) const
{
	if (this->_hp == 0)
		std::cout << "ScavTrap " << this->_name
			<< " has no more hit point, he can't do anything\n";
	else
		std::cout << "ScavTrap " << this->_name << " entered in Gate keeper mode\n";
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	//std::cout << "Copy assignment operator called\n";
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_att = rhs._att;

	return (*this);
}
