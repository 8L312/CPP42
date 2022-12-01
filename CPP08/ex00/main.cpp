#include "easyfind.hpp"

int main()
{
	int myints[] = { 10, 20, 30, 40, -8, 0};

	std::vector<int> myvector(myints, myints + 6);
	std::cout << "vector end = " << *myvector.end() << std::endl;
	std::cout << "easyfind(10) = " << ::easyfind(myvector, 10) << std::endl;
	std::cout << "easyfind(42) = " << ::easyfind(myvector, 42) << "\n\n";

	std::deque<int> mydeque(myints, myints + 6);
	std::cout << "deque end = " << *mydeque.end() << std::endl;
	std::cout << "easyfind(40) = " << ::easyfind(mydeque, 40) << std::endl;
	std::cout << "easyfind(2) = " << ::easyfind(mydeque, 2) << "\n\n";

	std::list<int> mylist(myints, myints + 6);
	std::cout << "list end = " << *mylist.end() << std::endl;
	std::cout << "easyfind(-8) = " << ::easyfind(mylist, -8) << std::endl;
	std::cout << "easyfind(88) = " << ::easyfind(mylist, 88) << "\n\n";

//	std::queue<int> myqueue(myints, myints + 6);
//	std::cout << "found = " << *::easyfind(myqueue, 30) << "\n\n";

//	std::stack<int> mystack(myints, myints + 6);
//	std::cout << "found = " << *::easyfind(mystack, 30) << "\n\n";

	return (0);
}
