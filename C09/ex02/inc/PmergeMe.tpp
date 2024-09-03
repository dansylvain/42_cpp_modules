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