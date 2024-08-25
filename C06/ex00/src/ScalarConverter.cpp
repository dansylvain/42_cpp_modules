#include "ScalarConverter.hpp"

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
*========================================================================**/
bool ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
			|| (str.length() == 1 && isprint(str[0]));
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

bool	ScalarConverter::isPseudoLiteral(const std::string &str)
{
	return (str == "+inf" || str == "+inff" || str == "-inf"
	|| str == "-inff" || str == "nan" || str == "nanf");
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
	else if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf"
			|| str == "nan" || str == "nanf")
		type = PSEUDOLITERAL;
	else
		type = UNKNOWN;
	return (type);
}

std::string ScalarConverter::literalTypeToString(literalType type)
{
	switch(type)
	{
		case INT: return "Int";
		case CHAR: return "Char";
		case FLOAT: return "Float";
		case DOUBLE: return "Double";
		case PSEUDOLITERAL: return "Pseudoliteral";
		default: return "Unknown";
	}
}



/**========================================================================
 *                           CONVERT METHODS
 *========================================================================**/
int ScalarConverter::convertToInt(const std::string& str)
{
	int value = atoi(str.c_str());
	return static_cast<int>(value);
}

float ScalarConverter::convertToFloat(const std::string& str)
{
	float value = static_cast<float>(atof(str.c_str()));
	return static_cast<float>(value);
}

double ScalarConverter::convertToDouble(const std::string& str)
{
	double value = atof(str.c_str());
	return static_cast<double>(value);
}

char ScalarConverter::convertToChar(const std::string& str)
{
	char value;
	if (str.size() == 3)
		value = str[1];
	else
		value = str[0];
	return static_cast<char>(value);
}

/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/

void	ScalarConverter::printPseudoLiterals(std::string str)
{
	std::string floatStr = str;
	std::string doubleStr = str;

	if (str == "nanf" || str == "+inff" || str == "-inff")
		str = str.substr(0, str.size() - 1);


	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	char c;
	int i;
	double d;
	float f;
	ScalarConverter sc;
	literalType type = sc.getType(str);
	try
	{
		switch(type)
		{
			case CHAR:
				c = sc.convertToChar(str);
				printConversions(c);
				break;
			case INT:
				i = sc.convertToInt(str);
				printConversions(i);
				break;
			case DOUBLE:
				d = sc.convertToDouble(str);
				printConversions(d);
				break;
			case FLOAT:
				f = sc.convertToFloat(str);
				printConversions(f);
				break;
			case PSEUDOLITERAL:
				sc.printPseudoLiterals(str);
				break;
			default :
				throw std::runtime_error("Conversion impossible.");
				return;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <>
void printConversions<char>(char value)
{
	std::cout << "char: '" << value << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}
