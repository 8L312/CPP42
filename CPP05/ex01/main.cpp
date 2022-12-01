#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n\n";

	Bureaucrat	Judas("Judas", 1);
	Bureaucrat	Random("Alex", 50);

	Form		Trees("Trees planting", 50, 200);
	Form		Mission("A secret mission", 0, 151);

	std::cout << Judas << std::endl;
	std::cout << Mission << std::endl;

	Judas.signForm(Mission);
	Random.signForm(Mission);

	std::cout << Mission << std::endl;

	std::cout << "\n\n";

	Random.Downgrade();
	std::cout << Random << std::endl;
	std::cout << Trees << std::endl;

	Random.signForm(Trees);
	std::cout << Trees << std::endl;

	return (0);
}
