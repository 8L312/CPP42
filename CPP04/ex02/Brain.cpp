#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor of Brain called\n";
	return ;
}

Brain::Brain(Brain const &src)
{
	*this = src;
	std::cout << "Copy constructor of Brain called\n";
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Destructor of Brain called\n";
	return ;
}

std::string	Brain::getIdea(int n) const
{
	if (0 <= n && n <= 99)
		return (this->_ideas[n]);
	else
		std::cout << "Wrong index\n";
	return ("");
}

void	Brain::setIdea(int n, std::string idea)
{
	if (0 <= n && n <= 99)
		this->_ideas[n] = idea;
	else
		std::cout << "Wrong index\n";
	return ;
}

Brain	*Brain::cpy(void) const
{
	Brain	*newBrain = new Brain;

	for (int i = 0; i <= 99; i++)
		newBrain->_ideas[i] = this->_ideas[i];

	return (newBrain);
}

Brain	&Brain::operator=(Brain const &rhs)
{
	//copy here the eventual values like :
	for (int i = 0; i <= 99; i++)
		this->_ideas[i] = rhs._ideas[i];

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}
