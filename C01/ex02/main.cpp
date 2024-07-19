#include <iostream>

int main(void)
{
	std::string string;
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	string = "HI THIS IS BRAIN";
	std::cout << "The memory address of the string variable: "	<< &string << std::endl;
	std::cout << "The memory address held by stringPTR:      " 	<< stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:      " 	<< &stringREF << std::endl;
	std::cout << "The value of the string variable:          " 	<< string << std::endl;
	std::cout << "The string value using the stringREF:      " 	<< *stringPTR << std::endl;
	std::cout << "The string value using the stringPTR:      " 	<< stringREF << std::endl;

	return (0);
}