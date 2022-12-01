#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class Fixed
{

public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed	&operator=(Fixed const &rhs);

private:
	int					_Integer;
	const static int	_Bit = 8;

};

#endif
