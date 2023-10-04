#include "Ice.hpp"

Ice::Ice(void){
//	std::cout << "Ice Default Constructor Called" << std::endl;
	_type = "ice";
}

Ice::~Ice(void){
//	std::cout << "Ice Default Destructor Called" << std::endl;
}

Ice::Ice(Ice const &src){
//	std::cout << "Ice Copy Constructor Called" << std::endl;
	*this = src;
}


Ice	&Ice::operator=(Ice const &rhs){
	_type = rhs._type;
	return *this;
}

AMateria *Ice::clone()const{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
