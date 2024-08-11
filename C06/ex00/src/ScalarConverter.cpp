#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		char c = literal[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}
	
	char* end;
	double value = strtod(literal.c_str(), &end);
	if (*end != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()
	&& isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}
