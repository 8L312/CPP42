#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("NoName"), _grade(150)
{
	//std::cout << "Default constructor of Bureaucrat called\n";
	return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name)
{
	try
	{
		if (grade < 1 || 150 < grade)
		{
			if (grade < 1 )
				throw GradeTooHighException();
			else
				throw GradeTooLowException();
		}
		else
			this->_grade = grade;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "The grade of " << name << " is too high, we keeped grade 1\n";
		this->_grade = 1;
		return ;
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "The grade of " << name << " is too low, we keeped grade 150\n";
		this->_grade = 150;
		return ;
	}

	//std::cout << "Parametric constructor of Bureacrat called\n";
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	//std::cout << "Copy constructor of Bureaucrat called\n";
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Destructor of Bureaucrat called\n";
	return ;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::Upgrade(void)
{
	try
	{
		if (this->_grade >= 2)
			this->_grade--;
		else
			throw GradeTooHighException();
		return ;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "The grade of " << this->_name << " is already maxed, no promotion needed for the Boss\n";
		return ;
	}
}

const char *Bureaucrat::GradeTooHighException::tooHigh(void) const throw()
{
	return ("The grade of your Bureaucrat is too high\n");
}

void	Bureaucrat::Downgrade(void)
{
	try
	{
		if (this->_grade <= 149)
			this->_grade++;
		else
			throw GradeTooLowException();
		return ;
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "The grade of " << this->_name << " is already at bottom, no need to bully him\n";
		return ;
	}
}

const char *Bureaucrat::GradeTooLowException::tooLow(void) const throw()
{
	return ("The grade of your Bureaucrat is too low\n");
}

const char *Bureaucrat::FormNotSignedException::what(void) const throw()
{
	return ("The form is not signed\n");
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		if (form.beSigned(*this))
		{
			std::cout << "Bureaucrat " << this->_name << " signed form \""
				<< form.getName() << "\"\n";
		}
		else
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't sign form \"" << form.getName() << "\" because his grade was too low\n";
		return ;
	}
	return ;
}

void	Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		if (form.execute(*this) == true )
		{
			std::cout << "Bureaucrat " << this->_name << " executed form \""
				<< form.getName() << "\"\n";
		}
		else
		{
			if (form.isSigned() == false)
				throw FormNotSignedException();
			else
				throw GradeTooLowException();
		}
	}
	catch (FormNotSignedException &e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't execute form \""
			<< form.getName() << "\" because it is not signed\n";
		return ;
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't execute form \""
			<< form.getName() << "\" because his grade is too low\n";
		return ;
	}
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	//copy here the eventual values like :
	std::cout << "Name attribut is const and cant' be modified : only the grade was copied\n";
	this->_grade = rhs._grade;

	//std::cout << "Copy assignment operator of Bureaucrat called\n";
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
}
