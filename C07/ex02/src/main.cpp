#include <iostream>
#include "Array.hpp"

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

int main()
{
	printB("Construction with no parameter: Creates an empty array:");
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	
	printB("\nConstruction with an unsigned int n as a parameter: Creates an array of n elements initialized by default:");
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	printB("\nafter putting in some values:");
	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = static_cast<int>(i * 10);
	
	std::cout << "Integer array contents:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	printB("");
	std::cout << std::endl;
	try
	{
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
