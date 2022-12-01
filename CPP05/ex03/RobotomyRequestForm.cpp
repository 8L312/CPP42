#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	Form("RobotomyRequestForm", 72, 45), _target("Random target")
{
	//std::cout << "Default constructor called\n";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("RobotomyRequestForm", 72, 45), _target(target)
{
	//std::cout << "Parametric constructor called\n";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):
	Form("RobotomyRequestForm", 72, 45), _target(src._target)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

bool	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (!this->isSigned())
			throw FormNotSignedException();
		if (executor.getGrade() >= this->getGradeToExec())
			throw GradeTooLowException();

		std::srand((unsigned)std::time(0));
		int	random = rand();

		std::cout << "*Drill noise*...\n";
		if (random % 2)
		{
			std::cout << "Congratulation ! " << this->_target
				<< " has been robotomised with success\n";
		}
		else
		{
			std::cout << "Oh no ! We failed the robotomy of " << this->_target
				<< std::endl;;
		}
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

bool	RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
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

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	//copy here the eventual values like :
	this->_target = rhs._target;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

const char	*RobotomyRequestForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the bureaucrat is too low to execute this Form\n");
}

const char	*RobotomyRequestForm::FormNotSignedException::what(void) const throw()
{
	return ("This Form isn't signed\n");
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &rhs)
{
	out << "Form name: " << rhs.getName()
		<< ", signed: " << ((rhs.isSigned()) ? "YES" : "NO")
		<< ", grade to sign: " << rhs.getGradeToSign()
		<< ", grade to execute: " << rhs.getGradeToExec()
		<< ", Target: " << rhs.getTarget();
	return (out);
}
