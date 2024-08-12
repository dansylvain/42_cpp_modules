#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact 	contacts[8];
		int			contactCount	;
		std::string	alphaStr;
		std::string	alphaNumStr;
		std::string	firstNameStr;
		std::string	lastNameStr;
		std::string	nicknameStr;
		std::string	phoneNumberStr;
		std::string	darkestSecretStr;
	public:
		// constructors and destructor
		PhoneBook();
		// getters and setters
		Contact		*getContacts();
		void		getInput(std::string str, std::string& input) const;
		int			getContactCount();
		std::string getFormatString();
		// utils methods
		void		addContact();
		void		searchContact(int index) const;
		void		displayContact(Contact contact) const;
		std::string formatString(const std::string& input);
		int			StringIsAlpha(std::string input) const;
		int			StringIsNum(std::string input) const;
		int			StringIsAlphaNum(std::string input) const;
};

#endif