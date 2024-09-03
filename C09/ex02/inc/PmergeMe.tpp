#include "PmergeMe.hpp"

template <typename InputContainer, typename Container>
void PmergeMe::getInputVector(InputContainer& input, Container& _vector)
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