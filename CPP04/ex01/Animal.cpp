#include "Animal.hpp"

Animal::Animal(void): type("random animal")
{
	std::cout << "Default constructor called for an animal\n";
	return ;
}

Animal::Animal(Animal const &src)
{
	*this = src;
	std::cout << "Copy constructor called for an animal\n";
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called for an animal\n";
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "*makes an unrecognizable sound*\n";
	return ;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	std::cout << "Copy assignment operator called for an animal\n";
	//copy here the eventual values like :
	this->type = rhs.getType();

	return (*this);
}
