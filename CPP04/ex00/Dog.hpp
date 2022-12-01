#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>

class Dog : public Animal
{

public:
	Dog(void);
	Dog(Dog const &src);
	virtual ~Dog(void);

	virtual void	makeSound(void) const;

	Dog	&operator=(Dog const &rhs);

};

#endif
