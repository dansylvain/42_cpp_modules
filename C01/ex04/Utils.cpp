#include "Utils.hpp"

int		Utils::ArgNumberWrong(int argc)
{
	if (argc != 4)
		return (std::cout << "Error: wrong number of arguments" << std::endl, 1);
	return (0);
}

void	Utils::initVars(std::string& destFile, char *argv[])
{
	std::string srcFile;

	srcFile = argv[1];
	destFile = srcFile + ".replace";

}

int	Utils::openStreams(std::ifstream& inputFile, std::ofstream& outputFile, char *srcFile, std::string& destFile)
{
	// open input file stream + check
	
	inputFile.open(srcFile);
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
	return (0);
}

















std::string Utils::replaceAllOccurrences(const std::string& str, char *argv[]) {
	std::string s1;
	std::string s2;

	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty()) {
		return str;
	}
	std::string result;
	size_t pos = 0;
	size_t prev_pos = 0;
	while ((pos = str.find(s1, prev_pos)) != std::string::npos) {
		result.append(str.substr(prev_pos, pos - prev_pos));
		result.append(s2);
		prev_pos = pos + s1.length();
	}

	result.append(str.substr(prev_pos));
	return result;
}