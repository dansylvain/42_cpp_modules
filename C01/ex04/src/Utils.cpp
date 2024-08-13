/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:57:09 by dansylvain        #+#    #+#             */
/*   Updated: 2024/08/13 10:33:56 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

/**========================================================================
 *                           VAR INITIALIZATION
 *========================================================================**/
std::string Utils::errMssg = "Usage: ./sed <file> <string1> <string2>";
std::string Utils::errMssg2 = "could not create output file";

/**========================================================================
 *                           ARGNUMBERWRONG
 *========================================================================**/
int	Utils::ArgNumberWrong(int argc)
{
	if (argc != 4)
		return (std::cout << Utils::errMssg << std::endl, 1);
	return (0);
}

/**========================================================================
 *                           openStreamsFails
 *========================================================================**/
int	Utils::openStreamsFails(std::ifstream& inputFile, std::ofstream& outputFile,
	char *argv[])
{
	std::string srcFile;
	std::string destFile;

	srcFile = argv[1];
	destFile = srcFile + ".replace";
	inputFile.open(srcFile.c_str());
	if (!inputFile)
		return (std::cout << "File error" << std::endl, 2);
	outputFile.open(destFile.c_str());
	if (!outputFile)
		return (std::cout << Utils::errMssg2 << std::endl, 3);
	return (0);
}

/**========================================================================
 *                           CREATENEWFILE
 *========================================================================**/
void	Utils::createNewFile(std::ifstream& inputFile,
		std::ofstream& outputFile, char *argv[])
{
	std::string newline;
	std::string line;
	while (std::getline(inputFile, line))
	{
		newline = Utils::replaceAllOccurrences(line, argv);
		outputFile << newline << std::endl;
	}
}

/**========================================================================
 *                           REPLACEALLOCCURRENCES
 *========================================================================**/
std::string		Utils::replaceAllOccurrences(const std::string& str,
				char *argv[])
{
	std::string s1;
	std::string s2;
	std::string result;
	size_t pos;
	size_t prev_pos;

	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty())
		return str;
	pos = 0;
	prev_pos = 0;
	while ((pos = str.find(s1, prev_pos)) != std::string::npos)
	{
		result.append(str.substr(prev_pos, pos - prev_pos));
		result.append(s2);
		prev_pos = pos + s1.length();
	}
	result.append(str.substr(prev_pos));
	return (result);
}

/**========================================================================
 *                           CLOSESTREAMS
 *========================================================================**/
void	Utils::closeStreams(std::ifstream& inputFile,
		std::ofstream& outputFile)
{
	inputFile.close();
	outputFile.close();
}