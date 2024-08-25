#pragma once
#include <iostream>
#include <string>
#include "main.hpp"

class ScalarConverter
{
	private:

		// coplien
		ScalarConverter(const ScalarConverter& other);
		virtual const ScalarConverter& operator=(const ScalarConverter& rhs) = 0;
	public:
		// coplien
		ScalarConverter();
		~ScalarConverter();

		// isType methods
		static bool	isChar(const std::string &str);
		static bool	isInt(const std::string &str);
		static bool	isFloat(const std::string &str);
		static bool	isDouble(const std::string &str);

		// other methods
		static void	convert(const std::string& str);
		static literalType getType(std::string str);
		static std::string literalTypeToString(literalType type);

};