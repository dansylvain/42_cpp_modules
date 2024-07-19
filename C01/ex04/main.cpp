#include <iostream>
#include <fstream>


int main( int argc, char **argv )
{
	std::string line;

	// arg number check
	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}

	// test1
	std::cout << argv[1] << std::endl;


	// open input file stream + check
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cout << "Error: file not found" << std::endl;
		return (2);
	}

	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
	}

	// close input file stream
	inputFile.close();

	return (0);
	(void)argc;
}