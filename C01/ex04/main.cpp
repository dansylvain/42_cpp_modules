#include "Utils.hpp"



int main( int argc, char **argv )
{
	std::string line;
	std::string destFile;
	std::string s1;
	std::string s2;
	std::ifstream inputFile;
	std::ofstream outputFile;
	// arg number check
	if(Utils::ArgNumberWrong(argc))
		return (1);
	
	//initialize variables
	Utils::initVars(destFile, s1, s2, argv);


	// open input file stream + check
	inputFile.open(argv[1]);
	if (!inputFile)
	{
		std::cout << "Error: file not found" << std::endl;
		return (2);
	}

	// open output file stream + check
	outputFile.open(destFile.c_str());
	if (!outputFile)
	{
		std::cout << "could not create output file" << std::endl;
		return (3);
	}
	
	std::string newline;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
		newline = Utils::replaceAllOccurrences(line, s1, s2);
		std::cout << newline << std::endl;
		outputFile << newline << std::endl;
	}


	// replace s1 with s2

	// close input file stream
	inputFile.close();

	
	return (0);
	(void)argc;
}