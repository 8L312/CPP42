#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "Constructor of Zombie called" << std::endl;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << "Destructor of Zombie called : " << this->_name << " destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void) const {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

std::string	Zombie::getName(void) const {

	return (this->_name);
}

void	Zombie::setName (std::string name) {

	this->_name = name;
	return ;
}
