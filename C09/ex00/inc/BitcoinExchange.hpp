#pragma once
#include "main.hpp"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _bitcoinRateByDate;

		//coplien (not used)
		BitcoinExchange(const BitcoinExchange&);
		const BitcoinExchange& operator=(const BitcoinExchange&);
		
		// utils
		void	openFile(std::ifstream&, std::string fileName);
		int		handleLine(std::pair<std::string, double>& newPair);
		
		// check date
		bool isLeapYear(int year);
		bool isValidDate(const std::string& date);
		
		// trim funcs
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
		
	public:
		// coplien
		BitcoinExchange();
		~BitcoinExchange();

		// Action methods
		void	extractDataFromFile(std::map<std::string, double>* map, std::string file);
		std::map<std::string, double>& get_bitcoinRateByDate();
};