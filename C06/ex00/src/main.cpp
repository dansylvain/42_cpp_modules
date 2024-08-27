#include "ScalarConverter.hpp"

int main()
{
	{
		std::string tab[] = {"0", "nan", "42.0f"};
		size_t size = sizeof(tab) / sizeof(tab[0]);
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "\n./convert " << "\033[31;1m" << tab[i] << "\033[0m" << std::endl;
			ScalarConverter::convert(tab[i]);
		}
	}
    pause();
	{
		std::string tab[] = {"-42", "0.42f", "7777777777777777777777777", "-76.765472f"
								, "Ich bin ein Kartofel"};
		size_t size = sizeof(tab) / sizeof(tab[0]);
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "\n./convert " << "\033[31;1m" << tab[i] << "\033[0m" << std::endl;
			ScalarConverter::convert(tab[i]);
		}
	}
	pause();
	{
		std::string tab[] = {"+inf", "+inff", "-inf", "-inff", "nan", "nanf"};
		size_t size = sizeof(tab) / sizeof(tab[0]);
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "\n./convert " << "\033[31;1m" << tab[i] << "\033[0m" << std::endl;
			ScalarConverter::convert(tab[i]);
		}
	}
	pause();
	std::cout << "Make your own tests!" << std::endl;
	std::string input;
	while (true)
	{
	std::cout << "\033[31;1mEnter a string representation of a C++ literal in its most common form (or type 'exit' to quit).\033[0m\nInput: " << std::flush;
		std::getline(std::cin, input);
		if (input == "exit")
			break;
		if (input.empty())
			continue;
		ScalarConverter::convert(input);
	}

	return (0);
}