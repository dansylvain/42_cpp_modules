/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:49:51 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/06 07:19:22 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename InputContainer, typename Container>
void	PmergeMe::vectorSort(InputContainer& input, Container& container)
{
	clock_t timer = startTimer();
	getInputVector(input, container);
	generateJacobstahlSequence();
	createFirstSortedPairing(container);
	sortPairsByMainChainHighestValue(container);
	createFinalVector(container);
	insertPendantValuesThroughBinarySearch(container);
	if (_isOdd)
		insertValueThroughBinarySearch(container, _straggler);
	stopTimer(container, timer);
}

template <typename Container>
void PmergeMe::reserve_space(Container&, typename Container::size_type)
{
	// Nothing. Void. NADA-ZERO.
}

template <>
inline void PmergeMe::reserve_space(std::vector<int>& container, std::vector<int>::size_type size)
{
    container.reserve(size);
}

template <typename InputContainer, typename Container>
void PmergeMe::getInputVector(InputContainer& input, Container& container)
{
	_initialVector = input;
	_intCount = input.size();
	container.clear();
	reserve_space(container, _intCount); //? specific to vector
	_isOdd = false;

	for (unsigned long i = 0; i < input.size(); i++)
	{
		Pair pair;
		pair.main = input[i];

		if (i + 1 < input.size())
		{
			pair.pendant = input[i + 1];
			container.push_back(pair);
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
void	PmergeMe::createFirstSortedPairing(Container& container)
{
	int tmp = 0;

	for (unsigned long i = 0; i < container.size(); i++)
	{
		if (container[i].main > container[i].pendant)
		{
			tmp = container[i].main;
			container[i].main = container[i].pendant;
			container[i].pendant = tmp;
			_comparisonCount++;
		}
	}
}

template<typename Container>
void	PmergeMe::sortPairsByMainChainHighestValue(Container& container)
{
	int len = container.size();
	if (len <= 1) return;

	int middle = len / 2;
	Container leftVector(container.begin(), container.begin() + middle);
	Container rightVector(container.begin() + middle, container.end());

	sortPairsByMainChainHighestValue(leftVector);
	sortPairsByMainChainHighestValue(rightVector);
	merge(leftVector, rightVector, container);
}

template<typename Container>
void	PmergeMe::merge(Container& leftVector, Container& rightVector,
		Container& container)
{
	int leftSize = leftVector.size();
	int rightSize = rightVector.size();
	int i = 0, l = 0, r = 0;

	while(l < leftSize && r < rightSize)
	{
		if(leftVector[l].main < rightVector[r].main)
			container[i++] = leftVector[l++];
		else
			container[i++] = rightVector[r++];
		_comparisonCount++;
	}
	while (l < leftSize)
		container[i++] = leftVector[l++];
	while (r < rightSize)
		container[i++] = rightVector[r++];
}

template<typename Container>
void	PmergeMe::insertPendantValuesThroughBinarySearch(Container& container)
{
	long unsigned int i = 0;
	if (_pairCount < 1)
		return;
	_currentFinalVectorSize = 0;
	for (; i < _jacobstahlSequence.size(); i++)
	{
		unsigned long int index = _jacobstahlSequence[i] - 1;
		if (index >= container.size())
			break;
		int val = container[index].pendant;
		insertValueThroughBinarySearch(container, val);
	}
	_pairCount -= i;
	for (;i > 0; i--)
	{
		unsigned long int index = _jacobstahlSequence[i - 1];
		container.erase(container.begin() + index - 1);
	}
	generateJacobstahlSequence();
	insertPendantValuesThroughBinarySearch(container);
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
void	PmergeMe::createFinalVector(Container& container)
{
	reserve_space(_finalVector, _intCount);
	for (int i = 0; i < _pairCount; i++)
	{
		_finalVector.push_back(container[i].main);
		_currentFinalVectorSize++;
	}
}

template<typename Container>
void PmergeMe::stopTimer(Container&, clock_t start)
{
	(void)start;
	
}

template<>
inline void	PmergeMe::stopTimer(std::vector<Pair>&, clock_t start)
{
	clock_t end = clock();
	_timeSpentVector = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

template<>
inline void	PmergeMe::stopTimer(std::deque<Pair>&, clock_t start)
{
	clock_t end = clock();
	_timeSpentDeque = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}