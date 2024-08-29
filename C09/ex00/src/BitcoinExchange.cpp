#include "BitcoinExchange.hpp"
#include <exception>

std::map<std::string, double> BitcoinExchange::_bitcoinRateByDate;

std::map<std::string, double>& BitcoinExchange::get_bitcoinRateByDate()
{
	return (BitcoinExchange::_bitcoinRateByDate);
}

void BitcoinExchange::displayMapContent()
{
	std::map<std::string, double>::const_iterator it;
	for (it = BitcoinExchange::get_bitcoinRateByDate().begin(); it != get_bitcoinRateByDate().end(); it++)
		std::cout << it->first << " <=> " << it->second << std::endl;
}

void BitcoinExchange::openFile(std::ifstream& inputFile, std::string fileName)
{
	inputFile.open(fileName.c_str());
	if (!inputFile)
		throw std::logic_error( "\"" + fileName + "\" : couldn't open file");
}

void BitcoinExchange::extractDataFromCsvFile(std::map<std::string, double>* map, std::string fileName)
{
	std::ifstream inputFile;
	try
	{
		BitcoinExchange::openFile(inputFile, fileName);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::string line;
	while (std::getline(inputFile, line))
	{
		double bitcoinRate;
		std::string::size_type pos = line.find(',');
		std::string date = line.substr(0, pos);
		std::string bitcoinRateStr = line.substr(pos + 1);
		std::stringstream ss(bitcoinRateStr);
		ss >> bitcoinRate;
		if (map)
		{
			std::pair<std::string, double> newPair(date, bitcoinRate);
			(*map).insert(newPair);
		}
		else
			std::cout << date << " <=> " << bitcoinRate << std::endl;
	}
}
