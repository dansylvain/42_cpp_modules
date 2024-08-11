#ifndef MAIN_HPP
#define MAIN_HPP

#include "Serializer.hpp"
#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
	int number;
	std::string text;

	Data(int num, const std::string& str) : number(num), text(str) {}
};

#endif