#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "Cat";
	std::cout << "Default constructor called for a WrongCat\n";
	return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	*this = src;
	std::cout << "Copy constructor called for a WrongCat\n";
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called for a WrongCat\n";
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*MIAOU MIAOU IMA WRONGCAT*\n";
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	//copy here the eventual values like :
	this->type = rhs.type;
	std::cout << "Copy assignment operator called for a WrongCat\n";

	return (*this);
}
