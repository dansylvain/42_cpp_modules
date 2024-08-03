#include "Terminal.hpp"
#include "unistd.h"

Terminal::Terminal() :
	terminalCommand("gnome-terminal -- bash -c \"./exec; exec bash\""),
	clearCommand("clear"),
	contentMenu("\033[1;32m Welcome to My Awesome PhoneBook\033[0m\n\n\
\033[1;31m - ADD\033[0m 		\033[1;32m=>\033[0m	add a new contact\n\
\033[1;31m - SEARCH\033[0m	\033[1;32m=>\033[0m	search for a contact\n\
\033[1;31m - EXIT\033[0m	 	\033[1;32m=>\033[0m	exit the phonebook\n\n\
\033[1;32m Your choice: \033[0m"),
	headerAdd("\033[1;32m Add a New Contact\n\033[0m\n"),
	contentSearch("\033[1;32m Search Contact Form\n\033[0m\n"),
	headerDisplay("\033[1;32m Contact Details\033[0m\n"),
	promptDisplay("New search? (Y/N)"),
	errorMessage("\033[8;2H\033[1;31mInvalid choice\033[0m \
	\033[7;14H                                               \033[7;14H"),
	contactAddedMessage("\n\033[1;32m Contact added successfully!\033[0m"),
	searchTabHeader("\033[1;31m	|     index|first name| last name|  nickname| \033[0m\n"),
	searchPrompt("\033[13;2H\033[1;32mEnter an index:                                   \
	\033[13;18H\033[0m"),
	searchEndPrompt("\033[1;32m\nPress Enter to continue...\033[0m")
	{}


void	Terminal::execSystemCmd(std::string str) const
		{std::system(str.c_str());}

void	Terminal::displayString(std::string str) const
		{std::cout << str << std::flush;};

void	Terminal::displayError(std::string str) const
		{std::cout << str << std::flush;sleep(1);};

void	Terminal::getUserinput(std::string& userInput)
		{std::getline(std::cin, userInput);};