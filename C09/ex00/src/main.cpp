#include "BitcoinExchange.hpp"
#include "main.hpp"
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (print("Error: wrong arg number"), 0);
	BitcoinExchange::extractDataFromCsvFile();
	BitcoinExchange::displayMapContent();
	return (0);


	(void)argv;
}