#include "PmergeMe.hpp"
#include "main.hpp"

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
PmergeMe::PmergeMe()
{
	print("PmergeMe instanciated");
}

PmergeMe::~PmergeMe()
{
	print("PmergeMe destroyed");
}

/**========================================================================
 *                           COMMON FUNCTIONS
 *========================================================================**/
void	PmergeMe::createJacobstahlSequence(const int& intCount)
{

	(void)intCount;
}




void	PmergeMe::generateJacobstahlSequence(const int& intCount)
{
	int j0 = 0;
	int j1 = 1;
	
	if (intCount < 1)
		return;
	_jacobstahlSequence.push_back(j1);
	while (true)
	{
		int nextJacobstahl = j1 + 2 * j0;
		if (nextJacobstahl > intCount)
			break;
		_jacobstahlSequence.push_back(nextJacobstahl);
		j0 = j1;
		j1 = nextJacobstahl;
	}
}

/**========================================================================
 *                           VECTOR
 *========================================================================**/
void	PmergeMe::getInputVector(std::vector<int>& input)
{
	_vector.clear();
	for (unsigned long i = 0; i < input.size(); i++)
		_vector.push_back(input[i]);
}

void	PmergeMe::createFirstSortedPairing(std::vector<int>  input, std::vector<int>& _vector)
{
	(void)input;
	(void)_vector;
}

void	PmergeMe::sortPairsByMainChainHighestValue(std::vector<int>& _vector)
{
	(void)_vector;

}

void	PmergeMe::insertPendantValuesThroughBinarySearch(std::vector<int>& _vector)
{
	(void)_vector;

}

void	PmergeMe::insertStraggler(std::vector<int>& _vector, const int& staggler)
{
	(void)_vector;
	(void)staggler;
}

void	PmergeMe::displayResults(std::vector<int>& _vector) const
{
	(void)_vector;

}

/**========================================================================
 *                           DEQUE
 *========================================================================**/
void	PmergeMe::getInputDeque(std::vector<int>& input)
{
	(void)input;
}

void	PmergeMe::createFirstSortedPairing(std::vector<int> input, std::deque<int>& _vector)
{
	(void)_vector;
	(void)input;
}

void	PmergeMe::sortPairsByMainChainHighestValue(std::deque<int>& _vector)
{
	(void)_vector;

}

void	PmergeMe::insertPendantValuesThroughBinarySearch(std::deque<int>& _vector)
{

	(void)_vector;
}

void	PmergeMe::insertStraggler(std::deque<int>& _vector, const int& staggler)
{
	(void)_vector;
	(void)staggler;
}

void	PmergeMe::displayResults(std::deque<int>& _vector) const
{
	(void)_vector;

}
