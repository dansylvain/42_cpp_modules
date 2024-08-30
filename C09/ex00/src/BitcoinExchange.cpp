#include "BitcoinExchange.hpp"
#include <exception>
#include <cstdlib>


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

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	// Vérification du format général
	if (!(date.size() == 10 &&
		date[4] == '-' && date[7] == '-' &&
		std::isdigit(date[0]) && std::isdigit(date[1]) &&
		std::isdigit(date[2]) && std::isdigit(date[3]) &&
		std::isdigit(date[5]) && std::isdigit(date[6]) &&
		std::isdigit(date[8]) && std::isdigit(date[9]))) {
		return false;
	}

	// Extraction de l'année, du mois et du jour
	int year, month, day;
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());

	// Vérification de l'année, du mois et du jour
	if (month < 1 || month > 12)
		return false;

	// Jours max en fonction du mois
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Ajustement pour février si l'année est bissextile
	if (isLeapYear(year)) {
		daysInMonth[1] = 29;
	}

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

void	BitcoinExchange::handleLine(std::pair<std::string, double>& newPair)
{
	// if (!newPair.second && trim(newPair.first) != "date")
	// {
	// 	std:: cout << "Error: bad input => " << newPair.first << std::endl;
	// 	return;
	// }
	if (newPair.first.empty())
	{
		std:: cout << "Error: bad input => " << newPair.second << std::endl;
		return;
	}
	if (newPair.second < 0)
		throw std::runtime_error("Error: not a positive number.") ;;
	if (newPair.second > 1000)
		throw std::runtime_error("Error: too large a number.") ;;
	if (!isValidDate(newPair.first) && trim(newPair.first) != "date")
	{
		std:: cout << "Error: bad input => " << newPair.first << std::endl;
		return ;
	}
	
	std::map<std::string, double>::reverse_iterator i = _bitcoinRateByDate.rbegin();
	while(i != _bitcoinRateByDate.rend())
	{
		if (i->first <=  newPair.first)
		{
			std::cout << newPair.first << " => "  << newPair.second << " = " << i->second * newPair.second << std::endl;
			return ;
		}
		i++;
	}
	std::cout << trim(newPair.first) << " <=> " << newPair.second << std::endl;
}

void BitcoinExchange::extractDataFromFile(std::map<std::string, double>* map, std::string fileName)
{
	// open file
	std::ifstream inputFile;
	try
		{BitcoinExchange::openFile(inputFile, fileName);}
	catch(const std::exception& e)
		{std::cerr << e.what() << '\n';}
	
	std::string line;
	int i = 0;
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
		else if (i++ != 0)	
			try
				{handleLine(newPair);}
			catch(const std::exception& e)
				{std::cerr << e.what() << '\n';}
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