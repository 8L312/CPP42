#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
//	std::cout << "Constructor of Phonebook called\n" << std::endl;
	this->_Contact_number = 0;
	this->menu();
	return ;
}

PhoneBook::~PhoneBook(void) {
//	std::cout << "Destructor of PhoneBook called\n" << std::endl;
	return ;
}

void	PhoneBook::start(void) {
	this->menu();
	return ;
}

void	PhoneBook::menu(void) {

	std::string	cmd;
	int			i = 0;

	std::cout << " ****************************" << std::endl;
	std::cout << " * Welcome to the PhoneBook *" << std::endl;
	std::cout << " ****************************" << std::endl << std::endl;;

	command:
	{
		if (std::cin == NULL)
			return ;
		std::cout << "*******************************" << std::endl;
		std::cout << "* You can ADD, SEARCH or EXIT *" << std::endl;
		std::cout << "*******************************" << std::endl;
		std::cout << std::endl << "Command: ";
		std::getline(std::cin, cmd);
		if (std::cin == NULL)
			return ;
		if (cmd == "")
			std::cout << std::endl << "!!! You must enter a command !!!" << std::endl;
		else if (cmd == "ADD")
		{
			if (this->getContact_number() == 8)
			{
				i = -1;
				while (++i < 7)
					this->setContact(this->getContact(i + 1), i);
				this->setContact(this->add(), 7);
			}
			else
			{
				this->setContact(this->add(), this->getContact_number());
				this->setContact_number(++i);
			}
		}
		else if (cmd == "SEARCH")
			this->search();
		else if (cmd == "EXIT")
			return ;
		else
			std::cout << std::endl << cmd << ": command not valid ¯\\_(ツ)_/¯" << std::endl;
		std::cout << std::endl;
		goto command;
	}
	return ;
}

int	PhoneBook::setContact_number(int i) {

	if (0 < i && i <= 8)
		this->_Contact_number = i;
	else
		return (1);
	return (0);
}

int	PhoneBook::getContact_number(void) {

	return (this->_Contact_number);
}

int	PhoneBook::setContact(Contact contact, int index) {

	this->_Contact_Tab[index] = contact;
	return (0);
}

Contact	PhoneBook::getContact(int index) {

	return (this->_Contact_Tab[index]);
}

Contact	PhoneBook::add(void) {

	Contact		contact;
	std::string	tmp;
	int	ok = 0;

	// First name //
	while (ok == 0)
	{
		std::cout << "Enter first name : ";
		std::getline(std::cin, tmp);
		if (std::cin == NULL)
			goto stop;
		if (tmp[0] == '\0')
			std::cout << "You must enter a value ><" << std::endl;
		else 
		{
			contact.setInfo("fn", tmp);
				ok = 1;
		}
	}
	
	// Last name //
	ok = 0;
	while (ok == 0)
	{
		std::cout << "Enter last name : ";
		std::getline(std::cin, tmp);
		if (std::cin == NULL)
			goto stop;
		if (tmp[0] == '\0')
			std::cout << "You must enter a value ><" << std::endl;
		else
		{
			contact.setInfo("ln", tmp);
			ok = 1;
		}
	}

	// Nickname //
	ok = 0;
	while (ok == 0)
	{
		std::cout << "Enter nickname : ";
		std::getline(std::cin, tmp);
		if (std::cin == NULL)
			goto stop;
		if (tmp[0] == '\0')
			std::cout << "You must enter a value ><" << std::endl;
		else
		{
			contact.setInfo("nn", tmp);
			ok = 1;
		}
	}

	// Phone number //
	ok = 0;
	while (ok == 0)
	{
		std::cout << "Enter phone number : ";
		std::getline(std::cin, tmp);
		if (std::cin == NULL)
			goto stop;
		if (tmp[0] == '\0')
			std::cout << "You must enter a value ><" << std::endl;
		else
		{
			unsigned int x = 0;
			while (tmp[x] != '\0')
			{
				if (tmp[x] <= 47 || 57 < tmp[x])
					break ;
				x++;
			}
			if (x == tmp.length())
			{
				contact.setInfo("pn", tmp);
				ok = 1;
			}
			else
				std::cout << "Thats not even numbers dude u.U" << std::endl;
		}
	}

	// Darkest secret //
	ok = 0;
	while (ok == 0)
	{
		std::cout << "Enter a dark secret : ";
		std::getline(std::cin, tmp);
		if (std::cin == NULL)
			goto stop;
		if (tmp[0] == '\0')
			std::cout << "You must enter a value ><" << std::endl;
		else
		{
			contact.setInfo("ds", tmp);
			ok = 1;
		}
	}
	return (contact);

	stop:
		Contact	empty;
		return (empty);
}

void PhoneBook::search(void) {
	
	///////////////////
	// if no contact //
	///////////////////

	if (this->_Contact_number == 0)
	{
		std::cout << "No contact for the moment, go get some friends" << std::endl;
		return ;
	}
	
	///////////////////////////
	// Display contact index //
	///////////////////////////

	int i = 0;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (++i <= this->_Contact_number)
	{
		char	tmp[11];

		// Index //
		std::cout << "|         ";
		std::cout << i << "|";

		// First name //
		std::size_t len = this->_Contact_Tab[i - 1].getInfo("fn").copy(tmp, 10);
		tmp[len] = '\0';
		if (len < 10)
		{
			while (len++ < 10)
				std::cout << " ";
			std::cout << tmp << "|";
		}
		else
		{
			if (this->_Contact_Tab[i - 1].getInfo("fn").length() == 10)
				std::cout << tmp << "|";
			else
			{
				tmp[9] = '.';
				tmp[10] = '\0';
				std::cout << tmp << "|";	
			}
		}

		//Last name //
		len = this->_Contact_Tab[i - 1].getInfo("ln").copy(tmp, 10);
		tmp[len] = '\0';
		if (len < 10)
		{
			while (len++ < 10)
				std::cout << " ";
			std::cout << tmp << "|";
		}
		else
		{
			if (this->_Contact_Tab[i - 1].getInfo("ln").length() == 10)
				std::cout << tmp << "|";
			else
			{
				tmp[9] = '.';
				tmp[10] = '\0';
				std::cout << tmp << "|";
			}
		}

		// Nickname //
		len = this->_Contact_Tab[i - 1].getInfo("nn").copy(tmp, 10);
		tmp[len] = '\0';
		if (len < 10)
		{
			while (len++ < 10)
				std::cout << " ";
			std::cout << tmp << "|";
		}
		else
		{
			if (this->_Contact_Tab[i - 1].getInfo("nn").length() == 10)
				std::cout << tmp << "|";
			else
			{
				tmp[9] = '.';
				tmp[10] = '\0';
				std::cout << tmp << "|";
			}
		}

		// New line or not //
		std::cout << std::endl;
		if (i < this->_Contact_number)
			std::cout << "|----------|----------|----------|----------|" << std::endl;
	}

	// End of tab //
	std::cout << "|----------|----------|----------|----------|" << std::endl;



	//////////////////////////////////////
	// Choice of the contact to display //
	//////////////////////////////////////

	choose:
	{
		std::cout << "Choose a contact index to display: ";
		std::string	num;
		std::getline(std::cin, num);
		if (std::cin == NULL)
			return ;
		if (0 < atoi(num.c_str()) && atoi(num.c_str()) <= this->_Contact_number)
		{
			// Display all contact infos //
			i = atoi(num.c_str());
			std::cout << std::endl;
			std::cout << "First name: " << this->_Contact_Tab[i - 1].getInfo("fn") << std::endl;
			std::cout << "Last name: " << this->_Contact_Tab[i - 1].getInfo("ln") << std::endl;
			std::cout << "Nickname: " << this->_Contact_Tab[i - 1].getInfo("nn") << std::endl;
			std::cout << "Phone number: " << this->_Contact_Tab[i - 1].getInfo("pn") << std::endl;
			std::cout << "Darkest secret: " << this->_Contact_Tab[i - 1].getInfo("ds") << std::endl;
		}
		else
		{
			// Not a valid contact index //
			std::cout << std::endl << "Not a valid index :(" << std::endl << std::endl;
			goto choose;
		}
	}
	return ;
}
