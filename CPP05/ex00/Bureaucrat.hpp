#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>

class Bureaucrat
{

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

	void			Upgrade(void);
	void			Downgrade(void);

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *tooHigh(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *tooLow(void) const throw();
	};

private:
	std::string	const	_name;
	unsigned int		_grade;

};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif
