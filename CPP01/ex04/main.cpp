# include "Replacer.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong	number of arguments\n";
		std::exit(1);
	}
	std::ifstream	infile;
	
	infile.open(av[1], std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "Can't open file " << av[1] << std::endl;
		std::exit(1);
	}
	infile.close();

	if (av[2][0] == '\0')
	{
		std::cout << "Bro, I can't replace NULL -.-\n";
		std::exit(1);
	}

	Replacer	replacer;

	replacer.getArg(av[1], av[2], av[3]);
	replacer.replace();
	return (0);
}
