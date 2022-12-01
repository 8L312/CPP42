#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("NoName"), _hp(10), _ep(10), _att(0)
{
	std::cout << "Default constructor called for ClapTrap " << this->_name << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _att(0)
{
	std::cout << "Parametric constructor called for ClapTrap " << this->_name << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "Copy constructor called for ClapTrap " << this->_name << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for ClapTrap " << this->_name << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hp == 0)
	{	
		std::cout << "ClapTrap " << this->_name << " has no more hit point :(\n";
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more energy point :(\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_att << " points of damage\n";
	this->_ep--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << this->_name << " is already dead dude U.u\n";
		return ;
	}
	if (amount >= this->_hp)
	{
		std::cout << this->_name << " took " << this->_hp
			<< " points of damage, he's now K.O. :O\n";
		this->_hp = 0;
		return ;
	}
	else
	{
		this->_hp -= amount;
		std::cout << this->_name << " took " << amount << " points of damage, he has "
			<< this->_hp << " hp left\n";
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << this->_name << " has no more hit point :(\n";
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << this->_name << " has no more energy point :(\n";
		return ;
	}
	this->_ep -= 1;
	this->_hp += amount;
	std::cout << this->_name << " healed " << amount << " hp and now has "
		<< this->_hp << " hp left\n";
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	//std::cout << "Copy assignment operator called\n";
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ep = rhs._hp;
	this->_att = rhs._att;

	return (*this);
}
