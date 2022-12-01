#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	Form("PresidentialPardonForm", 25, 5), _target("Random target")
{
	//std::cout << "Default constructor called\n";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form("PresidentialPardonForm", 25, 5), _target(target)
{
	//std::cout << "Parametric constructor called\n";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):
	Form("PresidentialPardonForm", 25, 5), _target(src._target)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

bool	PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->setSignature(true);
	else
	{
		if (this->isSigned() == true)
			return (false);
	}
	return (this->isSigned());
}

bool	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (!this->isSigned())
			throw FormNotSignedException();
		if (executor.getGrade() >= this->getGradeToExec())
			throw GradeTooLowException();

		std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox\n";
		return (true);
	}
	catch (FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	//copy here the eventual values like :
	this->_target = rhs._target;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

const char	*PresidentialPardonForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the bureaucrat is too low to execute this Form\n");
}

const char	*PresidentialPardonForm::FormNotSignedException::what(void) const throw()
{
	return ("This Form isn't signed\n");
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &rhs)
{
	out << "Form name: " << rhs.getName()
		<< ", signed: " << ((rhs.isSigned()) ? "YES" : "NO")
		<< ", grade to sign: " << rhs.getGradeToSign()
		<< ", grade to execute: " << rhs.getGradeToExec()
		<< ", Target: " << rhs.getTarget();
	return (out);
}
