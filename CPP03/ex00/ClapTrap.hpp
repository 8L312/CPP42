#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class ClapTrap
{

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	void			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	ClapTrap	&operator=(ClapTrap const &rhs);

private:
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_ep;
	unsigned int	_att;

};

#endif
