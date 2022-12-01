#include "Harl.hpp"

int	main()
{
	Harl	Judas;

	Judas.complain("DEBUG");
	std::cout << std::endl;
	Judas.complain("INFO");
	std::cout << std::endl;
	Judas.complain("WARNING");
	std::cout << std::endl;
	Judas.complain("ERROR");
	std::cout << std::endl;
	Judas.complain("JUDAS");
	return (0);
}
