#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <limits>
#include <string>
#include <stdexcept>
#include <sstream>

#include "main.hpp"

/**========================================================================
 *                           ACTION METHOD
 *========================================================================**/
// void ScalarConverter::convert(const std::string& literal)
// {
// 	char charNum;
// 	int intNum;
// 	float floatNum;
// 	double doubleNum;

// 	charNum = std::stoi(literal.c_str());
// 	std::cout << "charNum: " << charNum << std::endl;
// 	std::cout << "input: " << literal << std::endl;
// 	intNum = std::stoi(literal.c_str());
// 	std::cout << "intNum: " << static_cast<int>(intNum) << std::endl;
// 	floatNum = std::stof(literal.c_str());
// 	std::cout << "floatNum: " << static_cast<float>(floatNum) << std::endl;
// 	doubleNum = std::stod(literal.c_str());
// 	std::cout << "doubleNum: " << static_cast<double>(doubleNum) << std::endl;

// }


/**========================================================================
 *                           ISCHAR
 *? I decided to check both forms (with and without the <'> character) 
 *========================================================================**/
bool ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

/**========================================================================
 *                           ISINT
 *========================================================================**/
bool ScalarConverter::isInt(const std::string &str)
{
	std::istringstream iss(str);
	int intValue;
	return !(iss >> intValue).fail() && iss.eof();
}

/**========================================================================
 *                           ISFLOAT
 *? substring created to check validit of float before suffix 'f'
 *! missing digits before or after the point is considered valid input
 *! ex: 42.f and .42f are valid floats
 *========================================================================**/
bool ScalarConverter::isFloat(const std::string &str)
{
	if (str[str.length() - 1] != 'f')
		return false;
	std::string numberPart = str.substr(0, str.size() - 1);
	std::istringstream iss(numberPart);
	float floatValue;
	iss >> floatValue;
	return !iss.fail() && iss.eof() && (numberPart.find('.') != std::string::npos);
}

/**========================================================================
 *                           ISDOUBLE
 *! missing digits beofre or after the point is considered valid input
 *! ex: 42. and .42 are valid doubles
 *========================================================================**/
bool ScalarConverter::isDouble(const std::string &str)
{
	std::istringstream iss(str);
	double doubleValue;
	return !(iss >> doubleValue).fail() && iss.eof() && (str.find('.') != std::string::npos);
}