#include "main.hpp"
#include <PmergeMe.hpp>
	
	// tests to be made with at least 3000 different integers

	/* EXEMPLE OUTPUT:
	$> ./PmergeMe 3 5 9 7 4
	Before: 3 5 9 7 4
	After:
	3 4 5 7 9
	Time to process a range of 5 elements with std::[..] : 0.00031 us
	Time to process a range of 5 elements with std::[..] : 0.00014 us
	*/

int *convertInput(int argc, char** argv, int *intCount)
{
	(void)argv;
	(void)intCount;
	(void)argc;
	return intCount;

}

void	cleanRessources(int *input)
{
	(void)input;
}


int main(int argc, char **argv)
{
	int intCount;
	PmergeMe PmergeMe;
	int *input = convertInput(argc, argv, &intCount);

	//! COMMON FUNCS
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
	
	cleanRessources(input);
	print("Welcome to the jungle");
	return(0);
}