#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default constructor called for a cat\n";
	this->type = "Cat";
	return ;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	*this = src;
	std::cout << "Copy constructor called for a cat\n";
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called for a cat\n";
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "*MIAOU MIAOU MOTHERF***ER*\n";
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Copy assignment operator called for a cat\n";
	//copy here the eventual values like :
	this->type = rhs.type;

	return (*this);
}
