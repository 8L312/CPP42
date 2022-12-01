#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>

class Serializer
{

public:
	Serializer(void);
	Serializer(Serializer const &src);
	~Serializer(void);

	uintptr_t	serialize(Data *ptr);
	Data		*deserialize(uintptr_t raw);

	Serializer	&operator=(Serializer const &rhs);

private:

};

#endif
