#include "AMateria.hpp"

AMateria::AMateria(void){
//	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::~AMateria(void){
///	std::cout << "AMateria Default Destructor Called" << std::endl;
}

AMateria::AMateria(AMateria const &src){
//	std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = src;
}
AMateria::AMateria(std::string const &type): _type(type){
//	std::cout << "AMateria Assignation Constructor Called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &rhs){
	_type = rhs._type;
	return *this;
}

std::string const &AMateria::getType(void)const{
	return this->_type;
}

void	AMateria::use(ICharacter &target){
	std::cout << "AMateria: " << "\"*AMaterias an AMateria at " << target.getName() << "*\"" << std::endl;
}
