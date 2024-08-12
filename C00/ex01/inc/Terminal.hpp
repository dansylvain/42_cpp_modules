#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "unistd.h"

/**========================================================================
 *                           TERMINAL
 *? all attributes ar made public because used by other classes 
 *========================================================================**/
class	Terminal
{
		std::string	terminalCommand;
		std::string	clearCommand;
	public:
		std::string	contentMenu;
		std::string	headerAdd;
		std::string	contentSearch;
		std::string	headerDisplay;
		std::string	promptDisplay;
		std::string	errorMessage;
		std::string	contactAddedMessage;
		std::string	searchTabHeader;
		std::string	searchPrompt;
		std::string	searchEndPrompt;
		Terminal();
		void		execSystemCmd(std::string str) const;
		void		displayString(std::string str) const;
		void		displayError(std::string str) const;
		void		getUserinput(std::string& userInput) const;
		std::string	getTerminalCommand();
		std::string	getClearCommand();

};

#endif