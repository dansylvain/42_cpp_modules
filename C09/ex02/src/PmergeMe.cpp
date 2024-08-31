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
void	PmergeMe::validateInput(std::vector<int>& input) const
{
	(void)input;
}

void	PmergeMe::createJacobstahlSequence(const int& intCount)
{
	(void)intCount;
}

/**========================================================================
 *                           VECTOR
 *========================================================================**/
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
