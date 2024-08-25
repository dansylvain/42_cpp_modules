#pragma once
#include <iostream>
#include <string>
#include "main.hpp"
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		// coplien
		ScalarConverter(const ScalarConverter& other);
		const ScalarConverter& operator=(const ScalarConverter& rhs);
		ScalarConverter();
		~ScalarConverter();

		// isType methods
		bool	isChar(const std::string &str);
		bool	isInt(const std::string &str);
		bool	isFloat(const std::string &str);
		bool	isDouble(const std::string &str);
		bool	isPseudoLiteral(const std::string &str);
		
		// conversion methods
		int convertToInt(const std::string& str);
		float convertToFloat(const std::string& str);
		double convertToDouble(const std::string& str);
		char convertToChar(const std::string& str);

		// other methods
		void	printPseudoLiterals(std::string str);
		literalType getType(std::string str);
		std::string literalTypeToString(literalType type);
	public:
		// single static method
		static void	convert(const std::string& str);
};

template <typename T>
void printConversions(T value);

template <>
void printConversions<char>(char value);

#include "Scalarconverter.tpp"