#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <string>
#include <iomanip>
enum PseudoLiterals
{
	NEG_INFF,
	POS_INFF,
	NEG_INF,
	POS_INF,
	NAN,
	NUM_PSEUDO_LITERALS
};

enum literalTpe
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	UNKNOWN
};

const std::string pseudoLiteralsArray[NUM_PSEUDO_LITERALS] = {
	"-inff"
	"+inff"
	"-inf",
	"+inf",
	"nan"
};

literalTpe getType(std::string str)
{
	literalTpe type;

	if (ScalarConverter::isInt(str))
		type = INT;
	else if (ScalarConverter::isChar(str))
		type = CHAR;
	else if (ScalarConverter::isFloat(str))
		type = FLOAT;
	else if (ScalarConverter::isDouble(str))
		type = DOUBLE;
	else if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf" || str == "nan")
		type = PSEUDOLITERAL;
	else
		type = UNKNOWN;
	return (type);
}

int main()
{
	double Value;
	std::string input;
	literalTpe type;

	while (1)
	{
		while (input.length() == 0)
		{
			std::cout << "input: " << std::flush;
			std::cin >> input;
		}
		type = getType(input);
		std::istringstream issInt(input);
		issInt >> Value;		
		if (type == CHAR)
		{
			Value = input[1];
		}
		if (std::isprint(static_cast<char>(Value)))
			std::cout << "char: " <<  static_cast<char>(Value) << std::endl;
		else 
			std::cout << "char: impossible" << std::endl;
		if (type != PSEUDOLITERAL)
			std::cout << "int: " <<  static_cast<int>(Value) << std::endl;
		else 
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) <<  static_cast<float>(Value) << "f" << std::endl;
		std::cout << "double: " <<  (Value) << std::endl;

		input.clear();
	}

	return (0);
}



