#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <cstring>
# include <stdlib.h>

class Contact {

public:
	Contact(void);
	~Contact(void);
	void		setInfo(std::string info, std::string value);
	std::string	getInfo(std::string info);

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_secret;
};

#endif
