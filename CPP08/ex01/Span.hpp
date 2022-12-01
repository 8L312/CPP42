#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <algorithm>
# include <vector>
# include <ctime>

class Span
{

public:
	Span(unsigned int n);
	Span(Span const &src);
	~Span(void);

	void			addNumber(int num);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;
	void			addRange
		(std::vector<int>::iterator first, std::vector<int>::iterator last);
	void			showSpan(void);

	class OverMaxException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

	class NotEnoughValException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

	Span	&operator=(Span const &rhs);

private:
	Span(void);

	std::vector<int>	_vec;
	unsigned int		_max;
	unsigned int		_stocked;

};

#endif
