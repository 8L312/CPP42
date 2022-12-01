#include "Converter.hpp"

Converter::Converter(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

Converter::Converter(Converter const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

Converter::~Converter(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

Converter	&Converter::operator=(Converter const &rhs)
{
	//copy here the eventual values like :
	this->_raw = rhs._raw;
	this->_type = rhs._type;
	this->_toChar = rhs._toChar;
	this->_toInt = rhs._toInt;
	this->_toFloat = rhs._toFloat;
	this->_toDouble = rhs._toDouble;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

void	Converter::recieveArg(char *str)
{
	this->_raw = str;
	this->_rawstr = str;
	this->_type = -1;
	for (int i = 0; i < 5; i++)
		this->_canConvert[i] = 1;

	try
	{
		if (this->identifyType() == -1)
			throw NoTypeMatchException();
	
		std::cout << "  type = "; ////// A suppr /////
		if (this->_type == 0)	
			std::cout << "char";
		if (this->_type == 1)
			std::cout << "int";
		if (this->_type == 2)
			std::cout << "float";
		if (this->_type == 3)
			std::cout << "double";
		std::cout << std::endl; ///////A suppr///

		this->castAll();
		this->printResults();
	}
	catch ( NoTypeMatchException &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	return ;
}

const char	*Converter::NoTypeMatchException::what(void) const throw()
{
	return ("The type you entered is neither a char, an int, a float nor a double");
}

void	Converter::castAll(void)
{
	switch (this->_type)
	{
		case 0:
			this->_toChar = this->_raw[0];
			
			this->_toInt = static_cast<int>(this->_toChar);
			this->_toFloat = static_cast<float>(this->_toChar);
			this->_toDouble = static_cast<double>(this->_toChar);
			break ;

		case 1:
			this->_toInt = std::atoi(this->_raw);
			
			this->_toChar = static_cast<char>(this->_toInt);
			this->_toFloat = static_cast<float>(this->_toInt);
			this->_toDouble = static_cast<double>(this->_toInt);
			break ;

		case 2:
			this->_toFloat = std::atof(this->_raw);

			if (!this->canConvertInt(this->_toFloat))
				this->_canConvert[1] = 0;

			this->_toChar = static_cast<char>(this->_toFloat);
			this->_toInt = static_cast<int>(this->_toFloat);
			this->_toDouble = static_cast<double>(this->_toFloat);
			break ;

		case 3:
			this->_toDouble = std::atof(this->_raw);

			if (!this->canConvertInt(this->_toDouble))
				this->_canConvert[1] = 0;
			if (!this->canConvertFloat(this->_toDouble))
				this->_canConvert[2] = 0;

			this->_toChar = static_cast<char>(this->_toDouble);
			this->_toInt = static_cast<int>(this->_toDouble);
			this->_toFloat = static_cast<float>(this->_toDouble);
			break ;
	}
}

bool	Converter::canConvertInt(double num) const
{
	return (num <= std::numeric_limits<int>::max()
			&& num >= std::numeric_limits<int>::min()
			&& num != std::numeric_limits<double>::infinity()
			&& num != -std::numeric_limits<double>::infinity()
			&& num != std::numeric_limits<double>::quiet_NaN());
}

bool	Converter::canConvertFloat(double num) const
{
	return ((num <= std::numeric_limits<float>::max()
			&& num >= -std::numeric_limits<float>::max())
			|| num == std::numeric_limits<double>::infinity()
			|| num == -std::numeric_limits<double>::infinity()
			|| std::isnan(num));
}

void	Converter::printResults(void) const
{
	std::cout << " char  : ";
	this->printChar();
	std::cout << std::endl;

	std::cout << "  int  : ";
	this->printInt();
	std::cout << std::endl;

	std::cout << " float : ";
	this->printFloat();
	std::cout << std::endl;

	std::cout << "double : ";
	this->printDouble();
	std::cout << std::endl;
}

void	Converter::printChar(void) const
{
	if (!this->_canConvert[0])
	{
		std::cout << "impossible";
		return ;
	}
	if (this->_toInt < 0 || 127 < this->_toInt)
		std::cout << "impossible";
	else if (31 < this->_toChar && this->_toChar < 127)
		std::cout << "'" << this->_toChar << "'";
	else
		std::cout << "non displayable";
}

void	Converter::printInt(void) const
{
	if (!this->_canConvert[1])
	{
		std::cout << "impossible";
		return ;
	}
	std::cout << this->_toInt;
}

void	Converter::printFloat(void) const
{
	if (!this->_canConvert[2])
	{
		std::cout << "impossible";
		return ;
	}
	std::cout << this->_toFloat;
	if (this->_toInt < 1000000)
	{
		if (std::floor(this->_toFloat) == this->_toFloat
				&& std::ceil(this->_toFloat) == this->_toFloat
				&& abs(this->_toFloat) != INFINITY)
			std::cout << ".0f";
		else
			std::cout << "f";
	}
}

void	Converter::printDouble(void) const
{
	if (!this->_canConvert[3])
	{
		std::cout << "impossible";
		return ;
	}
	std::cout << this->_toDouble;
	if (std::floor(this->_toDouble) == this->_toDouble
			&& std::ceil(this->_toDouble) == this->_toDouble
			&& abs(this->_toDouble) != INFINITY
			&& this->_toInt < 1000000)
		std::cout << ".0";
}

int	Converter::identifyType(void)
{
	this->specialType();
	if (this->_type != -1)
		return (this->_type);

	this->charType();
	if (this->_type != -1)
		return (this->_type);

	int	pointCounter = 0;
	int	i = 0;
	if (this->_raw[0] == '-')
		i++;
	while (this->_raw[i] != '\0')
	{
		if ( !this->isDigit(this->_raw[i]) )
		{
			if (this->_raw[i] == '.')
			{
				pointCounter++;
				i++;
			}
			else
				break ;
		}
		i++;
	}

	if (this->_raw[i] != '\0' && this->_raw[i] != 'f')
		return (this->_type);

	if ( this->isDigit(this->_raw[i - 1]) && pointCounter == 1 )
		this->_type = 3;
	
	if (this->_raw[i] == 'f' && pointCounter == 1
			&& this->isDigit(this->_raw[i - 1]) && this->_raw[i + 1] == '\0')
		this->_type = 2;

	if (pointCounter == 0 && this->_raw[i] == '\0')
		this->_type = 1;
	
	if (this->_type == 1)
	{
		long test = std::atol(this->_raw);
		if (test < std::numeric_limits<int>::min()
			|| test > std::numeric_limits<int>::max())
			return (-1);
	}

	return (this->_type);
}

bool	Converter::isDigit(char c) const
{
	if (47 < c && c <= 57)
		return (true);
	return (false);
}

void	Converter::charType(void)
{
	if (this->_rawstr.length() == 1)
	{
		this->_type = 0;
		if (47 < this->_raw[0] && this->_raw[0] <= 57)
			this->_type = 1;
	}
	return ;
}

void	Converter::specialType(void)
{
	std::string spec[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	int i = -1;
	while (++i < 6)
	{
		if (this->_rawstr == spec[i])
			break ;
	}
	if (i <= 2)
		this->_type = 2;
	if (3 <= i && i <= 5)
		this->_type = 3;
	if (i <= 5)
	{
		this->_canConvert[0] = 0;
		this->_canConvert[1] = 0;
	}
	return ;
}
