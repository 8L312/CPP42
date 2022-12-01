#include "Span.cpp"

int main()
{
	{
	Span	swan(4);

	std::cout << swan.shortestSpan() << std::endl;

	std::vector<int>	vec;

	vec.push_back(0);
	vec.push_back(-10);
	vec.push_back(42);
	vec.push_back(43);
	swan.addRange(vec.begin(), vec.end());

	swan.addRange(vec.begin(), vec.end());
	swan.addNumber(10);

	std::cout << "shortest span = " << swan.shortestSpan() << std::endl;
	std::cout << "longest span = " << swan.longestSpan() << std::endl;
	swan.showSpan();
	}
	std::cout << "\n\n";
	{
	Span	one(1);

	one.addNumber(42);

	std::cout << "shortest span = " << one.shortestSpan() << std::endl;
	std::cout << "longest span = " << one.longestSpan() << std::endl;
	}
	std::cout << "\n\n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n\n";
	{
		Span bigone(12000);

		std::srand(std::time(NULL));
		for (int i = 0; i < 12001; i++)
			bigone.addNumber(std::rand() % 100000);
		
		std::cout << "shortest span = " << bigone.shortestSpan() << std::endl;
		std::cout << "longest span = " << bigone.longestSpan() << std::endl;
//		bigone.showSpan();
	}

	return (0);
}
