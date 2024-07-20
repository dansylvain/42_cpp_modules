/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansylvain <dansylvain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:57:01 by dansylvain        #+#    #+#             */
/*   Updated: 2024/07/20 10:57:02 by dansylvain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int main( int argc, char **argv )
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	if(Utils::ArgNumberWrong(argc))
		return (1);
	if (Utils::openStreams(inputFile, outputFile, argv))
		return (2);
	Utils::createNewFile(inputFile, outputFile, argv);
	Utils::closeStreams(inputFile, outputFile);
	return (0);
}