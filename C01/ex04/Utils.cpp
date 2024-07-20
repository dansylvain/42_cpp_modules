#include "Utils.hpp"

int		Utils::ArgNumberWrong(int argc)
{
	if (argc != 4)
		return (std::cout << "Error: wrong number of arguments" << std::endl, 1);
	return (0);
}

void	Utils::initVars(std::string& destFile, std::string& s1, std::string& s2, char *argv[])
{
	std::string srcFile;

	srcFile = argv[1];
	destFile = srcFile + ".replace";
	s1 = argv[2];
	s2 = argv[3];
}


















std::string Utils::replaceAllOccurrences(const std::string& str, const std::string& s1, const std::string& s2) {
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