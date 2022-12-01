#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class Animal
{

public:
	Animal(void);
	Animal(Animal const &src);
	virtual ~Animal(void);

	std::string		getType(void) const;

	virtual void	makeSound(void) const = 0;

	Animal	&operator=(Animal const &rhs);

protected:
	std::string	type;

};

#endif
