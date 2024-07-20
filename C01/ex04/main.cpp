#include "Utils.hpp"



int main( int argc, char **argv )
{
	
	std::string destFile;
	std::ifstream inputFile;
	std::ofstream outputFile;

	if(Utils::ArgNumberWrong(argc))
		return (1);
	Utils::initVars(destFile, argv);
	if (Utils::openStreams(inputFile, outputFile, argv[1], destFile))
		return (2);
	
	// replace s1 with s2
	std::string newline;
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
		newline = Utils::replaceAllOccurrences(line, argv);
		std::cout << newline << std::endl;
		outputFile << newline << std::endl;
	}



	// close input file stream
	inputFile.close();

	
	return (0);
	(void)argc;
}