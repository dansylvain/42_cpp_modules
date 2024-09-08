/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:51:20 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/08 12:45:17 by dsylvain         ###   ########.fr       */
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
	PmergeMe._finalVector.clear();
	PmergeMe.vectorSort(input, PmergeMe._deque);
	PmergeMe.displayResults();

	return(0);
}