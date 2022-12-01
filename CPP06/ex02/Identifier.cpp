#include "Identifier.hpp"

Identifier::Identifier(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

Identifier::Identifier(Identifier const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

Identifier::~Identifier(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

Base	*Identifier::generate(void)
{
	Base	*base;

	std::srand((unsigned)std::time(0));
	int	random = rand() % 3;

	switch (random)
	{
		case 0:
			base = new A();
			break ;

		case 1:
			base = new B();
			break ;

		case 2:
			base = new C();
			break ;
	}
	return (base);
}

void	Identifier::identify(Base *p)
{
	Base *ret;

	ret = dynamic_cast<A *>(p);
	if (ret != NULL)
	{
		std::cout << "Base is of A type\n";
		return ;
	}

	ret = dynamic_cast<B *>(p);
	if (ret != NULL)
	{
		std::cout << "Base is of B type\n";
		return ;
	}

	ret = dynamic_cast<C *>(p);
	if (ret != NULL)
	{
		std::cout << "Base is of C type\n";
		return ;
	}
}

void	Identifier::identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Base is of A type\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}

	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Base is of B type\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}

	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Base is of C type\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}

	return ;
}

Identifier	&Identifier::operator=(Identifier const &rhs)
{
	//copy here the eventual values like :
	(void)rhs;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}
