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
void PmergeMe::getInputVector(std::vector<int>& input)
{
	_vector.clear();
	_isOdd = false;

	for (unsigned long i = 0; i < input.size(); i += 2)
	{
		Pair pair;
		pair.main = input[i];

		if (i + 1 < input.size())
		{
			pair.pendant = input[i + 1];
			_vector.push_back(pair);
		}
		else
		{
			_isOdd = true;
			_straggler = input[i];
		}
	}
	std::cout << "value of i: " << input.size() << ", straggler: " << _straggler << std::endl;
}


void PmergeMe::createFirstSortedPairing(std::vector<Pair>& _vector)
{
	int tmp = 0;

	for (unsigned long i = 1; i < _vector.size(); i += 2)
	{
		if (_vector[i].main > _vector[i].pendant)
		{
			std::cout << "before: " << _vector[i].main << ", " << _vector[i].pendant << std::endl;
			tmp = _vector[i].main;
			_vector[i].main = _vector[i].pendant;
			_vector[i].pendant = tmp;
			std::cout << "after: " << _vector[i].main << ", " << _vector[i].pendant << std::endl;
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


/**========================================================================
 *                           DISPLAY
 *========================================================================**/

void	PmergeMe::displayVector(int intCount, std::vector<Pair>& input)
{
	for (int i = 0; i < intCount / 2; i++)
	{
		std::cout << input[i].main << ", " << input[i].pendant << std::flush;
		if (i != intCount - 1 && _isOdd == false)
			std::cout << ", " << std::flush;
		else if (i != intCount - 1 && _isOdd)
			std::cout << ", " << _straggler << std::flush;
		else
			std::cout << std::endl;
	}
}