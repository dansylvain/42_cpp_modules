#include "main.hpp"
#include "ScalarConverter.hpp"

int main(void)
{
    std::cout << "Welcome to the Jungle" << std::endl;
	std::string input;

	while (true)
	{
		std::cout << "input: " << std::flush;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Please enter a valid input." << std::endl;
		}
		if (input.size())
		{
			ScalarConverter::convert(input);
		}
		input.clear();
	}
    return (0);
}