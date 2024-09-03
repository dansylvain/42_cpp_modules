/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:48:52 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/03 09:52:15 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	print(std::string str)
{
	std::cout << str << std::endl;
}

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

void	pause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}

int stringToInt(const std::string& str)
{
	int nbr;

	std::stringstream ss(str);
	ss >> nbr;
	return (nbr);
}

bool isPositivInteger(const std::string& str)
{
	std::istringstream iss(str);
	int number;
	char c;
	if (!(iss >> number) || (iss >> c))
		return false;
	if (number < 0)
		return false;
	return true;
}

bool convertInput(int argc, char** argv, std::vector<int>* input)
{
	
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		while (iss >> token)
		{
			if (!isPositivInteger(token))
				return false;
			std::istringstream tokenStream(token);
			int number;
			tokenStream >> number;
			input->push_back(number);
		}
	}
	return true;
}



void	displayInputTab(int inputIntCount, std::vector<int>& input)
{
	for (int i = 0; i < inputIntCount; i++)
	{
		std::cout << input[i] << std::flush;
		if (i != inputIntCount - 1)
			std::cout << ", " << std::flush;
		else
			std::cout << std::endl;
	}
}