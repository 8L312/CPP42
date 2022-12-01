#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n";

//	Animal	judas;
	Animal	*ani1 = new Cat();
//	Animal	*ani2 = new Animal();

	ani1->makeSound();
//	ani2->makeSound();

	delete ani1;
//	delete ani2;

	std::cout << "\n\n";

	return (0);
}
