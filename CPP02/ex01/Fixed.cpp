#include "Fixed.hpp"

Fixed::Fixed(void): _Integer(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(int const n)
{
	this->_Integer = (n << this->_Bit);
	std::cout << "Int constructor called\n";
	return ;
}

Fixed::Fixed(float const f)
{
	this->_Integer = roundf(f * (1 << this->_Bit));
	std::cout << "Float constructor called\n";
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_Integer);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits memeber function called\n";
	this->_Integer = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ( (float)this->_Integer / (float)(1 << this->_Bit) );
}

int	Fixed::toInt(void) const
{
	return (this->_Integer >> this->_Bit);
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignement operator called\n";
	this->_Integer = rhs.getRawBits();

	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return (out);
}
