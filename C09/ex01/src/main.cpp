#include "main.hpp"
#include <iostream>
#include <string>
#include <cstring>

bool checkInput(char input[])
{
	int operandCount = 0;
	int nbrCount;

	char* token = std::strtok(input, " 	");
	while (token)
	{
		if (std::isdigit(token[0]))
		{
			operandCount++;
			nbrCount++;
		}
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			if (operandCount-- != 2)
				return (false);
		}
		else
			return (false);
		token = std::strtok(NULL, " ");
	}
	return (operandCount == 1 && nbrCount <= 10);
}

int main(int argc, char** argv)
{
	if (argc != 2)
		return (std::cout << "Usage: ./RPN <expression>." << std::endl, 1);

	char input_copy[256];
    std::strncpy(input_copy, argv[1], sizeof(input_copy));
	if (!checkInput(input_copy))
		return (std::cout << "invalid input." << std::endl, 1);

	return (0);
}
