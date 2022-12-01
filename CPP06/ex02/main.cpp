#include "Base.hpp"
#include "Identifier.hpp"

int	main()
{
	Base *base;

	Identifier identifier;

	base = identifier.generate();

	std::cout << "Identifier with pointer :\n"; 
	identifier.identify(base);

	std::cout << "Identifier with reference :\n";
	identifier.identify(*base);

	delete (base);
	return (0);
}
