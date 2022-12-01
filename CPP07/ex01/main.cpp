#include "Iter.hpp"

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{ o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main()
{
	int			tab_int[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	float		tab_float[3] = {1.001f, 2.45, 3.678};
	std::string	tab_string[4] = {"un", "deux", "trois", "quatre"};

	std::cout << "Iter with an array of 8 int\n";
	::iter(tab_int, 8, ::template_fct);

	std::cout <<std::endl;
	std::cout << "Iter with an array of 3 float\n";
	::iter(tab_float, 3, ::template_fct);

	std::cout <<std::endl;
	std::cout << "Iter with an array of 4 string\n";
	::iter(tab_string, 4, ::template_fct);

	std::cout << "\n\n";

	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );

	return (0);
}
