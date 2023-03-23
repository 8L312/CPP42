#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <ctime>
# include <vector>
# include <deque>
#include <algorithm>

# define MAXDISPLAY 15 //max displayed values on output

class PmergeMe
{

public:
	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	~PmergeMe(void);
	
	void	takeArg(char **av);
	void	displayResults(void);

	void	sortVec(unsigned int p, unsigned int r);
	void	sortDeque(unsigned int p, unsigned int r);

	void	setTime(double time, std::string type);
	std::vector<unsigned int>	getVector(void) const;
	std::deque<unsigned int>	getDeque(void) const;

	PmergeMe	&operator=(PmergeMe const &rhs);

private:
	std::vector<unsigned int>	_vector;
	std::deque<unsigned int>	_deque;

	double		_timeVector;
	double		_timeDeque;

	void	mergeVec(unsigned int p, unsigned int q, unsigned int r);
	void	insertVec(unsigned int p, unsigned int q);
	void	mergeDeque(unsigned int p, unsigned int q, unsigned int r);
	void	insertDeque(unsigned int p, unsigned int q);
};

#endif
