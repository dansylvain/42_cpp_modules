#pragma once
#include "Array.hpp"

// Default constructor: Initializes an empty array with size 0.
template <typename T>
Array<T>::Array() : data(NULL), _size(0)
{
}

// Constructor: Initializes an array of size 'n' with default-constructed elements.
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (_size == 0)
		data = NULL;
	else
	{
		data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			data[i] = T(); // Initialize each element with the default value of T.
	}
}

// Copy constructor: Creates a deep copy of another array.
template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	if (_size == 0)
		data = NULL;
	else
	{
		data = new T[_size];
		copyFrom(other);  // Copy elements from the 'other' array.
	}
}

// Copy assignment operator: Assigns the contents of another array to this one.
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		free(); // Free existing memory.
		_size = other._size;
		if (_size == 0)
			data = NULL;
		else
		{
			data = new T[_size];
			copyFrom(other); // Copy elements from the 'other' array.
		}
	}
	return *this;
}

// Destructor: Frees the dynamically allocated memory.
template <typename T>
Array<T>::~Array()
{
	free();
}

// Subscript operator: Provides access to array elements. Throws an exception if the index is out of bounds.
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

// Const subscript operator: Provides read-only access to array elements. Throws an exception if the index is out of bounds.
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

// Returns the size of the array.
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

// Helper function: Copies elements from another array to this one.
template <typename T>
void Array<T>::copyFrom(const Array& other)
{
	for (unsigned int i = 0; i < _size; ++i)
		data[i] = other.data[i];
}

// Helper function: Frees the dynamically allocated memory and sets the pointer to NULL.
template <typename T>
void Array<T>::free()
{
	delete[] data;
	data = NULL;
}
