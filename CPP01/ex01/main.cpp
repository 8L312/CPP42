#include "Zombie.hpp"

int	main()
{
	int	N = 4;
	Zombie	*ptr = zombieHorde(N, "Judas");
	Zombie	*base = ptr;

	int i = 1;
	while (i <= N)
	{
		std::cout << "Zombie nº " << i << ": ";
		ptr->announce();
		ptr++;
		i++;
	}
	delete[](base);
	return (0);
}
