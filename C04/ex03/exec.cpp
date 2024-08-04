#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Terminal.hpp"	
#include <sstream>

void	print(std::string str);
void	printB(const std::string& str);
void printFB(const std::string& str);

void	printF(std::string str);
void	test_one();
void	test_two();
void	test_three();
void	test_four();

bool TEST;




int main()
{
	std::string userInput;
	Terminal term;
	while (1)
	{
		// term.execSystemCmd(term.clearCommand);
		term.displayString(term.contentMenu);
		// term.getUserinput(userInput);
		std::getline(std::cin, userInput);
		std::istringstream iss(userInput);
		std::string token;
		std::string tokens[3];
		int i = 0;

		while (iss >> token)
		{
			if (i == 4)
				break;
			std::cout << "token " << i << ": " << token << " \n" << std::flush;
			tokens[i++] = token;
		}
		if ((i == 2 && tokens[0] != "CREATE") || i > 3 || (i > 2 && (tokens[0] == "CREATE" || tokens[0] == "LEARN")) || i == 1 || (i == 2 && (tokens[0] != "CREATE" && tokens[0] != "LEARN"))) 
			term.displayError(term.errorMessage);
		if (i == 3 && tokens[1] != "EQUIP" && tokens[1] != "UNEQUIP" && tokens[1] != "USE" && tokens[1] != "LEARN")
			term.displayError(term.errorMessage);
		// if ()
		// 	term.displayError(term.errorMessage);

	}
	return 0;

	TEST = false;
	test_four();
	return 0;
}

void	print(std::string str)
{
	if (TEST)
		std::cout << str << std::endl;
}

void printB(const std::string& str)
{
	if (TEST)
		std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}

void	printF(std::string str)
{
		std::cout << str << std::endl;
}

void printFB(const std::string& str)
{
	std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}