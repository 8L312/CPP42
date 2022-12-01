#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "NoName";
	this->_hp = 100;
	this->_ep = 100;
	this->_att = 30;
	std::cout << "Default constructor called for FragTrap " << this->_name << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_att = 30;

	std::cout << "Parametric constructor called for FragTrap " << this->_name << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Copy constructor called for FragTrap " << this->_name << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called for FragTrap " << this->_name << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name
		<< " wants to high fives... any volounteer ?\n";
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	//std::cout << "Copy assignment operator called\n";
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_att = rhs._att;

	return (*this);
}
