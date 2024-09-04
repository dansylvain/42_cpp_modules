/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:49:06 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/04 07:10:33 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <fstream>

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
PmergeMe::PmergeMe() : 	_isOdd(false),
						_straggler(std::numeric_limits<double>::max()),
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

clock_t PmergeMe::startTimer()
{
	return clock();
}


/**========================================================================
 *                           DISPLAY
 *========================================================================**/
void PmergeMe::fillOutputFile() const
{
	std::string filename = "completeOutput";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file for writing");

	file << "***********************\n	Unsorted list:\n\
***********************\n";
	for (int i = 0; i < _intCount; i++)
	{
		std::ostringstream oss;
		oss << _initialVector[i];
		file << oss.str() + " ";
	}
	file << "\n***********************\n	Sorted list:\n\
***********************\n";
	for (int i = 0; i < _intCount; i++)
	{
		std::ostringstream oss;
		oss << _finalVector[i];
		file << oss.str() + " ";
	}
	file.close();
}

void	PmergeMe::displayResults()
{
	std::cout << "Before: " << std::flush;
	displayIntVector(_initialVector);
	std::cout << "After:  " << std::flush;
	displayIntVector(_finalVector);
	
	std::cout << "\nTime to process a range of " << _intCount 
	<< " elements with std::vector : "
	<< _timeSpentVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _intCount 
	<< " elements with std::deque  : "
	<< _timeSpentDeque << " us" << std::endl;
	std::cout << "\nComparison total: " << _comparisonCount << std::endl;
	if (_intCount > 10)
		std::cout 
		<< "\n********** COMPLETE OUTPUT IN FILE\
 \"completeOutput\" **********\n";
	std::cout <<
	"\nTry this for random values:\n	\
	./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\\n' ' ')"
	<< std::endl;
	fillOutputFile();
}

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
		std::cout << vector[i].main << ", " 
		<< vector[i].pendant << std::flush;
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

