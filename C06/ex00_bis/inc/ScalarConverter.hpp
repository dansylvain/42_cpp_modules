#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	public:
		static bool	isChar(const std::string &str);
		static bool	isInt(const std::string &str);
		static bool	isFloat(const std::string &str);
		static bool	isDouble(const std::string &str);

		static void convert(const std::string &literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();
};

#endif