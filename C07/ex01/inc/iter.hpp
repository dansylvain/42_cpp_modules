#pragma once
#include <iostream>

template<typename T>
void iter(const T* array, unsigned int len, void (*func)(const T&))
{
	for (unsigned int i = 0; i < len; ++i)
		func(array[i]);
}

template<typename T>
void iter(T* array, unsigned int len, void (*func)(T&))
{
	for (unsigned int i = 0; i < len; ++i)
		func(array[i]);
}

template<typename T>
void print(T& var)
{
    std::cout << var << std::endl;
}

void	printInt(int& value);
void	printB(std::string str);
void	printChar(char& value);
void	printString(std::string& value);
void	pause();
