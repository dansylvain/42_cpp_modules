#include "PmergeMe.hpp"

template<typename InputContainer, typename Container>
void	PmergeMe::vectorSort(InputContainer& input, Container& _vector)
{
	clock_t timer = startTimer();
	getInputVector(input, _vector);
	generateJacobstahlSequence();
	createFirstSortedPairing(_vector);
	sortPairsByMainChainHighestValue(_vector);
	createFinalVector(_vector);
	insertPendantValuesThroughBinarySearch(_vector);
	if (_isOdd)
		insertValueThroughBinarySearch(_vector, _straggler);
	_timeSpentVector = stopTimer(timer);
}

template <typename Container>
void PmergeMe::reserve_space(Container&, typename Container::size_type) {
    // Fonction template générique (peut être vide ou avoir une logique par défaut)
}

// Spécialisation pour std::vector
template <>
inline void PmergeMe::reserve_space(std::vector<int>& container, std::vector<int>::size_type size)
{
    container.reserve(size);
}

template <typename InputContainer, typename Container>
void PmergeMe::getInputVector(InputContainer& input, Container& _vector)
{
	_initialVector = input;
	_intCount = input.size();
	_vector.clear();
	reserve_space(_vector, _intCount); //? specific to vector
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

template<typename Container>
void	PmergeMe::createFirstSortedPairing(Container& _vector)
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

template<typename Container>
void	PmergeMe::sortPairsByMainChainHighestValue(Container& _vector)
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

template<typename Container>
void	PmergeMe::merge(Container& leftVector, Container& rightVector,
		Container& _vector)
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

template<typename Container>
void	PmergeMe::insertPendantValuesThroughBinarySearch(Container& _vector)
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
		insertValueThroughBinarySearch(_vector, val);
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

template<typename Container>
void PmergeMe::insertValueThroughBinarySearch(Container&, int val)
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


template<typename Container>
void	PmergeMe::createFinalVector(Container& _vector)
{
	reserve_space(_finalVector, _intCount);
	for (int i = 0; i < _pairCount; i++)
	{
		_finalVector.push_back(_vector[i].main);
		_currentFinalVectorSize++;
	}
}


template<typename Container>
void	PmergeMe::displayResults(Container& _vector)
{
/* 		$> ./PmergeMe 3 5 9 7 4

	Time to process a range of 5 elements with std::[..] : 0.00031 us
	Time to process a range of 5 elements with std::[..] : 0.00014 us */
	std::cout << "Before: " << std::flush;
	displayIntVector(_initialVector);
	std::cout << "After:  " << std::flush;
	displayIntVector(_finalVector);
	
	std::cout << "Time to process a range of " << _intCount << " elements with std::vector : "
	<< _timeSpentVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _intCount << " elements with std::deque  : "
	<< _timeSpentVector << " us" << std::endl;
	std::cout << "Comparison total: " << _comparisonCount << std::endl;
	std::cout <<
	"\nTry this for random values:\n	./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\\n' ' ')"
	<< std::endl;
	(void)_vector;
}