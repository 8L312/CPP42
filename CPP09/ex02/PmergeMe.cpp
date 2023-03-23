#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

PmergeMe::~PmergeMe(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	//copy here the eventual values like :
	this->_deque = rhs._deque;
	this->_vector = rhs._vector;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

void	PmergeMe::takeArg(char **av)
{
	int i = 0;
	while (av[++i] != NULL)
	{
		_vector.push_back( std::atoi(av[i]) );
		_deque.push_back( std::atoi(av[i]) );
	}
}

void	PmergeMe::insertVec(unsigned int p, unsigned int q)
{
	for (unsigned int i = p; i < q; i++)
	{
		unsigned int tempVal = _vector[i + 1];
		unsigned int j = i + 1;
		while (j > p && _vector[j - 1] > tempVal)
		{
			_vector[j] = _vector[j - 1];
			j--;
		}
		_vector[j] = tempVal;
	}
}

void	PmergeMe::mergeVec(unsigned int p, unsigned int q, unsigned int r)
{
	unsigned int n1 = q - p + 1;
	unsigned int n2 = r - q;
	std::vector<unsigned int> LA;
	for (unsigned int i = p; i < q + 1; i++)
		LA.push_back(_vector[i]);
	std::vector<unsigned int> RA;
	for (unsigned int i = q + 1; i < r + 1; i++)
		RA.push_back(_vector[i]);
	unsigned int RIDX = 0;
	unsigned int LIDX = 0;
	for (unsigned int i = p; i < r - p + 1; i++)
	{
		if (RIDX == n2)
		{
			_vector[i] = LA[LIDX];
			LIDX++;
		}
		else if (LIDX == n1)
		{
			_vector[i] = RA[RIDX];
			RIDX++;
		}
		else if (RA[RIDX] > LA[LIDX])
		{
			_vector[i] = LA[LIDX];
			LIDX++;
		}
		else
		{
			_vector[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void	PmergeMe::sortVec(unsigned int p, unsigned int r)
{
	if (r - p > _vector.size() / 2)
	{
		int q = (p + r) / 2;
		sortVec(p, q);
		sortVec(q + 1, r);
		mergeVec(p, q, r);
	}
	else
		insertVec(p, r);
}

void	PmergeMe::insertDeque(unsigned int p, unsigned int q)
{
	for (unsigned int i = p; i < q; i++)
	{
		unsigned int tempVal = _deque[i + 1];
		unsigned int j = i + 1;
		while (j > p && _deque[j - 1] > tempVal)
		{
			_deque[j] =  _deque[j - 1];
			j--;
		}
		_deque[j] = tempVal;
	}
}

void	PmergeMe::mergeDeque(unsigned int p, unsigned int q, unsigned int r)
{
	unsigned int n1 = q - p + 1;
	unsigned int n2 = r - q;
	std::deque<unsigned int> LA;
	for (unsigned int i = p; i < q + 1; i++)
		LA.push_back(_deque[i]);
	std::deque<unsigned int> RA;
	for (unsigned int i = q + 1; i < r + 1; i++)
		RA.push_back(_deque[i]);
	unsigned int RIDX = 0;
	unsigned int LIDX = 0;
	for (unsigned int i = p; i < r - p + 1; i++)
	{
		if (RIDX == n2)
		{
			_deque[i] = LA[LIDX];
			LIDX++;
		}
		else if (LIDX == n1)
		{
			_deque[i] = RA[RIDX];
			RIDX++;
		}
		else if (RA[RIDX] > LA[LIDX])
		{
			_deque[i] = LA[LIDX];
			LIDX++;
		}
		else
		{
			_deque[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void	PmergeMe::sortDeque(unsigned int p, unsigned int r)
{
	if (r - p > _deque.size() / 2)
	{
		int q = (p + r) / 2;
		sortDeque(p, q);
		sortDeque(q + 1, r);
		mergeDeque(p, q, r);
	}
	else
		insertDeque(p, r);
}

void	PmergeMe::setTime(double time, std::string type)
{
	if (type == "vector")
		_timeVector = time;
	else
		_timeDeque = time;
}

std::vector<unsigned int>	PmergeMe::getVector(void) const
{
	return (_vector);
}

std::deque<unsigned int>		PmergeMe::getDeque(void) const
{
	return (_deque);
}

void	PmergeMe::displayResults(void)
{
	std::cout << "After  : ";
	int i = 0;
	unsigned int last = 0;

	for (std::vector<unsigned int>::iterator it = _vector.begin();
			it != _vector.end(); ++it)
	{
    	std::cout << *it << " ";
		if (++i > MAXDISPLAY)
		{
			std::cout << "[...]";
			break ;
		}
		last = *it;
	}
  	std::cout << '\n';

				///	SAME DISPLAY BUT WITHE DEQUE ///
/*	i = 0;
	for (std::deque<unsigned int>::iterator it = _deque.begin();
			it != _deque.end(); ++it)
	{
    	std::cout << *it << " ";
		if (++i > MAXDISPLAY)
		{
			std::cout << "[...]";
			break ;
		}
	}*/

	for (int i = 1; i <= static_cast<int>(_vector.size() - 1); i++)
	{
		if (_vector[i-1] > _vector[i])
		{
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "Car " << _vector[i-1] << " > " << _vector[i] << "\n";
			break;
		}
	}

	for (int i = 1; i <= static_cast<int>(_deque.size() - 1); i++)
	{
		if (_deque[i-1] > _deque[i])
		{
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "ERROR !!!!!!!! VECTOR NON TRIE !!!!!!!!\n";
			std::cout << "Car " << _deque[i-1] << " > " << _deque[i] << "\n";
			break;
		}
	}

  	std::cout << '\n';

	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << std::fixed
		<< _timeVector * 1000  << " ms" << std::endl;

	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque   : " << std::fixed
		<< _timeDeque * 1000 << " ms" << std::endl;
}
