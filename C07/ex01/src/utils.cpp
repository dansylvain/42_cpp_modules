#include "main.hpp"

void printInt(int& value)
{
    std::cout << value << std::endl;
}

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

void printChar(char& value) {
    std::cout << value << std::endl;
}

void printString(std::string& value) {
    std::cout << value << std::endl;
}

void	pause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}