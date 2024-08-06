#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>

class Utils {
	private:
	static	std::string	errMssg;
	static	std::string	errMssg2;
	
	public:
	Utils();
	static	std::string replaceAllOccurrences(const std::string& str, char *argv[]);
	static	int ArgNumberWrong(int argc);
	static	void initVars(std::string& destFile, char *argv[]);
	static	int openStreamsFails(std::ifstream& inputFile, std::ofstream& outputFile, char *argv[]);
	static	void createNewFile(std::ifstream& inputFile, std::ofstream& outputFile, char *argv[]);
	static	void closeStreams(std::ifstream& inputFile, std::ofstream& outputFile);
};

#endif