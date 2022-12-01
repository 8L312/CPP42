#include "Span.hpp"

Span::Span(void) // is private cause nonsense if empty
{
	//std::cout << "Default constructor called\n";
	return ;
}

Span::Span(unsigned int n): _max(n), _stocked(0)
{
	//std::cout << "Parametric constructor called\n";
	return ;
}

Span::Span(Span const &src)
{
	this->_max = src._max;
	this->_stocked = src._stocked;
	this->_vec = src._vec;
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

Span::~Span(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

void	Span::addNumber(int num)
{
	try
	{
		if (this->_stocked < this->_max)
		{
			this->_vec.push_back(num);
			this->_stocked++;
		}
		else
			throw OverMaxException();
	}
	catch (OverMaxException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

unsigned int	Span::shortestSpan(void) const
{
	try
	{
		if (this->_stocked <= 1)
			throw(NotEnoughValException());

		std::vector<int>	tmp = this->_vec;
		std::sort(tmp.begin(), tmp.end());
		unsigned int	span = *(tmp.begin() + 1) - *tmp.begin();

		if (this->_stocked == 2)
			return (span);
		for (std::vector<int>::iterator i = tmp.begin(); i != (tmp.end() - 1); i++)
		{
			if ( (*(i + 1) - *i) < (int)span )
				span = *(i + 1) - *i;
			if (span == 0)
				return (span);
		}
		return (span);
	}
	catch (NotEnoughValException &e)
	{
		std::cout << e.what() << " :";
		return (0);
	}
}

unsigned int	Span::longestSpan(void) const
{
	try
	{
		if (this->_stocked <= 1)
			throw NotEnoughValException();
		
		std::vector<int>	tmp = this->_vec;
		std::sort(tmp.begin(), tmp.end());

		return ( *(tmp.end() - 1) - *tmp.begin() );
	}
	catch (NotEnoughValException &e)
	{
		std::cout << e.what() << " :";
		return (0);
	}
}

void	Span::addRange
(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	try
	{
		std::vector<int>	tmp(first, last);

		if ( tmp.size() > (this->_max - this->_stocked) )
			throw OverMaxException();
		this->_vec.insert(this->_vec.end(), tmp.begin(), tmp.end());
		this->_stocked += tmp.size();
		return ;
	}
	catch (OverMaxException &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}	
}

Span	&Span::operator=(Span const &rhs)
{
	//copy here the eventual values like :
	this->_vec = rhs._vec;
	this->_max = rhs._max;
	this->_stocked = rhs._stocked;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

const char	*Span::OverMaxException::what(void) const throw()
{
	return ("You reached the max capacity of your span, nothing was made");
}

const char	*Span::NotEnoughValException::what(void) const throw()
{
	return ("There is not enough value stocked in this span to do this");
}

void	Span::showSpan(void)
{
	std::cout << "Span instance contains : ";
	for (std::vector<int>::iterator i = this->_vec.begin(); i != this->_vec.end(); i++)
	{
		std::cout << *i;
		if ((i + 1) !=  this->_vec.end())
			std::cout << ",";
	}
	return ;
}
