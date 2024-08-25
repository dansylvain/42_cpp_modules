#include "ScalarConverter.hpp"

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

void	ScalarConverter::convert(const std::string& str)
{
	std::cout << "convert: " << str << std::endl;
}
