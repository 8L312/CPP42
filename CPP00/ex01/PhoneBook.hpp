#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <cstring>
# include <stdlib.h>
# include "PhoneBook.hpp"
# include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	start(void);

private:
	void	menu(void);
	Contact	add(void);
	void	search(void);
	void	exit(void);
	int		setContact_number(int i);
	int		getContact_number(void);
	int		setContact(Contact contact, int index);
	Contact	getContact(int index);

	int		_Contact_number;
	Contact _Contact_Tab[8];
};

#endif
