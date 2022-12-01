#include "Zombie.hpp"

int	main()
{
	Zombie	*jesus;
	
	jesus = newZombie("Jesus");
	randomChump("Judas");
	jesus->announce();
	delete(jesus);

	return (0);
}
