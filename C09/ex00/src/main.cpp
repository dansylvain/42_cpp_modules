#include "BitcoinExchange.hpp"
#include "main.hpp"
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

typedef BitcoinExchange BE;

int main(int argc, char **argv)
{
	if (argc != 2)
		return (print("Error: wrong arg number"), 0);
	BE::extractDataFromCsvFile(&BE::get_bitcoinRateByDate(), "data.csv");
	// BE::displayMapContent();

	BE::extractDataFromCsvFile(NULL, argv[1]);

	return (0);
	(void)argv;
}