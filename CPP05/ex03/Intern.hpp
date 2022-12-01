#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>

class Intern
{

public:
	Intern(void);
	Intern(Intern const &src);
	~Intern(void);

	Form	*makeForm(std::string name, std::string target) const;

	class FormNameNotValidException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

	Intern	&operator=(Intern const &rhs);

private:

};

#endif
