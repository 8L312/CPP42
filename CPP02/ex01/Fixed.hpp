#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <stdlib.h>

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

	Fixed	&operator=(Fixed const &rhs);

private:
	int					_Integer;
	const static int	_Bit = 8;

};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);

#endif
