#include "BitcoinExchange.hpp"

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
BitcoinExchange::BitcoinExchange() 
{
}

BitcoinExchange::~BitcoinExchange()
{
}

/**========================================================================
 *                           GETTER
 *========================================================================**/
std::map<std::string, double>& BitcoinExchange::get_bitcoinRateByDate()
{
	return (BitcoinExchange::_bitcoinRateByDate);
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void BitcoinExchange::extractDataFromFile(std::map<std::string, double>* map, std::string fileName)
{
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

int	BitcoinExchange::handleLine(std::pair<std::string, double>& newPair)
{
	if (newPair.first.empty())
		return(std:: cout << "Error: bad input => " << newPair.second << std::endl, 0);
	if (newPair.second < 0)
		throw std::runtime_error("Error: not a positive number.") ;;
	if (newPair.second > 1000)
		throw std::runtime_error("Error: too large a number.") ;;
	if (!isValidDate(newPair.first) && trim(newPair.first) != "date")
		return (std:: cout << "Error: bad input => " << newPair.first << std::endl, 0);
	std::map<std::string, double>::reverse_iterator i = _bitcoinRateByDate.rbegin();
	while(i++ != _bitcoinRateByDate.rend())
		if (i->first <=  newPair.first)
			return (std::cout << newPair.first << " => "  << newPair.second << " = "
					<< i->second * newPair.second << std::endl, 0);
	return (std::cout << trim(newPair.first) << " <=> " << newPair.second << std::endl, 0);
}

/**========================================================================
 *                           UTILS
 *========================================================================**/
void BitcoinExchange::openFile(std::ifstream& inputFile, std::string fileName)
{
	inputFile.open(fileName.c_str());
	if (!inputFile)
		throw std::logic_error( "\"" + fileName + "\" : couldn't open file");
}

/**========================================================================
 *                           CHECK DATE VALIDITY
 *========================================================================**/
bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (!(date.size() == 10 &&
		date[4] == '-' && date[7] == '-' &&
		std::isdigit(date[0]) && std::isdigit(date[1]) &&
		std::isdigit(date[2]) && std::isdigit(date[3]) &&
		std::isdigit(date[5]) && std::isdigit(date[6]) &&
		std::isdigit(date[8]) && std::isdigit(date[9]))) {
		return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**========================================================================
 *                           TRIM FUNCS
 *========================================================================**/
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
