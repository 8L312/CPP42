#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <stdlib.h>

# define TRUE 0
# define FALSE 1

class Fixed
{

public:
	Fixed(void);
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const &src);
	~Fixed(void);


	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed	min(Fixed &a, Fixed &b);
	static Fixed	min(Fixed const &a, Fixed const &b);
	static Fixed	max(Fixed &a, Fixed &b);
	static Fixed	max(Fixed const &a, Fixed const &b);


	Fixed	&operator=(Fixed const &rhs);
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	
	bool	operator<(Fixed const &rhs);
	bool	operator>(Fixed const &rhs);

	bool	operator<=(Fixed const &rhs);
	bool	operator>=(Fixed const &rhs);

	bool	operator==(Fixed const &rhs);
	bool	operator!=(Fixed const &rhs);

private:
	int					_Integer;
	const static int	_Bit = 8;

};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);

#endif
