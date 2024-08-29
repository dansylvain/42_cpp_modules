#include "BitcoinExchange.hpp"
#include <exception>

std::map<std::string, double> BitcoinExchange::_bitcoinRateByDate;

std::map<std::string, double>& BitcoinExchange::get_bitcoinRateByDate()
{
	return (BitcoinExchange::_bitcoinRateByDate);
}

void BitcoinExchange::extractDataFromCsvFile()
{
	std::ifstream inputFile;

	inputFile.open("data.csv");
	if (!inputFile)
		throw std::logic_error("File error");
	
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
		BitcoinExchange::get_bitcoinRateByDate().insert(newPair);
	}
	std::map<std::string, double>::const_iterator it;
	for (it = BitcoinExchange::get_bitcoinRateByDate().begin(); it != get_bitcoinRateByDate().end(); it++)
		std::cout << it->first << " <=> " << it->second << std::endl;
}
