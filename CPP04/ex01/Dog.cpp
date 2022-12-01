#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Default constructor called for a dog\n";
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	this->type = src.type;
	this->_brain = src._brain->cpy();
	std::cout << "Copy constructor called for a dog\n";
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Destructor called for a dog\n";
	return ;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::setBrain(Brain *brain)
{
	this->_brain = brain;
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
	delete (this->_brain);
	this->_brain = rhs._brain->cpy();

	return (*this);
}
