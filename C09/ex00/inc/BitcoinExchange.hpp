#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

class BitcoinExchange
{
	private:
		static std::map<std::string, double> _bitcoinRateByDate;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		const BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();
	public:
		static void	extractDataFromFile(std::map<std::string, double>* map, std::string file);
		static std::map<std::string, double>& get_bitcoinRateByDate();
		static void displayMapContent();
		static void openFile(std::ifstream&, std::string fileName);
		static void	handleLine(std::pair<std::string, double>& newPair);
		static void	checkValidity(std::pair<std::string, double>& newPair);
		static bool isValidDateFormat(const std::string& date);
		static bool isLeapYear(int year);
		static bool isValidDate(const std::string& date);

		static std::string ltrim(const std::string& s);
		static std::string rtrim(const std::string& s);
		static std::string trim(const std::string& s);
};