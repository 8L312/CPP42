# include "Converter.hpp"

int main(int ac, char **av)
{
	Converter	convert;

	if (ac != 2)
	{
		std::cout << "usage : ./convert [arg]\n";
		return (1);
	}
	convert.recieveArg(av[1]);

	return (0);
}
