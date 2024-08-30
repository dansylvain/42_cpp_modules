#include "main.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <list>
#include <stack>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		return (std::cout << "Usage: ./RPN <expression>." << std::endl, 1);
	RPN rpnCalculator;
	if (!rpnCalculator.checkInput(argv[1]))
		return (std::cout << "invalid input." << std::endl, 1);

	rpnCalculator.createStack(argv[1]);
	rpnCalculator.displayStack();



	return (0);
}
