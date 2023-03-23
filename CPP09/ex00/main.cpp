#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if 	(ac != 2)
	{
		std::cout << "Usage: \"./btc [filename.txt]\"\n";
		return (1);
	}

	BitcoinExchange	btc("data.csv");
	
	btc.output(av[1]);
	std::exit(0);
	return (0);
}
