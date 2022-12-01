#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n";

	const Animal* j = new Dog(); 
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "\n\n";

	Animal	*tab[8];

	for (int i = 0; i < 8; i++)
	{
		if (i <= 3)
		{
			tab[i] = new Cat();
			std::cout << std::endl;
		}
		else
		{
			tab[i] = new Dog();
			std::cout << std::endl;
		}
	}

	std::cout << "\n\n";
	
	for (int n = 0; n < 8; n++)
	{
		tab[n]->makeSound();
		delete tab[n];
		std::cout << std::endl;
	}

	std::cout << "\n\n";

	Animal *dog1 = new Dog();

	{
		Animal *dog2 = dog1;
		dog2->makeSound();
	}

	dog1->makeSound();
	delete dog1;

	std::cout << "\n\n!!! COPIE PROFONDE !!!\n";

	Dog	basic;

	std::cout << "basic brain = " << ( basic.getBrain() ) << std::endl;
	{
		Dog	tmp = basic; 
		std::cout << "tmp brain = " << ( tmp.getBrain() ) << std::endl;
		
	}

	return (0);
}
