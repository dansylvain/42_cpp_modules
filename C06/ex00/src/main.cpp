#include "main.hpp"

int main(int argc, char **argv)
{
	std::string num;

	if (argc == 2)
	{
		num = argv[1];
		print(num);
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