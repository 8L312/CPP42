#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class Brain
{

public:
	Brain(void);
	Brain(Brain const &src);
	~Brain(void);

	std::string	getIdea(int n) const;
	void		setIdea(int n, std::string idea);
	Brain		*cpy(void) const;

	Brain	&operator=(Brain const &rhs);

private:
	std::string	_ideas[100];

};

#endif
