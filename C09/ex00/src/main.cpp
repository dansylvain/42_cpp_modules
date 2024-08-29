#include "main.hpp"
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

int main(int argc, char **argv)
{
	std::map<std::string, double> bitcoinRateByDate;
	if (argc != 2)
	return (print("Error: wrong arg number"), 0);

	std::cout << "Welcome to the jugle" << std::endl;
	std::ifstream inputFile;

	inputFile.open("data.csv");
	if (!inputFile)
		return (std::cout << "File error" << std::endl, 2);
	
	std::string line;
	while (std::getline(inputFile, line))
	{
		double bitcoinRate;
		std::string::size_type pos = line.find(',');
		std::string date = line.substr(0, pos);
		std::string bitcoinRateStr = line.substr(pos + 1);
		std::stringstream ss(bitcoinRateStr);
		ss >> bitcoinRate;
		std::pair<std::string, double> newPair(date, bitcoinRate);
		bitcoinRateByDate.insert(newPair);
	}
	std::map<std::string, double>::const_iterator it;
	for (it = bitcoinRateByDate.begin(); it != bitcoinRateByDate.end(); it++)
		std::cout << it->first << " <=> " << it->second << std::endl;

	return (0);
	(void)argv;
}