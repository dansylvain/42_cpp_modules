#include "BitcoinExchange.hpp"
#include "main.hpp"
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

int main(int argc, char **argv)
{
	static	std::map<std::string, double> bitcoinRateByDate;
	if (argc != 2)
	return (print("Error: wrong arg number"), 0);

	std::cout << "Welcome to the jugle" << std::endl;
	BitcoinExchange::extractDataFromCsvFile();
	return (0);
	(void)argv;
}