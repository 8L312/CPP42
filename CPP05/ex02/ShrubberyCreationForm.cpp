#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	Form("ShrubberyCreationForm", 145, 137), _target("Random target")
{
	//std::cout << "Default constructor called\n";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	//std::cout << "Parametric constructor called\n";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):
	Form("ShrubberyCreationForm", 145, 137), _target(src._target)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

bool	ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
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

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (!this->isSigned())
			throw FormNotSignedException();
		if (executor.getGrade() >= this->getGradeToExec())
			throw GradeTooLowException();
		
		std::string		name;
		std::ofstream	outfile;

		name.insert(0, "_shrubbery");
		name.insert(0, this->_target.c_str());
		outfile.open(name.c_str());
		outfile << "               ,@@@@@@@," << std::endl;
		outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		outfile << "    ,&%.%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		outfile << "   %&&%/ %&%.%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		outfile << "       |o|        | |         | |" << std::endl;
		outfile << "       |.|        | |         | |" << std::endl;
		outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		outfile.close();
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

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	//copy here the eventual values like :
	this->_target = rhs._target;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

const char	*ShrubberyCreationForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the bureaucrat is too low to execute this Form\n");
}

const char	*ShrubberyCreationForm::FormNotSignedException::what(void) const throw()
{
	return ("This Form isn't signed\n");
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &rhs)
{
	out << "Form name: " << rhs.getName() 
		<< ", signed: " << ((rhs.isSigned()) ? "YES" : "NO")
		<< ", grade to sign: " << rhs.getGradeToSign()
		<< ", grade to execute: " << rhs.getGradeToExec()
		<< ", Target: " << rhs.getTarget();
	return (out);
}
