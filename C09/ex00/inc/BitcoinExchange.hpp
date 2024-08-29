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
		static void	extractDataFromCsvFile();
		static std::map<std::string, double>& get_bitcoinRateByDate();

};