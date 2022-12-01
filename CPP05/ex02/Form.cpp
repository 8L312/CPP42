#include "Form.hpp"

Form::Form(void) : _name("NoTitle"), _signed(false), _toSign(150), _toExec(150)
{
	this->_signed = false;
	//std::cout << "Default constructor called\n";
	return ;
}

Form::Form(std::string name, unsigned int toSign, unsigned int toExec) : _name(name), _toSign( (1 <= toSign && toSign <= 150) ? toSign : ( (toSign < 1) ? 1 : 150) ), _toExec( (1 <= toExec && toExec <= 150) ? toExec : ( (toExec < 1) ? 1 : 150) )
{
	this->_signed = false;
	int err = 0;

re:
	try
	{
		if (toSign < 1 || 150 < toSign)
		{
			err = 1;
			if (toSign < 1)
				throw GradeTooHighException();
			else
				throw GradeTooLowException();
		}
		if (toExec < 1 || 150 < toExec)
		{
			err = 2;
			if (toExec < 1)
				throw GradeTooHighException();
			else
				throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "The grade to " << ((err == 1) ? "sign" : "execute") << " Form \"" << name << "\" is too high. We keeped grade 1\n";
		toSign = 1;
		goto re;
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "The grade to " << ((err == 1) ? "sign" : "execute") << " Form \"" << name << "\" is too low. We keeped grade 150\n";
	}

	//std::cout << "Parametric constructor called\n";
	return ;
}

Form::Form(Form const &src) : _name(src._name), _toSign(src._toSign), _toExec(src._toExec)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

Form::~Form(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (this->_toSign);
}

unsigned int	Form::getGradeToExec(void) const
{
	return (this->_toExec);
}

void	Form::setSignature(bool status)
{
	this->_signed = status;
	return ;
}

/*
bool	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_toSign >= bureaucrat.getGrade())
		this->_signed = true;
	else
	{
		if (this->_signed == true)
			return (false);
	}
	return (this->_signed);
}*/

Form	&Form::operator=(Form const &rhs)
{
	//copy here the eventual values like :
	this->_signed = rhs._signed;
	std::cout << "Name, toSign and toExec attributes are const and can't be modified, only \"signed\" was copied\n";

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

const char *Form::GradeTooHighException::tooHigh(void) const throw()
{
	return ("The grade is too high\n");
}

const char *Form::GradeTooLowException::tooLow(void) const throw()
{
	return ("The grade is too low\n");
}

std::ostream	&operator<<(std::ostream &out, Form const &rhs)
{
	if (rhs.isSigned())
		out << "Form name: " << rhs.getName() << ", signed: YES, grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExec();
	else
		out << "Form name: " << rhs.getName() << ", signed: NO, grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExec();
	return (out);
}
