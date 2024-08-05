#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class	Terminal
{
	public:
		Terminal();
		void			execSystemCmd(std::string str) const;
		void			displayString(std::string str) const;
		void			displayError(std::string str) const;
		static void		framingFuncOutput(int len, std::string title, void (*f1)(void), void (*f2)(void));
		static void		FramingFuncOutputNoMethod(int *i);
		static void 	displayAppState();
		static void		print(std::string str);	
		static void		printB(const std::string& str);
		static void		printF(std::string str);
		static void		printFB(const std::string& str);
		std::string		terminalCommand;
		std::string		clearCommand;
		std::string		contentMenu;
		std::string		errorMessage;
};

#endif