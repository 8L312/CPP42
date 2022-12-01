#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n\n";
	Bureaucrat	random;
	Bureaucrat	Judas("Judas", 1);
	Bureaucrat	Hacker("Hackerman", 0);
	Bureaucrat	gronaze("Gronaze", 151);

	std::cout << Judas << std::endl;
	Judas.Downgrade();
	std::cout << Judas << std::endl;
	Judas.Upgrade();
	Judas.Upgrade();
	random.Downgrade();
	gronaze = Hacker;


	std::cout << Judas << std::endl;
	std::cout << random << std::endl;
	std::cout << gronaze << std::endl;



	return (0);
}
