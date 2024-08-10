#include "main.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string input;

	if (argc == 2)
	{
		input = argv[1];
		ScalarConverter::convert(input);
	}
	else
		print("Usage: ./convert <number>");

	return (0);
}

void print(const std::string& str)
{
		std::cout << str << std::endl;
}

void printB(const std::string& str)
{
		std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}