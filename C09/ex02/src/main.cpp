#include "main.hpp"
#include <PmergeMe.hpp>
	// parsing
	
	// merge-insert sorting algorithm (Ford-Johnson algorithm)
	
	// use containers std::vector and std::deque

	// tests to be made with at least 3000 different integers

	/* EXEMPLE OUTPUT:
	$> ./PmergeMe 3 5 9 7 4
	Before: 3 5 9 7 4
	After:
	3 4 5 7 9
	Time to process a range of 5 elements with std::[..] : 0.00031 us
	Time to process a range of 5 elements with std::[..] : 0.00014 us
	*/

	// The management of errors related to duplicates is left to your discretion. => ???

int *convertInput(int argc, char** argv, int *intCount)
{

}

void	cleanRessources(int *input)
{
	
}


int main(int argc, char **argv)
{
	int intCount;
	PmergeMe PmergeMe;
	// 1: associate values by pairs + set odd/even boolean
	int *input = convertInput(argc, argv, &intCount);
	// 2: input validation (negativ numbers, non ints)
	PmergeMe.validateInput(input);
	// 3: create Jacobstahl suite of index
	PmergeMe.createJacobstahlSequence(intCount);
	// 4: pre-sort pairs (lower/higher value)
	PmergeMe.createFirstSortedPairing(input, PmergeMe._vector);
	// 5: sort pairs (by higher value, <= 20 values => insert sort / >20 values => merge sort)
	PmergeMe.sortPairsByMainChainHighestValue(PmergeMe._vector);
	// 6: insert values through binary search according to Jacobstahl suite
	PmergeMe.insertPendantValuesThroughBinarySearch(PmergeMe._vector);
	// 7: IF ODD: insert last value
	PmergeMe.insertStraggler(PmergeMe._vector, input[intCount]);
	PmergeMe.displayResults(PmergeMe._vector);
	cleanRessources(input);
	print("Welcome to the jungle");
	return(0);
}