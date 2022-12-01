#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n";

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j type = " << j->getType() << "(supposed to be Dog)" << std::endl;
	std::cout << "i type = " << i->getType() << "(Supposed to be Cat)" << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n\n";

	delete meta;
	delete j;
	delete i;

	std::cout << "\n\n";

	const WrongAnimal *judas = new WrongCat();

	std::cout << "judas's type = " << judas->getType() << "(supposed to be Cat)" << std::endl;
	judas->makeSound();

	delete judas;

	return (0);
}
