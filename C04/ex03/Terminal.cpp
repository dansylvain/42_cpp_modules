#include "Terminal.hpp"
#include "unistd.h"

Terminal::Terminal() :
	terminalCommand("gnome-terminal --geometry=150x24 -- bash -c \"./exec; exec bash\""),
	clearCommand("clear"),
	contentMenu("Welcome to the jungle : "),
	headerAdd("\033[1;32m Add a New Contact\n\033[0m\n"),
	contentSearch("\033[1;32m Search Contact Form\n\033[0m\n"),
	headerDisplay("\033[1;32m Contact Details\033[0m\n"),
	promptDisplay("New search? (Y/N)"),
	errorMessage("Error\n"),
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