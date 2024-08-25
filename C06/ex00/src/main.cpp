#include "main.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "usage: ./convert <string>" << std::endl, 0);
	ScalarConverter::convert(argv[1]);

	// std::string input;
	// while (true)
	// {
	// 	std::cout << "input: " << std::flush;
	// 	std::getline(std::cin, input);
	// 	if (input.empty())
	// 		std::cout << "Please enter a valid input." << std::endl;
	// 	if (input.size())
	// 		ScalarConverter::convert(input);
	// 	input.clear();
	// }
    return (0);
}