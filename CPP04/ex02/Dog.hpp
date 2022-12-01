#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>

class Dog : public Animal
{

public:
	Dog(void);
	Dog(Dog const &src);
	virtual ~Dog(void);

	Brain	*getBrain(void) const;
	void	setBrain(Brain *brain);

	virtual void	makeSound(void) const;

	Dog	&operator=(Dog const &rhs);

private:
	Brain	*_brain;
};

#endif
