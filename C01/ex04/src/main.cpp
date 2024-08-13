/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:57:01 by dansylvain        #+#    #+#             */
/*   Updated: 2024/08/13 13:51:29 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <string>
#include <cstdlib>

int main( int argc, char **argv )
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	if(Utils::ArgNumberWrong(argc))
		return (1);
	if (Utils::openStreamsFails(inputFile, outputFile, argv))
		return (2);
	Utils::createNewFile(inputFile, outputFile, argv);
	Utils::closeStreams(inputFile, outputFile);
	
	// display output
	std::cout << "Input file: " << std::endl;
	system((std::string("cat ") + argv[1]).c_str());	
	std::cout << std::endl;
	std::cout << "Output file: " << std::endl;
	system((std::string("cat ") + argv[1] + ".replace").c_str());	
	return (0);
}