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

bool convertInput(int argc, char** argv, std::vector<int>* inputPtr, int *inputIntCount)
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
			(*inputIntCount)++;
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
	int inputIntCount = 0;
	PmergeMe PmergeMe;
	std::vector<int> input;
	std::vector<int>* inputPtr;
	inputPtr = & input;
	

	//! COMMON FUNCS
	if(!convertInput(argc, argv, inputPtr, &inputIntCount))
		return (print("Error: invalid input"), 1);
	PmergeMe.getInputVector(input);
	PmergeMe.generateJacobstahlSequence();
	
	
	printB("\nDisplay Input Tab:");
	displayInputTab(inputIntCount, input);

	printB("\nDisplay Tab upon creation:");
	PmergeMe.displayPairVector(PmergeMe._vector);

	printB("\nDisplay JacobsDingsdaBumsda Tab:");
	displayInputTab(PmergeMe._jacobstahlSequence.size(), PmergeMe._jacobstahlSequence);
	
	//! VECTOR FUNCS
	PmergeMe.createFirstSortedPairing(PmergeMe._vector);
	printB("\nDisplay Tab after initial sorting:");
	PmergeMe.displayPairVector(PmergeMe._vector);
	
	PmergeMe.sortPairsByMainChainHighestValue(PmergeMe._vector);
	printB("\nDisplay Tab after merge sorting:");
	PmergeMe.displayPairVector(PmergeMe._vector);
	
	PmergeMe.createFinalVector();
	PmergeMe.displayIntVector(PmergeMe._finalVector);

	PmergeMe.insertPendantValuesThroughBinarySearch(PmergeMe._vector);
	
	
	
	
	
	PmergeMe.insertStraggler(PmergeMe._vector);
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