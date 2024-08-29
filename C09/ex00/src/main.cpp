#include "main.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	return (print("Error: wrong arg number"), 0);

	std::cout << "Welcome to the jugle" << std::endl;
	std::ifstream inputFile;

	inputFile.open("data.csv");
	if (!inputFile)
		return (std::cout << "File error" << std::endl, 2);
	
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
	}
	return (0);
	(void)argv;
}