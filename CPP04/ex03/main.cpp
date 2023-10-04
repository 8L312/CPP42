#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(){
	std::cout << std::endl << std::endl;
	{
	std::cout << "TEST DU SUJET :" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice"); me->equip(tmp);
	tmp = src->createMateria("cure"); me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << "######################################" << std::endl << std::endl;
	}

	std::cout << "TEST SUPPLEMENTAIRES : " << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("Jesus");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");	//plus de place
	me->equip(tmp);
	tmp = src->createMateria("curedent");	//pas une materia reconnue
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-2, *bob);
	me->use(-1, *bob);

	std::cout << "######################################" << std::endl << std::endl;
	std::cout << "*** au tour de Bob ***" << std::endl << std::endl;

	AMateria* tmp2;
	tmp2 = src->createMateria("ice");
	bob->equip(tmp2);
	bob->use(0, *me);
	bob->use(1, *me);

	delete bob;
	delete me;
	delete src;

	return (0);
}
