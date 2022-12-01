#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>

class ScavTrap : public ClapTrap
{

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	void	attack(const std::string &target);

	void	guardGate(void) const;

	ScavTrap	&operator=(ScavTrap const &rhs);

private:

};

#endif
