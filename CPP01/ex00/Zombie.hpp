#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

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

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
