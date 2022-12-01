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
	func_ptr 	f[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	int i = -1;
	while (++i < 4)
	{
		if (level == index[i])
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "This level does not exists\n";
	return ;
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
