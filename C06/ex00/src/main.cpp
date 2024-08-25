#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "usage: ./convert <string>" << std::endl, 0);
	ScalarConverter::convert(argv[1]);
    return (0);
}