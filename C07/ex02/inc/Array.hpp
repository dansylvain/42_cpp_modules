// Array.hpp
#pragma once
#include <stdexcept>

template <typename T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size() const;

private:
	T* data;
	unsigned int _size;

	void copyFrom(const Array& other);
	void free();
};

#include "Array.tpp"
