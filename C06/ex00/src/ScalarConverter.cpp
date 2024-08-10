#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <limits>
#include <string>
#include <stdexcept>

#include "main.hpp"

/**========================================================================
 *                           ACTION METHOD
 *========================================================================**/
void ScalarConverter::convert(const std::string& literal)
{
	char charNum;
	int intNum;
	float floatNum;
	double doubleNum;

	charNum = std::stoi(literal.c_str());
	std::cout << "charNum: " << charNum << std::endl;
	std::cout << "input: " << literal << std::endl;
	intNum = std::stoi(literal.c_str());
	std::cout << "intNum: " << static_cast<int>(intNum) << std::endl;
	floatNum = std::stof(literal.c_str());
	std::cout << "floatNum: " << static_cast<float>(floatNum) << std::endl;
	doubleNum = std::stod(literal.c_str());
	std::cout << "doubleNum: " << static_cast<double>(doubleNum) << std::endl;

}

