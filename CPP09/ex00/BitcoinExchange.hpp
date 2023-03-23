#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <fstream>
#include <map>

class BitcoinExchange
{

public:
	BitcoinExchange(const char *data); //data will be given in .csv format
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

	void	output(char *filename);

	BitcoinExchange	&operator=(BitcoinExchange const &rhs);

private:
	BitcoinExchange(void);
	int		checkDate(std::string str);
	int		checkValue(std::string str);
	int		checkValueInfile(std::string str);
	void	data_error(std::string line);
	int		fillMap(std::string str);
	void	wrongValue(int err);
	void	displayResult(std::string str);

	std::map<std::string, float>	_btvalue;
	std::string						_firstDate;
	std::string						_lastDate;
};

#endif
