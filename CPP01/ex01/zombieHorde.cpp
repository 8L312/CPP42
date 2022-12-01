#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {

	if (N <= 0)
	{
		std::cout << "Horde must at least have 1 zombie ><" << std::endl;
		std::exit(1);
	}

	Zombie	*ptr = new Zombie[N];
	Zombie	*ret = ptr;

	int i = 0;
	while (i < N)
	{
		ptr->setName(name);
		i++;
		ptr++;
	}
	return (ret);
}
