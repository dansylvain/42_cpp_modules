#include <iostream>
#include <fstream>

class Utils {
	public:
		static	std::string replaceAllOccurrences(const std::string& str, char *argv[]);
		static	int ArgNumberWrong(int argc);
		static	void initVars(std::string& destFile, char *argv[]);
		static	int openStreams(std::ifstream& inputFile, std::ofstream& outputFile, char *srcFile, std::string& destFile);

};