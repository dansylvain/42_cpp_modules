/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:49:30 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/04 07:38:00 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <limits>
#include <iomanip>
#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <string>
#include "main.hpp"

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

		void	displayResults();

		void	displayPairVector(std::vector<Pair>& input);
		void	displayIntVector(std::vector<int>& input);
		void	displayJacobstahlVector(std::vector<int>& vector);

		clock_t	startTimer();
		template<typename Container>
		void	stopTimer(Container&, clock_t start);
		
		template<typename Container>
		void	displayListStateGraph(Container& _vector) const;
		
		void	fillOutputFile() const;

};

template <>
void PmergeMe::reserve_space(std::vector<int>& container, std::vector<int>::size_type size);

template<>
void	PmergeMe::stopTimer(std::vector<Pair>&, clock_t start);

template<>
void	PmergeMe::stopTimer(std::deque<Pair>&, clock_t start);

#include "PmergeMe.tpp"

