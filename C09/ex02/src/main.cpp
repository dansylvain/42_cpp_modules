#include "main.hpp"
#include <PmergeMe.hpp>
#include <sstream>

	// tests to be made with at least 3000 different integers

	/* EXEMPLE OUTPUT:
	$> ./PmergeMe 3 5 9 7 4
	Before: 3 5 9 7 4
	After:
	3 4 5 7 9
	Time to process a range of 5 elements with std::[..] : 0.00031 us
	Time to process a range of 5 elements with std::[..] : 0.00014 us
	*/

int stringToInt(const std::string& str)
{
	int nbr;

	std::stringstream ss(str);
	ss >> nbr;
	return (nbr);
}

bool isInteger(const std::string& str)
{
	std::istringstream iss(str);
	int number;
	char c;
	if (!(iss >> number) || (iss >> c))
		return false;
	return true;
}

std::vector<int>& convertInput(int argc, char** argv, std::vector<int>& input, int *intCount)
{
	
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		while (iss >> token)
		{
			std::istringstream tokenStream(token);
			int number;
			if (tokenStream >> number)
			{
				input.push_back(number);
				(*intCount)++;
			}
			else
			{
				std::cout << "hey Houston, we have a problem" << std::endl;
			}
		}
	}
	return input;
}

void	cleanRessources(int *input)
{
	(void)input;
}


int main(int argc, char **argv)
{
	int intCount = 0;
	PmergeMe PmergeMe;
	std::vector<int> input;

	//! COMMON FUNCS
	input = convertInput(argc, argv, input, &intCount);

	for (int i = 0; i < intCount; i++)
	{
		std::cout << input[i] << std::flush;
		if (i != intCount - 1)
			std::cout << ", " << std::flush;
		else
			std::cout << std::endl;
	}





	PmergeMe.validateInput(input);
	PmergeMe.createJacobstahlSequence(intCount);

	//! VECTOR FUNCS
	PmergeMe.createFirstSortedPairing(input, PmergeMe._vector);
	PmergeMe.sortPairsByMainChainHighestValue(PmergeMe._vector);
	PmergeMe.insertPendantValuesThroughBinarySearch(PmergeMe._vector);
	PmergeMe.insertStraggler(PmergeMe._vector, input[intCount]);
	PmergeMe.displayResults(PmergeMe._vector);

	//! DEQUE FUNCS
	PmergeMe.createFirstSortedPairing(input, PmergeMe._deque);
	PmergeMe.sortPairsByMainChainHighestValue(PmergeMe._deque);
	PmergeMe.insertPendantValuesThroughBinarySearch(PmergeMe._deque);
	PmergeMe.insertStraggler(PmergeMe._deque, input[intCount]);
	PmergeMe.displayResults(PmergeMe._deque);
	
	// cleanRessources(input);
	print("Welcome to the jungle");
	return(0);
}