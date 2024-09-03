/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:51:20 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/03 09:52:08 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
	PmergeMe PmergeMe;
	std::vector<int> input;	

	if(!convertInput(argc, argv, &input))
		return (print("Error: invalid input"), 1);
	PmergeMe.vectorSort(input, PmergeMe._vector);	
	PmergeMe.displayResults(PmergeMe._vector);

	PmergeMe.vectorSort(input, PmergeMe._deque);
	PmergeMe.displayResults(PmergeMe._deque);

	// //! DEQUE FUNCS
	// PmergeMe.createFirstSortedPairing(PmergeMe._deque);
	// PmergeMe.sortPairsByMainChainHighestValue(PmergeMe._deque);
	// PmergeMe.insertPendantValuesThroughBinarySearch(PmergeMe._deque);
	// PmergeMe.insertStraggler(PmergeMe._deque);
	// PmergeMe.displayResults(PmergeMe._deque);
	
	print("");
	return(0);
}