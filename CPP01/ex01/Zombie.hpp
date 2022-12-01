#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>
# include <stdlib.h>

class Zombie {

public:
	Zombie(void);
	~Zombie(void);

	void		announce(void) const;
	std::string	getName (void) const;
	void		setName(std::string name);

private:
	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
