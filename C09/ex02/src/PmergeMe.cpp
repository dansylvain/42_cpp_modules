/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:49:06 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/03 10:13:06 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

clock_t PmergeMe::startTimer()
{
	return clock();
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

