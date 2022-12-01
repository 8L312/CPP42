#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; ++i)
		{
			for (size_t j = 0; j < strlen(av[i]); j++)
				putchar(toupper(av[i][j]));
		}
		std::cout << std::endl;
	}
	return (0);
}
