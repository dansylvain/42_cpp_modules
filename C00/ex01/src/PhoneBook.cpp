#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0),
	alphaStr("azertyuiopqsdfghjklmwxcvbn AZERTYUIOPQSDFGHJKLMWXCVBN-'\"éèàäëïöüùêîôûâ"),
	alphaNumStr("0123456789azertyuiopqsdfghjklmwxcvbn AZERTYUIOPQSDFGHJKLMWXCVBN-'\"éèàäëïöüùêîôûâ?!.;:+-=*5()"),
	firstNameStr("\033[1;31m- First Name: \033[0m"),
	lastNameStr("\033[1;31m- Last Name: \033[0m"),
	nicknameStr("\033[1;31m- Nickname: \033[0m"),
	phoneNumberStr("\033[1;31m- Phone Number: \033[0m"),
	darkestSecretStr("\033[1;31m- Darkest Secret: \033[0m")
 {}

void	PhoneBook::getInput(std::string str, std::string& input) const {
	std::cout << str << std::flush;
	std::getline(std::cin, input);
}

int		PhoneBook::StringIsAlpha(std::string input) const {
	if (input.empty() || input.find_first_not_of(PhoneBook::alphaStr)
		!= std::string::npos || input.length() > 50) {
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	return 1;
}

int		PhoneBook::StringIsNum(std::string input) const {
	if (input.empty() || input.find_first_not_of("0123456789 -/")
		!= std::string::npos || input.length() > 10) {
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	return 1;
}

int		PhoneBook::StringIsAlphaNum(std::string input) const {
	if (input.empty() || input.find_first_not_of(PhoneBook::alphaNumStr)
		!= std::string::npos || input.length() > 50) {
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	return 1;
}

std::string PhoneBook::formatString(const std::string& input) {
    std::string formatted;
    
    if (input.size() <= 10) {
        formatted = std::string(10 - input.size(), ' ') + input;
    } else {
        formatted = input.substr(0, 9) + ".";
    }
    
    return formatted;
}

void	PhoneBook::addContact() {
	std::string input;
	Contact contact;
	do{PhoneBook::getInput(PhoneBook::firstNameStr, input);}
	while (!PhoneBook::StringIsAlpha(input));
	contact.setFirstName(input);
	do{PhoneBook::getInput(PhoneBook::lastNameStr, input);}
	while (!PhoneBook::StringIsAlpha(input));
	contact.setLastName(input);
	do{PhoneBook::getInput(PhoneBook::nicknameStr, input);}
	while (!PhoneBook::StringIsAlphaNum(input));
	contact.setNickname(input);
	do {PhoneBook::getInput(PhoneBook::phoneNumberStr, input);}
	while (!PhoneBook::StringIsNum(input));
	contact.setPhoneNumber(input);
	do {PhoneBook::getInput(PhoneBook::darkestSecretStr, input);}
	while (!PhoneBook::StringIsAlphaNum(input));
	contact.setDarkestSecret(input);

	getContacts()[contactCount % 8] = contact;
	contactCount++;
}

void	PhoneBook::searchContact(int index) const {
	if (index < 0 || index >= contactCount) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	PhoneBook::displayContact(contacts[index]);
}

void	PhoneBook::displayContact(Contact contact) const {
	std::cout << PhoneBook::firstNameStr << "    " << contact.getFirstName() << std::endl;
	std::cout << PhoneBook::lastNameStr << "     " << contact.getLastName() << std::endl;
	std::cout << PhoneBook::nicknameStr << "      " << contact.getNickname() << std::endl;
	std::cout << PhoneBook::phoneNumberStr << "  " << contact.getPhoneNumber() << std::endl;
	std::cout << PhoneBook::darkestSecretStr << contact.getDarkestSecret() << std::endl;
}

Contact		*PhoneBook::getContacts()
{
	return (contacts);
}

int			PhoneBook::getContactCount()
{
 return (contactCount);
}
