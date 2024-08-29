#include "BitcoinExchange.hpp"
#include "main.hpp"
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

typedef BitcoinExchange BE;

int main(int argc, char **argv)
{
	if (argc != 2)
		return (print("Error: wrong arg number"), 0);
	BE::extractDataFromCsvFile(&BE::get_bitcoinRateByDate(), "data.csv");
	BE::displayMapContent();


	std::ifstream inputFile;
	BE::openFile(inputFile, "input.txt");

	std::string line;
	while (std::getline(inputFile, line))
	{
		double bitcoinRate;
		std::string::size_type pos = line.find('|');
		std::string date = line.substr(0, pos);
		std::string bitcoinRateStr = line.substr(pos + 1);
		std::stringstream ss(bitcoinRateStr);
		ss >> bitcoinRate;
		std::cout << date << " <=> " << bitcoinRate << std::endl;
	}

	return (0);
	(void)argv;
}