#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class	Terminal
{
	public:
		Terminal();
		void	execSystemCmd(std::string str) const;
		void	displayString(std::string str) const;
		void	displayError(std::string str) const;
		void	getUserinput(std::string& userInput);
		static void	framingFuncOutput(int len, void (*f)(void));
		void	print(std::string str);	
		void	printB(const std::string& str);
		void	printF(std::string str);
		void	printFB(const std::string& str);
		std::string terminalCommand;
		std::string clearCommand;
		std::string contentMenu;
		std::string headerAdd;
		std::string contentSearch;
		std::string headerDisplay;
		std::string promptDisplay;
		std::string errorMessage;
		std::string contactAddedMessage;
		std::string searchTabHeader;
		std::string searchPrompt;
		std::string searchEndPrompt;
};

#endif