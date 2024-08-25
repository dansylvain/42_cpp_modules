#pragma once
#include <iostream>
#include <string>
#include "main.hpp"
#include "LiteralValue.hpp"



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
		static bool	isPseudoLiteral(const std::string &str);


		// conversion methods

		static int convertToInt(const std::string& str);
		static float convertToFloat(const std::string& str);
		static double convertToDouble(const std::string& str);
		static char convertToChar(const std::string& str);

		static void	printPseudoLiterals(std::string str);
		static literalType getType(std::string str);
		static std::string literalTypeToString(literalType type);
		static void	convert(const std::string& str);
};

template <typename T>
void printConversions(T value);

template <>
void printConversions<char>(char value);

#include "Scalarconverter.tpp"