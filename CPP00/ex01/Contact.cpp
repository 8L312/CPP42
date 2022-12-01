#include "Contact.hpp"

Contact::Contact(void) {
//	std::cout << "Constructor of Contact called" << std::endl;
	return ;
}

Contact::~Contact(void) {
//	std::cout << "Destructor of Contact called" << std::endl;
	return ;
}

void	Contact::setInfo(std::string info, std::string value) {

	if (info == "fn")
		this->_first_name = value;
	else if (info == "ln")
		this->_last_name = value;
	else if (info == "nn")
		this->_nickname = value;
	else if (info == "pn")
		this->_phone_number = value;
	else if (info == "ds")
		this->_secret = value;
}

std::string	Contact::getInfo(std::string info) {

	if (info == "fn")
		return (this->_first_name);
	else if (info == "ln")
		return (this->_last_name);
	else if (info == "nn")
		return (this->_nickname);
	else if (info == "pn")
		return (this->_phone_number);
	else if (info == "ds")
		return (this->_secret);
	return (NULL);
}
