#include "Utils.hpp"



int main( int argc, char **argv )
{
	std::string line;
	std::string destFile;
	std::string s1;
	std::string s2;
	std::ifstream inputFile;
	std::ofstream outputFile;

	if(Utils::ArgNumberWrong(argc))
		return (1);
	Utils::initVars(destFile, s1, s2, argv);
	if (Utils::openStreams(inputFile, outputFile, argv[1], destFile))
		return (2);
	
	// replace s1 with s2
	std::string newline;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
		newline = Utils::replaceAllOccurrences(line, s1, s2);
		std::cout << newline << std::endl;
		outputFile << newline << std::endl;
	}



	// close input file stream
	inputFile.close();

	
	return (0);
	(void)argc;
}