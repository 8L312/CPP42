#include "Fixed.hpp"

Fixed::Fixed(void): _Integer(0)
{
	std::cout << "Default constructor called\n";
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

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignement operator called\n";
	this->_Integer = rhs.getRawBits();

	return (*this);
}
