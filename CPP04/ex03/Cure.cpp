#include "Cure.hpp"

Cure::Cure(void){
//	std::cout << "Cure Default Constructor Called" << std::endl;
	_type = "cure";
}

Cure::~Cure(void){
//	std::cout << "Cure Default Destructor Called" << std::endl;
}

Cure::Cure(Cure const &src){
//	std::cout << "Cure Copy Constructor Called" << std::endl;
	*this = src;
}

Cure	&Cure::operator=(Cure const &rhs){
	_type = rhs._type;
	return *this;
}

AMateria *Cure::clone()const{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target){
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
