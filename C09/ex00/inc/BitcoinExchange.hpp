#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include "main.hpp"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _bitcoinRateByDate;

		BitcoinExchange(const BitcoinExchange&);
		const BitcoinExchange& operator=(const BitcoinExchange&);
		void displayMapContent();
		void openFile(std::ifstream&, std::string fileName);
		void	handleLine(std::pair<std::string, double>& newPair);
		void	checkValidity(std::pair<std::string, double>& newPair);
		bool isValidDateFormat(const std::string& date);
		bool isLeapYear(int year);
		bool isValidDate(const std::string& date);
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
	public:
		void	extractDataFromFile(std::map<std::string, double>* map, std::string file);
		std::map<std::string, double>& get_bitcoinRateByDate();
		BitcoinExchange()  {};
		~BitcoinExchange() {};
};