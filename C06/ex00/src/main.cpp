#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <string>

enum PseudoLiterals {
	NEG_INFF,
	POS_INFF,
	NEG_INF,
	POS_INF,
	NAN,
	NUM_PSEUDO_LITERALS
};

const std::string pseudoLiteralsArray[NUM_PSEUDO_LITERALS] = {
	"-inff"
	"+inff"
	"-inf",
	"+inf",
	"nan"
};



int main() {
	std::string input;

	while (1)
	{
			std::cin >> input;
			if (ScalarConverter::isInt(input)) {
				std::cout << "Int" << std::endl;
			} else if (ScalarConverter::isChar(input)) {
				std::cout << "Char" << std::endl;
			} else if (ScalarConverter::isFloat(input)) {
				std::cout << "Float" << std::endl;
			} else if (ScalarConverter::isDouble(input)) {
				std::cout << "Double" << std::endl;
			} else {
				std::cout << "Unknown type" << std::endl;
			}
	}

	return 0;
}