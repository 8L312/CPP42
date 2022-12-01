#include "Serializer.hpp"

Serializer::Serializer(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

Serializer::~Serializer(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return ( reinterpret_cast<Data *>(raw) );
}

Serializer	&Serializer::operator=(Serializer const &rhs)
{
	//copy here the eventual values like :
	(void)rhs;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}
