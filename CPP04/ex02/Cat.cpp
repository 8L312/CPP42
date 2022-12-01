#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default constructor called for a cat\n";
	this->type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	this->type = src.type;
	this->_brain = src._brain->cpy();
	std::cout << "Copy constructor called for a cat\n";
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Destructor called for a cat\n";
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "*MIAOU MIAOU MOTHERF***ER*\n";
	return ;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::setBrain(Brain *brain)
{
	this->_brain = brain;
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Copy assignment operator called for a cat\n";
	//copy here the eventual values like :
	this->type = rhs.type;
	delete (this->_brain);
	this->_brain = rhs._brain->cpy();

	return (*this);
}
