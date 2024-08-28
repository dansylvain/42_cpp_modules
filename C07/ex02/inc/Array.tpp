#pragma once
#include "Array.hpp"

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
template <typename T>
Array<T>::Array() : data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (_size == 0)
		data = NULL;
	else
	{
		data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			data[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	if (_size == 0)
		data = NULL;
	else
	{
		data = new T[_size];
		copyFrom(other);
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		free();
		_size = other._size;
		if (_size == 0)
			data = NULL;
		else
		{
			data = new T[_size];
			copyFrom(other);
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	free();
}

/**========================================================================
 *                           OPERATOR OVERLOADING
 *========================================================================**/
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

/**========================================================================
 *                           UTILS FUNCS
 *========================================================================**/
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
void Array<T>::copyFrom(const Array& other)
{
	for (unsigned int i = 0; i < _size; ++i)
		data[i] = other.data[i];
}

template <typename T>
void Array<T>::free()
{
	delete[] data;
	data = NULL;
}
