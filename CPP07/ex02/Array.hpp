#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cstdlib>

template<typename T>
class Array {
public:
	Array(void) : _size(0)
	{
		return ;
	}

	Array(unsigned int n) : _size(n)
	{
		this->_array = new T[n];
		return ;
	}

	Array(Array const &src)
	{
		this->_size = src._size;
		this->_array = new T[src._size];
		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
		return ;
	}

	~Array(void)
	{
		if (this->_size != 0)
			delete[](this->_array);
		return ;
	}

	unsigned int	size(void) const
	{
		return (this->_size);
	}

	Array	&operator=(Array const &rhs)
	{
		this->_size = rhs._size;
		this->_array = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; i++)
			this->_array[i] = rhs.getElem(i);
		return (*this);
	}

	T	&operator[](unsigned int index)
	{
		try
		{
			if (index < this->_size)
				return (this->_array[index]);
			else
				throw BadIndexException();
			return (this->_array[index]);
		}
		catch (BadIndexException &e)
		{
			std::cout << e.what() << "Programm exited" << std::endl;
			std::exit(1);
		}
		return (this->_array[index]);
	}

	class	BadIndexException : public std::exception
	{
		public:
			virtual const char *what(void) const throw()
			{
				return ("Your index doesn't fit in the array");
			}
	};

	T	const &getElem(unsigned int n) const
	{
		try
		{
			if (n < this->_size)
				return (this->_array[n]);
			throw BadIndexException();
		}
		catch (BadIndexException &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "You tried to access memory you shouldn't. Programm exited\n";
			std::exit(1);
		}
	}

	void	setElem(unsigned int n, T const &elem)
	{
		try
		{
			if (n < this->_size)
				this->_array[n] = elem;
			else
				throw BadIndexException();
		}
		catch (BadIndexException &e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}
		return ;
	}

		
private:
	unsigned int	_size;
	T				*_array;
};

#endif
