#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void	iter( T *tab, size_t size, void (*fct)(const T &) )
{
	for (size_t i = 0; i < size; i++)
		fct(tab[i]);
	return ;
}

template<typename T>
void	template_fct(T const &elem)
{
	std::cout << "Elem of tab = [" << elem << "] and its adress = {"
		<< &elem << "}\n";
	return ;
}

#endif
