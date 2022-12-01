#include "Intern.hpp"

Intern::Intern(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

Intern::Intern(Intern const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

Intern::~Intern(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

Form	*Intern::makeForm(std::string name, std::string target) const
{
	std::string	forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	try
	{
		int		n = 3;
		Form	*ret = NULL;

		for (int i = 0; i < 3; i++)
			n = (name == forms[i] ? i : n);

		switch (n)
		{
			case 0:
				ret = new ShrubberyCreationForm(target);
				return (ret);
			case 1:
				ret = new RobotomyRequestForm(target);
				return (ret);
			case 2:
				ret = new PresidentialPardonForm(target);
				return (ret);
			default:
				throw FormNameNotValidException();
				break ;
		}
		return (ret);
	}
	catch (FormNameNotValidException &e)
	{
		std::cout << e.what() << std::endl;
		std::exit(1);
		return (NULL);
	}
}

const char	*Intern::FormNameNotValidException::what(void) const throw()
{
	return ("The form name is not valid :O");
}

Intern	&Intern::operator=(Intern const &rhs)
{
	//copy here the eventual values like :
	(void)rhs;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}
