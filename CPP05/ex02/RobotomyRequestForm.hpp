#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Form
{

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm(void);

	std::string		getTarget(void) const;
	virtual bool	beSigned(const Bureaucrat &bureaucrat);
	virtual bool	execute(const Bureaucrat &executor) const;

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

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

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &rhs);

#endif
