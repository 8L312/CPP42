#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "usage : ./PmergeMe [ints to sort]\n";
		return (1);
	}
	
	int i = 0;
	while (av[++i] != NULL)
	{
		if (av[i][0] == '\0')
		{
				std::cout << "Error: bad input in numbers\n";
				return (1);
		}
		for (int o = 0; av[i][o] != '\0'; o++)
		{
			if (av[i][o] < '0' || '9' < av[i][o])
			{
				std::cout << "Error: bad input in numbers\n";
				return (1);
			}
		}
		int j = std::atoi(av[i]);
		if (j < 0 && 2147483647 > j)
		{
			std::cout << "We can only sort positive integer\n";
			return (1);
		}
	}

	PmergeMe	sorter;
	
	sorter.takeArg(av);

	i = 0;
	std::cout << "Before : ";
	while (av[++i] != NULL)
	{
		std::cout << std::atoi(av[i]) << " ";
		if (i > MAXDISPLAY)
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << std::endl;

	clock_t	start;
	clock_t	end;
	double	time;

	start = clock();
	sorter.sortVec(0, sorter.getVector().size() - 1);
	end = clock();
	time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
	sorter.setTime(time, "vector");

	start = clock();
	sorter.sortDeque(0, sorter.getDeque().size() - 1);
	end = clock();
	time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
	sorter.setTime(time, "deque");

	sorter.displayResults();
	return (0);
}
