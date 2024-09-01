#include "main.hpp"
#include <PmergeMe.hpp>
#include <sstream>
#include <ctime>

clock_t startTimer()
{
    return clock();
}

double stopTimer(clock_t start)
{
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}


int stringToInt(const std::string& str)
{
	int nbr;

	std::stringstream ss(str);
	ss >> nbr;
	return (nbr);
}

bool isPositivInteger(const std::string& str)
{
	std::istringstream iss(str);
	int number;
	char c;
	if (!(iss >> number) || (iss >> c))
		return false;
	if (number < 0)
		return false;
	return true;
}

bool convertInput(int argc, char** argv, std::vector<int>* input)
{
	
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		while (iss >> token)
		{
			if (!isPositivInteger(token))
				return false;
			std::istringstream tokenStream(token);
			int number;
			tokenStream >> number;
			input->push_back(number);
		}
	}
	return true;
}



void	displayInputTab(int inputIntCount, std::vector<int>& input)
{
	for (int i = 0; i < inputIntCount; i++)
	{
		std::cout << input[i] << std::flush;
		if (i != inputIntCount - 1)
			std::cout << ", " << std::flush;
		else
			std::cout << std::endl;
	}
}

int main(int argc, char **argv)
{
	PmergeMe PmergeMe;
	std::vector<int> input;	

	if(!convertInput(argc, argv, &input))
		return (print("Error: invalid input"), 1);
	PmergeMe.vectorSort(input);	
	PmergeMe.displayResults(PmergeMe._vector);

	//! DEQUE FUNCS
	PmergeMe.createFirstSortedPairing(PmergeMe._deque);
	PmergeMe.sortPairsByMainChainHighestValue(PmergeMe._deque);
	PmergeMe.insertPendantValuesThroughBinarySearch(PmergeMe._deque);
	PmergeMe.insertStraggler(PmergeMe._deque);
	PmergeMe.displayResults(PmergeMe._deque);
	
	print("");
	return(0);
}