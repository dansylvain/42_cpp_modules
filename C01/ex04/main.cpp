#include <iostream>
#include <fstream>


int main( int argc, char **argv )
{
	std::string line;
	std::string srcFile;
	std::string destFile;

	srcFile = argv[1];
	destFile = srcFile + ".replace";
	// arg number check
	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}

	// test1
	std::cout << argv[1] << std::endl;
	std::cout << destFile << std::endl;


	// open input file stream + check
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cout << "Error: file not found" << std::endl;
		return (2);
	}

	// open output file stream + check
	std::ofstream outputFile(destFile.c_str());
	if (!outputFile)
	{
		std::cout << "could not create output file" << std::endl;
		return (3);
	}

	while (std::getline(inputFile, line))
	{
		outputFile << line << std::endl;
	}

	// close input file stream
	inputFile.close();

	return (0);
	(void)argc;
}