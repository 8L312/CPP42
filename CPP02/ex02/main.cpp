# include "Fixed.hpp"

int	main( void )
{
	// Example main //
	std::cout << "Example main\n";
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;

	// Tests perso //
	std::cout << "Tests persos\n";

	Fixed	c(42);
	Fixed	d(Fixed(8) - Fixed(6));

	Fixed	i(8);
	Fixed	j(8);

	
	std::cout << "c = ";
	std::cout << c << std::endl;
	std::cout << "--c = ";
	std::cout << --c << std::endl;

	std::cout << "c = " << c << " & d = " << d << std::endl;

	std::cout << "(c / d) = ";
	std::cout << (c / d) << std::endl;
	std::cout << "(c * d) = ";
	std::cout << (c * d) << std::endl;
	std::cout << "Fixed::min(c, d) = ";
	std::cout << Fixed::min(c, d) << std::endl;

	std::cout << "Fixed::max(i, j) = ";
	std::cout << Fixed::max(i, j) << std::endl;

	std::cout << "(i != j) = ";
	std::cout << (i != j) << std::endl;
	std::cout << "j++" << std::endl;
	j++;
	std::cout << "(i < j) = ";
	std::cout << (i < j) << std::endl;

	std::cout << "i--" << std::endl;
	i--;
	std::cout << "(i + j) = ";
	std::cout << (i + j) << std::endl;


	return (0);
}
