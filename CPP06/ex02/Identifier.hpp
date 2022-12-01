#ifndef IDENTIFIER_HPP
# define IDENTIFIER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <ctime>
# include "Base.hpp"

class Identifier
{

public:
	Identifier(void);
	Identifier(Identifier const &src);
	~Identifier(void);

	Base	*generate(void);
	void	identify(Base *p);
	void	identify(Base &p);

	Identifier	&operator=(Identifier const &rhs);

private:

};

#endif
