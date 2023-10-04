#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(void){
//	std::cout << "Character Default Constructor Called" << std::endl;
	_name = "Default caracter";
	_materia_count = 0;
	this->_inv[0] = NULL;
	this->_inv[1] = NULL;
	this->_inv[2] = NULL;
	this->_inv[3] = NULL;
}

Character::~Character(void){
//	std::cout << "Character Default Destructor Called" << std::endl;
}

Character::Character(Character const &src){
//	std::cout << "Character Copy Constructor Called" << std::endl;
	*this = src;
}

Character::Character(std::string const name){
//	std::cout << "Character Naming Constructor Called" << std::endl;
	_materia_count = 0;
	_name = name;
}

Character	&Character::operator=(Character const &rhs){
	_materia_count = rhs._materia_count;
	_name = rhs._name;
	this->_inv[0] = rhs._inv[0];
	this->_inv[1] = rhs._inv[1];
	this->_inv[2] = rhs._inv[2];
	this->_inv[3] = rhs._inv[3];
	return *this;
}

std::string	const	&Character::getName()const{
	return _name;
}

void				Character::equip(AMateria* m){
	if (_materia_count > 3){
		std::cout << "Cannot equip that materia" << std::endl;
		return;
	}
	if (m == NULL){
//		std::cout << "This mf NULL" << std::endl;
		return ;
	}
//	std::cout << "equipping materia" << std::endl;
	_inv[_materia_count] = m;
	_materia_count++;
}

void	Character::unequip(int i){
	if (i > 4 || i < 1){
		std::cout << "You only have 4 slots for Materias" << std::endl;
		return ;
	}
	this->_inv[i - 1] = NULL;
	return ;
}

void	Character::use(int i, ICharacter& target){
	if ((i > 3 || i < 0) || !_inv[i]){
		std::cout << "You only have 4 slots for Materias" << std::endl;
		return;
	}
//	std::cout << materia_count << std::endl;
	if (i >= _materia_count)
		return ;
	_inv[i]->use(target);
	return ;
}
