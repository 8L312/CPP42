#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>

class PresidentialPardonForm : public Form
{

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm(void);

	std::string		getTarget(void) const;
	virtual bool	beSigned(const Bureaucrat &bureaucrat);
	virtual bool	execute(const Bureaucrat &executor) const;

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

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

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &rhs);
#endif
