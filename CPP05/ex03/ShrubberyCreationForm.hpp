#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>
# include <fstream>

class ShrubberyCreationForm : public Form
{

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm(void);

	std::string		getTarget(void) const;
	virtual bool	beSigned(const Bureaucrat &bureaucrat);
	virtual bool	execute(const Bureaucrat &executor) const;

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};

private:
	std::string	_target;

};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &rhs);

#endif
