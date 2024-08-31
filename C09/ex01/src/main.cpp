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
	rpnCalculator.calculate(argv[1]);

	return (0);
}
