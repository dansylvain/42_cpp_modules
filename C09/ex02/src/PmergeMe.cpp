#include "PmergeMe.hpp"
#include "main.hpp"
#include <limits>

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
PmergeMe::PmergeMe() : _isOdd(false), _straggler(std::numeric_limits<double>::max())
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
	unsigned long i = 0;
	for (; i < input.size(); i++)
		_vector.push_back(input[i]);
	if (i % 2 != 0)
	{
		_isOdd = true;
		_straggler = input[i - 1];
	}
	std::cout << "value of i: " << i << ", " << _straggler << std::endl;
}

void PmergeMe::createFirstSortedPairing(std::vector<int>& inputVector)
{
	int tmp;

	for (unsigned long i = 1; i < inputVector.size(); i += 2)
	{
		if (inputVector[i - 1] > inputVector[i])
		{
			tmp = inputVector[i - 1];
			inputVector[i - 1] = inputVector[i];
			inputVector[i] = tmp;
		}
	}
}

void	PmergeMe::sortPairsByMainChainHighestValue(std::vector<Pair>& _vector)
{
	(void)_vector;

}

void	PmergeMe::insertPendantValuesThroughBinarySearch(std::vector<Pair>& _vector)
{
	(void)_vector;

}

void	PmergeMe::insertStraggler(std::vector<Pair>& _vector)
{
	(void)_vector;
}

void	PmergeMe::displayResults(std::vector<Pair>& _vector) const
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

void	PmergeMe::createFirstSortedPairing(std::deque<Pair>& _deque)
{
	(void)_deque;

}

void	PmergeMe::sortPairsByMainChainHighestValue(std::deque<Pair>& _deque)
{
	(void)_deque;

}

void	PmergeMe::insertPendantValuesThroughBinarySearch(std::deque<Pair>& _deque)
{

	(void)_deque;
}

void	PmergeMe::insertStraggler(std::deque<Pair>& _deque)
{
	(void)_deque;
}

void	PmergeMe::displayResults(std::deque<Pair>& _deque) const
{
	(void)_deque;

}
