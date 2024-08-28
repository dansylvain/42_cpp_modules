#pragma once
#include <stdexcept>
#include <cstdlib>

/**========================================================================
 *                           ARRAY
 *? use try/catch whenever you use [] operator 
 *========================================================================**/
template <typename T>
class Array
{
private:
	T*				data;
	unsigned int	_size;

	void copyFrom(const Array& other);
	void free();

public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T&			operator[](unsigned int index);
	const T&	operator[](unsigned int index) const;

	unsigned int size() const;
};

#include "Array.tpp"
