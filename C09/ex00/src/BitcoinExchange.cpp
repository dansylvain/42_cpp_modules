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

bool BitcoinExchange::isValidDateFormat(const std::string& date)
{
	return (date.size() == 10 &&
		date[4] == '-' && date[7] == '-' &&
		std::isdigit(date[0]) && std::isdigit(date[1])
		&& std::isdigit(date[2]) && std::isdigit(date[3])
		&& std::isdigit(date[5]) && std::isdigit(date[6])
		&&std::isdigit(date[8]) && std::isdigit(date[9]));
}

void	BitcoinExchange::handleLine(std::pair<std::string, double>& newPair)
{
	try
	{
		if (!newPair.second && trim(newPair.first) != "date")
		{
			std:: cout << "Error: bad input => " << newPair.first << std::endl;
			return;
		}
		if (newPair.first.empty())
		{
			std:: cout << "Error: bad input => " << newPair.second << std::endl;
			return;
		}
		if (newPair.second < 0)
			throw std::runtime_error("Error: not a positive number.") ;;
		if (newPair.second > 1000)
			throw std::runtime_error("Error: too large a number.") ;;
		if (!isValidDateFormat(newPair.first) && trim(newPair.first) != "date")
			throw std::runtime_error("Error: invalid input.") ;;
		
		std::map<std::string, double>::reverse_iterator i = _bitcoinRateByDate.rbegin();
		while(i != _bitcoinRateByDate.rend())
		{
			if (i->first <=  newPair.first)
			{
				std::cout << i->first << " | " << i->second * newPair.second << std::endl;
				return ;
			}
			i++;
		}

		std::cout << trim(newPair.first) << " <=> " << newPair.second << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
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
		std::pair<std::string, double> newPair;
		char c;

		if (map)
			c = ',';
		else
			c = '|';
		std::string::size_type pos = line.find(c);
		newPair.first = trim(line.substr(0, pos));
		std::string bitcoinRateStr;
		if (pos != std::string::npos)
			bitcoinRateStr = line.substr(pos + 1);
		std::stringstream ss(bitcoinRateStr);
		ss >> newPair.second;
		if (map)
			(*map).insert(newPair);
		else
			handleLine(newPair);
	}
}


std::string BitcoinExchange::ltrim(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isspace(*it)) {
		++it;
	}
	return std::string(it, s.end());
}

std::string BitcoinExchange::rtrim(const std::string& s)
{
	std::string::const_reverse_iterator rit = s.rbegin();
	while (rit != s.rend() && std::isspace(*rit)) {
		++rit;
	}
	return std::string(s.begin(), rit.base());
}

std::string BitcoinExchange::trim(const std::string& s)
{
	return ltrim(rtrim(s));
}