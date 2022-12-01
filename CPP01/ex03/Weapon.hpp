#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>
#include <stdlib.h>

class Weapon {

public:
	Weapon(std::string type);
	~Weapon(void);

	std::string			&getType(void) const;
	void				setType(std::string);

private:
	std::string	_type;
	std::string	&_typeREF;
};

#endif
