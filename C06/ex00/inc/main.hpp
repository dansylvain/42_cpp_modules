#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iomanip>
#include <cmath>

enum literalType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	UNKNOWN
};

void	print(std::string str);
void	printB(std::string str);
void	pause();