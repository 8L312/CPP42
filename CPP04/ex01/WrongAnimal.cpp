#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("random WrongAnimal")
{
	std::cout << "Default constructor called for a WrongAnimal\n";
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
	std::cout << "Copy constructor called for a WrongAnimal\n";
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called for a WrongAnimal\n";
	return ;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*makes an unrecognizable sound*\n";
	return ;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	//copy here the eventual values like :
	this->type = rhs.type;
	std::cout << "Copy assignment operator called for a WrongAnimal\n";

	return (*this);
}
