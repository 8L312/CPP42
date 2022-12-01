#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:
	Form(void);
	Form(std::string name, unsigned int toSign, unsigned int toExec);
	Form(Form const &src);
	virtual ~Form(void);

	std::string		getName(void) const;
	bool			isSigned(void) const;
	unsigned int	getGradeToSign(void) const;
	unsigned int	getGradeToExec(void) const;
	void			setSignature(bool status);

	virtual bool	beSigned(const Bureaucrat &bureaucrat) = 0;
	virtual bool	execute(const Bureaucrat &executor) const = 0;

	Form	&operator=(Form const &rhs);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*tooHigh(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*tooLow(void) const throw();
	};

private:
	std::string	const	_name;
	bool				_signed;
	const unsigned int	_toSign;
	const unsigned int	_toExec;

};

std::ostream	&operator<<(std::ostream &out, Form const &rhs);

#endif
