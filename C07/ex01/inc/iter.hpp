#pragma once
#include <iostream>

template<typename T>
void iter(T* array, unsigned int len, void (*func)(T&))
{
	for (unsigned int i = 0; i < len; ++i)
	{
		func(array[i]);
	}
}
