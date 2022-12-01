#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Default constructor called for a dog\n";
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	*this = src;
	std::cout << "Copy constructor called for a dog\n";
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called for a dog\n";
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "*OUAF OUAF IMA GOOD BOI*\n";
	return ;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << "Copy assignment operator called for a dog\n";
	//copy here the eventual values like :
	this->type = rhs.type;

	return (*this);
}
