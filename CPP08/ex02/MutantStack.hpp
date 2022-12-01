#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <stack>
# include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void)
	{
		return ;
	}
	
	MutantStack(const MutantStack<T> &src)
	{
		*this = src;
		return ;
	}

	MutantStack<T> &operator=(const MutantStack<T> &rhs) 
	{
		this->c = rhs.c;
		return (*this);
	}

	~MutantStack(void)
	{
		return ;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void)
	{
		return this->c.begin();
	}
	
	iterator end(void)
	{
		return this->c.end();
	}
};

#endif
