#ifndef EASYFIND_HPP
# define EADYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <deque>
#include <list>
//#include <queue>		doesnt allow iterators :(
//#include <stack>		same
#include <vector>

template<typename T>
int easyfind(T &container, int toFind)
{
	typename T::iterator	found = find( container.begin(), container.end(), toFind );

	if (found == container.end())
		return (*container.end());
	else
		return (*found);
}

#endif
