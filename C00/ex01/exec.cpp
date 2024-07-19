#include "Terminal.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "unistd.h"

void	addNewUser(Terminal *term, PhoneBook *phoneBook);
void	searchUser(Terminal *term, PhoneBook *phoneBook);

int main(void)
{
	Terminal term;
	PhoneBook phoneBook;
	std::string userInput;

	while (1)
	{
		term.execSystemCmd(term.clearCommand);
		term.displayString(term.contentMenu);
		term.getUserinput(userInput);

		if (userInput == "ADD")
			addNewUser(&term, &phoneBook);
		else if (userInput == "SEARCH" && phoneBook.contactCount > 0)
			searchUser(&term, &phoneBook);
		else if (userInput == "EXIT")
			break;
		else
			term.displayError(term.errorMessage);
	}
	return 0;
}

void	addNewUser(Terminal *term, PhoneBook *phoneBook)
{
	(*term).execSystemCmd((*term).clearCommand);
	(*term).displayString((*term).headerAdd);
	(*phoneBook).addContact();
	std::cout << (*term).contactAddedMessage << std::flush;
	sleep(1);
}

void	searchUser(Terminal *term, PhoneBook *phoneBook)
{
	std::string userInput;

	(*term).execSystemCmd((*term).clearCommand);
	(*term).displayString((*term).contentSearch);
	std::string pipe = "\033[1;31m|\033[0m";
	std::cout << (*term).searchTabHeader << std::flush;
	for (int i = 0 ; i < 8 && i < (*phoneBook).contactCount; i++)
	{
		std::cout << "	" << pipe << "         " << i << pipe << 
		(*phoneBook).formatString((*phoneBook).contacts[i].getFirstName()).c_str()
		<< pipe << (*phoneBook).formatString((*phoneBook).contacts[i].getLastName())
		<< pipe << (*phoneBook).formatString((*phoneBook).contacts[i].getNickname())
		<< pipe << std::endl;
	}
	do {std::cout << (*term).searchPrompt << std::flush;std::getline(std::cin, userInput);}
	while (userInput.length() != 1 || userInput[0] < '0'
		|| userInput[0] >= (*phoneBook).contactCount + '0');
	std::cout << std::endl;
	(*phoneBook).searchContact(userInput[0] - '0');
	std::cout << (*term).searchEndPrompt << std::flush;
	std::getline(std::cin, userInput);
}