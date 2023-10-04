#ifndef CHARACTER_H
#define CHARACTER_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class MateriaSource;
class AMateria;

class Character: public ICharacter{
	private:
		std::string _name;
		AMateria 	*_inv[4];
		int			_materia_count;
	public:
		Character();
		virtual ~Character();
		Character(Character const &);
		Character(std::string const);

		Character	&operator=(Character const &);
		std::string	const	&getName() const;
		void		equip(AMateria* m);
		void		unequip(int i);
		void		use(int i, ICharacter& target);
};

#endif
