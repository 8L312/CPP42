#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>
# include <limits>
# include <cmath>
# include <iomanip>

class Converter
{

public:
	Converter(void);
	Converter(Converter const &src);
	~Converter(void);

	void	recieveArg(char *str);

	Converter	&operator=(Converter const &rhs);

	class NoTypeMatchException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

private:
	char		*_raw;
	std::string	_rawstr;

	int			_type; // -1 = ERR  // 0 = char // 1 = int // 2 = float // 3 = double //
	int			_canConvert[4]; //index like upper : 0 is not ok || 1 is ok //

	char		_toChar;
	int			_toInt;
	float		_toFloat;
	double		_toDouble;

	int		identifyType(void);
	void	specialType(void);
	void	charType(void);

	void	castAll(void);
	bool	canConvertInt(double num) const;
	bool	canConvertFloat(double num) const;

	void	printResults(void) const;

	bool	isDigit(char c) const;

	void	printChar(void) const;
	void	printInt(void) const;
	void	printFloat(void) const;
	void	printDouble(void) const;


};

#endif
