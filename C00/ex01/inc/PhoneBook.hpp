#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		Contact contacts[8];
		int		contactCount;
		PhoneBook();
		void		addContact();
		void		getInput(std::string str, std::string& input) const;
		void		searchContact(int index) const;
		void		displayContact(Contact contact) const;
		int			StringIsAlpha(std::string input) const;
		int			StringIsNum(std::string input) const;
		int			StringIsAlphaNum(std::string input) const;
		std::string formatString(const std::string& input);
		std::string alphaStr;
		std::string alphaNumStr;
		std::string	firstNameStr;
		std::string	lastNameStr;
		std::string	nicknameStr;
		std::string	phoneNumberStr;
		std::string	darkestSecretStr;
};

#endif