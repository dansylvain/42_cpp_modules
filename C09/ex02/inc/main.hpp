/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:49:42 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/03 09:52:59 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>
#include <sstream>

void	print(std::string str);
void	printB(std::string str);
void	pause();
int		stringToInt(const std::string& str);
bool	isPositivInteger(const std::string& str);
bool	convertInput(int argc, char** argv, std::vector<int>* input);
void	displayInputTab(int inputIntCount, std::vector<int>& input);
