#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

BitcoinExchange::BitcoinExchange(const char *data): _lastDate("0000-01-01")
{
//	std::cout << "Parametric constructor called\n";
	std::ifstream	data_csv;

	data_csv.open(data, std::ios::in);
	if (!data_csv.is_open())
	{
		std::cout << "Error: can't open data.csv\n";
		std::exit(1);
	}

	std::string	line;
	getline(data_csv, line); //first line is not a date, val

	while (!data_csv.eof())
	{
		getline(data_csv, line);
		if (line.empty() && data_csv.eof())
			goto firstlast;
		if (checkDate(line.substr(0, 10)))
			data_error(line);
		if (line[10] != ',')
			data_error(line);
		if (checkValue(line.substr(11)))
			data_error(line);
		if (fillMap(line))
		{
			std::cout << "This date already exists\n";
			data_error(line);
		}
	}

firstlast:
	std::string	f = "2100-01-01";
	std::string	l = "0000-01-01";

	for (std::map<std::string, float>::iterator it = _btvalue.begin();
			it != _btvalue.end(); it++)
	{
		if (it->first < f)
			f = it->first;
		if (it->first > l)
			l = it->first;
	}
	_firstDate = f;
	_lastDate = l;

	return ;
}

int BitcoinExchange::checkDate(std::string str)
{
	int	year;
	int	month;
	int	day;

	if (str[4] != '-' || str[7] != '-')
		return (1);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (str[i] < '0' || '9' < str[i])
			return (1);
	}

	year = std::atoi( (str.substr(0, 4)).c_str() );
	if (year < 1)
		return (1);
	
	month = std::atoi( (str.substr(5, 2)).c_str() );
	if (month < 1 || 12 < month)
		return (1);
	
	day = std::atoi( (str.substr(8, 2)).c_str() );
	if (day < 1 || 31 < day)
		return (1);
	if (month == 2 && 29 < day)
		return (1);
	if ( (month == 4 || month == 6 || month == 9 || month == 11) && 30 < day)
		return (1);

	if (_lastDate != "0000-01-01")
	{
		if (str < _firstDate)
		{
			std::cout << "This date is too far away in the past : ";
			return (1);
		}
		if (str > _lastDate)
		{
			std::cout << "!!! Last date stored in data.csv is [" << _lastDate
				<< "] value could be outdated !!!\n";
			return (0);
		}
	}

	return (0);
}

int BitcoinExchange::checkValue(std::string str)
{
	if (str.empty())
		return (1);

	int i = 0;
	int isf = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
		{
			if (str[i] == '.')
				isf++;
			else
				return (1);
		}
		i++;
	}
	if (1 < isf)
		return (1);

	if (!isf)
	{
		long valint = std::atol(str.c_str());
		if (valint < 0)
			return (1);
	}
	else
	{
		float valfloat = std::atof(str.c_str());
		if (valfloat < 0)
			return (1);
	}
	return (0);
}

void	BitcoinExchange::data_error(std::string line)
{
	std::cout << "Error in data.csv at line = [" << line << "] : programm exited\n";
	std::exit(1);
}

int	BitcoinExchange::fillMap(std::string str)
{
	std::string	date;
	std::string	value;

	float		f_value;

	date = str.substr(0, 10);
	value = str.substr(11);
	
	if (value.find("."))
		f_value = std::atof( value.c_str() );
	else
		f_value = static_cast<float>(std::atoi( value.c_str() ));

	if (_btvalue.count(date) > 0)
		return (1);
	_btvalue[date] = f_value;
	return (0);
}

void	BitcoinExchange::output(char *filename)
{
	std::ifstream infile;

	infile.open(filename, std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "Error: cannot open file [" << filename << "]\n";
		std::exit(1);
	}

	std::string	line;
	getline(infile, line); //first line is not a date, val

	int err = 0;
	while (!infile.eof())
	{
		getline(infile, line);
		if (line.empty())
			continue ;
		if (checkDate(line.substr(0, 10)))
		{
			std::cout << "Error: bad input date\n";
			continue ;
		}
		if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		{
			std::cout << "Error: bad input format\n";
			continue ;
		}
		if ((err = checkValueInfile(line.substr(13))))
		{
			wrongValue(err);
			continue ;
		}
		displayResult(line);
	}
	return ;
}

void	BitcoinExchange::displayResult(std::string str)
{
	std::string	date;
	std::string	value;

	float		f_value;

	date = str.substr(0, 10);
	value = str.substr(13);

	if (value.find("."))
		f_value = std::atof( value.c_str() );
	else
		f_value = static_cast<float>(std::atoi( value.c_str() ));

	std::map<std::string, float>::iterator	it;
	it = _btvalue.find(date);
	if (it != _btvalue.end())	
		goto print;
	else
	{
		it = _btvalue.begin();
		while (date > it->first && it != _btvalue.end())
			it++;
		it--;
	}

print:
	std::cout << date << " => " << value << " = "
		<< f_value * (it->second) << std::endl;
}

void	BitcoinExchange::wrongValue(int err)
{
	switch (err)
	{
		case 1:
			std::cout << "Error: wrong format in value\n";
			break ;

		case 2:
			std::cout << "Error: negative value\n";
			break ;

		case 3:
			std::cout << "Error: too large number\n";
			break ;
		
		default:
			break ;
	}
}

int BitcoinExchange::checkValueInfile(std::string str)
{
	if (str.empty())
		return (1);

	if (str[0] == '-')
		return (2);
	int i = 0;
	int isf = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
		{
			if (str[i] == '.')
				isf++;
			else
				return (1);
		}
		i++;
	}
	if (1 < isf)
		return (1);

	if (!isf)
	{
		long valint = std::atol(str.c_str());
		if (valint < 0)
			return (2);
		if (valint > 1000)
			return (3);
	}
	else
	{
		float valfloat = std::atof(str.c_str());
		if (valfloat < 0)
			return (2);
		if (valfloat > 1000)
			return (3);
	}
	return (0);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	//copy here the eventual values like :
	this->_btvalue = rhs._btvalue;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}
