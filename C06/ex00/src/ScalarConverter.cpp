#include "ScalarConverter.hpp"
#include <sstream>

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

const ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (this != &rhs)
	;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

/**========================================================================
 *                           ISTYPE METHODS
//? ISFLOAT && ISDOUBLE
//? substring created to check validity of float before suffix 'f'
//! missing digits before or after the point is considered valid input
//! ex: 42.f and .42f are valid floats
*========================================================================**/
bool ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string &str)
{
	std::istringstream iss(str);
	int intValue;
	return !(iss >> intValue).fail() && iss.eof();
}

bool ScalarConverter::isFloat(const std::string &str)
{
	if (str[str.length() - 1] != 'f' || str[0] == '.' || str[str.length() - 2] == '.')
		return false;
	std::string numberPart = str.substr(0, str.size() - 1);
	std::istringstream iss(numberPart);
	float floatValue;
	iss >> floatValue;
	return !iss.fail() && iss.eof() && (numberPart.find('.') != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	if (str[0] == '.' || str[str.length() - 1] == '.')
		return (0);
	std::istringstream iss(str);
	double doubleValue;
	return !(iss >> doubleValue).fail() && iss.eof() && (str.find('.') != std::string::npos);
}


/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/
literalType ScalarConverter::getType(std::string str)
{
	literalType type;

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

std::string ScalarConverter::literalTypeToString(literalType type)
{
    switch(type)
    {
        case CHAR: return "Char";
        case INT: return "Int";
        case FLOAT: return "Float";
        case DOUBLE: return "Double";
        case PSEUDOLITERAL: return "Pseudoliteral";
        default: return "Unknown";
    }
}



/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/
void ScalarConverter::convert(const std::string& str)
{
	literalType type = getType(str);
	std::cout << str << ": " << literalTypeToString(type) << std::endl;
}