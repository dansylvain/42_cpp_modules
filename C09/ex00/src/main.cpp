#include "main.hpp"
#include "BitcoinExchange.hpp"

/**========================================================================
 *!                           ALGORITHM SORT TO BE ADDED?
 *========================================================================**/
int main(int argc, char **argv)
{
	BitcoinExchange obj;
	if (argc == 1)
		return (print("Error: couldn't open file"), 0);
	obj.extractDataFromFile(&obj.get_bitcoinRateByDate(), "data.csv");
	obj.extractDataFromFile(NULL, argv[1]);
	return (0);
}