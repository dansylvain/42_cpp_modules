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

int main()
{
	printB("Test iter with int array");
	{	
		int array[] = {1, 2, 3, 4, 5};
		unsigned int len = sizeof(array) / sizeof(array[0]);
		iter(array, len, print);
	}
	pause();
	printB("Test iter with char array");
	{	
		char array[] = {'a', 'b', 'c', 'd', 'e'};
		unsigned int len = sizeof(array) / sizeof(array[0]);
		iter(array, len, print);
	}
	pause();
	printB("Test iter with std::string array");
	{	
		std::string array[] = {"Welcome", "to", "the", "jungle"};
		unsigned int len = sizeof(array) / sizeof(array[0]);
		iter(array, len, print);
	}
	return 0;
}