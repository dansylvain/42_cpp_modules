#pragma once
#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <string>

class PmergeMe
{
	private:
	public:


		typedef struct pair
		{
			int main;
			int pendant;
		} Pair;

		std::vector<pair>	_vector;
		std::vector<int>	_finalVector;
		std::vector<int>	_initialVector;
		std::deque<Pair>	_deque;
		std::vector<int> 	_jacobstahlSequence;
		bool				_isOdd;
		double				_straggler;
		int					_intCount;
		int					_pairCount;
		int					_comparisonCount;
		int					_currentFinalVectorSize;
		double				_timeSpentVector;
		double				_timeSpentDeque;

		//coplien
		PmergeMe();
		PmergeMe(const PmergeMe&);
		const PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		// common funcs
		void	generateJacobstahlSequence();
	
		// vector

		template<typename InputContainer, typename Container>
		void	vectorSort(InputContainer& _initialVector, Container&);

		template <typename Container>
		void reserve_space(Container& container, typename Container::size_type size);




		template<typename InputContainer, typename Container>
		void	getInputVector(InputContainer& input, Container& _vector);

		template<typename Container>
		void	createFirstSortedPairing(Container& _vector);

		template<typename Container>
		void	sortPairsByMainChainHighestValue(Container&);

		template<typename Container>
		void	merge(Container& leftVector, Container& rightVector,
				Container& _vector);

		template<typename Container>
		void	createFinalVector(Container&);

		template<typename Container>
		void	insertPendantValuesThroughBinarySearch(Container& _vector);
		
		template<typename Container>
		void	insertValueThroughBinarySearch(Container&, int val);

		template<typename Container>
		void	displayResults(Container& _vector);

		// deque
		// void	getInputDeque(std::vector<int>& input);
		// void	createFirstSortedPairing(std::deque<Pair>& _deque);
		// void	sortPairsByMainChainHighestValue(std::deque<Pair>& _deque);
		// void	insertPendantValuesThroughBinarySearch(std::deque<Pair>& _deque);
		// void	insertStraggler(std::deque<Pair>& _deque);
		// void	displayResults(std::deque<Pair>& _deque);


		void	displayPairVector(std::vector<Pair>& input);
		void	displayIntVector(std::vector<int>& input);
		void	displayJacobstahlVector(std::vector<int>& vector);

		clock_t	startTimer();
		double	stopTimer(clock_t start);
};

		template <>
	    void PmergeMe::reserve_space(std::vector<int>& container, std::vector<int>::size_type size);
#include "PmergeMe.tpp"

