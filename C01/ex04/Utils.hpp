#include <iostream>
#include <fstream>

class Utils {
	public:
		static	std::string replaceAllOccurrences(const std::string& str, const std::string& s1, const std::string& s2);
		static	int ArgNumberWrong(int argc);
		static	void initVars(std::string& destFile, std::string& s1, std::string& s2, char *argv[]);
};