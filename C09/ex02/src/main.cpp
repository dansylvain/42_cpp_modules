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

bool convertInput(int argc, char** argv, std::vector<int>* inputPtr, int *intCount)
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
			inputPtr->push_back(number);
			(*intCount)++;
		}
	}
	return true;
}

void	cleanRessources(int *input)
{
	(void)input;
}

void	displayInputTab(int intCount, std::vector<int>& input)
{
	for (int i = 0; i < intCount; i++)
	{
		std::cout << input[i] << std::flush;
		if (i != intCount - 1)
			std::cout << ", " << std::flush;
		else
			std::cout << std::endl;
	}
}


int main(int argc, char **argv)
{
	int intCount = 0;
	PmergeMe PmergeMe;
	std::vector<int> input;
	std::vector<int>* inputPtr;
	inputPtr = & input;
	

	//! COMMON FUNCS
	if(!convertInput(argc, argv, inputPtr, &intCount))
		return (print("Error: invalid input"), 1);
	printB("\nDisplay Input Tab:");
	displayInputTab(intCount, input);
	PmergeMe.getInputVector(input);
	
	PmergeMe.generateJacobstahlSequence(intCount);
	printB("\nDisplay JacobsDingsdaBumsda Tab:");
	displayInputTab(PmergeMe._jacobstahlSequence.size(), PmergeMe._jacobstahlSequence);
	






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
	print("");
	return(0);
}