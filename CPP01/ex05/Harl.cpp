#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	std::string	index[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	n = 4;

	for (int i = 0; i < 4; i++)
		n = (level == index[i] ? i : n);
	switch (n)
	{
		case 0:
			this->FuncPtr = &Harl::_debug;
			break ;
		case 1:
			this->FuncPtr = &Harl::_info;
			break ;
		case 2:
			this->FuncPtr = &Harl::_warning;
			break ;
		case 3:
			this->FuncPtr = &Harl::_error;
			break ;
		default:
			std::cout << "This level doesn't exists" << std::endl;
			return ;
	}
	return ( (this->*FuncPtr)() );
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n";
	return ;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	return ;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	return ;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
	return ;
}
