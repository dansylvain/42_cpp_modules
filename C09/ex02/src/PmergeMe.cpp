#include "PmergeMe.hpp"
#include "main.hpp"
#include <limits>
#include <iomanip>

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
PmergeMe::PmergeMe() : 	_isOdd(false), _straggler(std::numeric_limits<double>::max()),
						_intCount(0), _pairCount(0), _comparisonCount(0),
						_currentFinalVectorSize(0)
{
}

PmergeMe::~PmergeMe()
{
}

/**========================================================================
 *                           COMMON FUNCTIONS
 *========================================================================**/
void	PmergeMe::generateJacobstahlSequence()
{
	_jacobstahlSequence.clear();
	int j0 = 0;
	int j1 = 1;
	
	if (_pairCount < 1)
		return;
	while (true)
	{
		int nextJacobstahl = j1 + 2 * j0;
		if (nextJacobstahl > _pairCount)
			break;
		_jacobstahlSequence.push_back(nextJacobstahl);
		j0 = j1;
		j1 = nextJacobstahl;
	}
}

/**========================================================================
 *                           VECTOR
 * reserve method used to pre allocate memory size for vector
 *========================================================================**/
void	PmergeMe::vectorSort(std::vector<int> input)
{
	clock_t timer = startTimer();
	getInputVector(input);
	generateJacobstahlSequence();
	createFirstSortedPairing(_vector);
	sortPairsByMainChainHighestValue(_vector);
	createFinalVector();
	insertPendantValuesThroughBinarySearch(_vector);
	if (_isOdd)
		insertValueThroughBinarySearch(_straggler);
	_timeSpent = stopTimer(timer);
}

void PmergeMe::getInputVector(std::vector<int>& input)
{
	_initialVector = input;
	_intCount = input.size();
	_vector.clear();
	_vector.reserve(_intCount); //? specific to vector
	_isOdd = false;

	for (unsigned long i = 0; i < input.size(); i++)
	{
		Pair pair;
		pair.main = input[i];

		if (i + 1 < input.size())
		{
			pair.pendant = input[i + 1];
			_vector.push_back(pair);
			_pairCount++;
			i++;
		}
		else
		{
			_isOdd = true;
			_straggler = input[i];
		}
	}
}


void PmergeMe::createFirstSortedPairing(std::vector<Pair>& _vector)
{
	int tmp = 0;

	for (unsigned long i = 0; i < _vector.size(); i++)
	{
		if (_vector[i].main > _vector[i].pendant)
		{
			tmp = _vector[i].main;
			_vector[i].main = _vector[i].pendant;
			_vector[i].pendant = tmp;
			_comparisonCount++;
		}
	}
}

/**========================================================================
 *                         SORTPAIRSBYMAINCHAINHIGHESTVALUE
 * this function is a merge sort algorithm. uses helper function merge (see below)
 *========================================================================**/
void	PmergeMe::sortPairsByMainChainHighestValue(std::vector<Pair>& _vector)
{
	int len = _vector.size();
	if (len <= 1) return;

	int middle = len / 2;
	std::vector<Pair> leftVector(_vector.begin(), _vector.begin() + middle);
	std::vector<Pair> rightVector(_vector.begin() + middle, _vector.end());

	sortPairsByMainChainHighestValue(leftVector);
	sortPairsByMainChainHighestValue(rightVector);
	merge(leftVector, rightVector, _vector);
}

void	PmergeMe::merge(std::vector<Pair>& leftVector, std::vector<Pair>& rightVector,
		std::vector<Pair>& _vector)
{
	int leftSize = leftVector.size();
	int rightSize = rightVector.size();
	int i = 0, l = 0, r = 0;

	while(l < leftSize && r < rightSize)
	{
		if(leftVector[l].main < rightVector[r].main)
			_vector[i++] = leftVector[l++];
		else
			_vector[i++] = rightVector[r++];
		_comparisonCount++;
	}
	while (l < leftSize)
		_vector[i++] = leftVector[l++];
	while (r < rightSize)
		_vector[i++] = rightVector[r++];
}

void	PmergeMe::createFinalVector()
{
	_finalVector.reserve(_intCount);
	for (int i = 0; i < _pairCount; i++)
	{
		_finalVector.push_back(_vector[i].main);
		_currentFinalVectorSize++;
	}
}

void	PmergeMe::insertPendantValuesThroughBinarySearch(std::vector<Pair>& _vector)
{
	long unsigned int i = 0;
	if (_pairCount < 1)
		return;
	for (; i < _jacobstahlSequence.size(); i++)
	{
		unsigned long int index = _jacobstahlSequence[i] - 1;
		if (index >= _vector.size())
			break;
		int val = _vector[index].pendant;
		insertValueThroughBinarySearch(val);
	}
	_pairCount -= i;
	for (;i > 0; i--)
	{
		unsigned long int index = _jacobstahlSequence[i - 1];
		_vector.erase(_vector.begin() + index - 1);
	}
	generateJacobstahlSequence();
	insertPendantValuesThroughBinarySearch(_vector);
}

void PmergeMe::insertValueThroughBinarySearch(int val)
{
	int low = 0;
	int high = _currentFinalVectorSize - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (_finalVector[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
		_comparisonCount++;
	}
	_finalVector.insert(_finalVector.begin() + low, val);
	_currentFinalVectorSize++;
}

void	PmergeMe::displayResults(std::vector<Pair>& _vector)
{
/* 		$> ./PmergeMe 3 5 9 7 4

	Time to process a range of 5 elements with std::[..] : 0.00031 us
	Time to process a range of 5 elements with std::[..] : 0.00014 us */
	std::cout << "Before: " << std::flush;
	displayIntVector(_initialVector);
	std::cout << "After:  " << std::flush;
	displayIntVector(_finalVector);
	
	std::cout << "Time to process a range of " << _intCount << " elements with std::vector : "
	<< std::fixed << std::setprecision(5) << _timeSpent << " us" << std::endl;
	std::cout << "Time to process a range of " << _intCount << " elements with std::deque  : "
	<< std::fixed << std::setprecision(5) << _timeSpent << " us" << std::endl;
	std::cout << "Comparison total: " << _comparisonCount << std::endl;
	std::cout <<
	"\nTry this for random values:\n	./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\\n' ' ')"
	<< std::endl;
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

void	PmergeMe::displayResults(std::deque<Pair>& _deque)
{
	(void)_deque;

}


/**========================================================================
 *                           DISPLAY
 *========================================================================**/

void	PmergeMe::displayJacobstahlVector(std::vector<int>& vector)
{
	int intCount = vector.size();
	
	for (int i = 0; i < intCount; i++)
	{
		std::cout << vector[i] << std::flush;
		if (i != intCount - 1)	
			std::cout << " | " << std::flush;
	}
	print("");
}

void	PmergeMe::displayPairVector(std::vector<Pair>& vector)
{
	for (int i = 0; i < _pairCount; i++)
	{
		std::cout << vector[i].main << ", " << vector[i].pendant << std::flush;
		if (i != _pairCount - 1)
			std::cout << " | " << std::flush;
		else if (_isOdd)
			std::cout << " | 🪁" << _straggler << "🪁 " << std::endl;
	}
	print("");
}

void	PmergeMe::displayIntVector(std::vector<int>& vector)
{
	int intCount = vector.size();
	
	if (intCount > 10)
	{
		for (int i = 0; i < 4; i++)
		{
			std::cout << vector[i] << std::flush;
			if (i != intCount - 1)
				std::cout << " " << std::flush;
		}
		std::cout << " [...]" << std::flush;
		
	}
	else
	{
		for (int i = 0; i < intCount; i++)
		{
			std::cout << vector[i] << std::flush;
			if (i != intCount - 1)
				std::cout << " " << std::flush;
		}
	}
	print("");
}

clock_t PmergeMe::startTimer()
{
	return clock();
}

double PmergeMe::stopTimer(clock_t start)
{
	clock_t end = clock();
	return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

}